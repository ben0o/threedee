
#include "MeshManager.hpp"

MeshManager::MeshManager(Settings* _ptrSettings)
{
	p_settings = _ptrSettings;
}
MeshManager::~MeshManager()
{
}

Object MeshManager::LoadObj(std::string _filename)
{
	if (objectMap[_filename] != 0 )
		return object[objectMap[_filename]];
	
	std::vector<float>vertices;
	std::vector<float>uv;
	std::vector<float>normals;
	std::vector<std::string>mtl;

	std::vector<int>vertexIndices;
	std::vector<int>textureIndices;
	std::vector<int>normalIndices;
	
	std::vector<Material> materials;
	std::map<std::string,int> materialMap;
	
	std::string line;
	
	std::ifstream objfile (_filename);
	if (objfile.is_open())
	{
		while ( std::getline(objfile,line) )
		{
			float tempFloat;
			short tempShort;
			std::string tempString;
			
			std::string firstToken;
			std::stringstream ss(line);
			ss >> firstToken;
			
			if (firstToken == "mtllib")
			{
				ss >> tempString;
				CreateMaterials(tempString,materials,materialMap);
			}
			if (firstToken == "usemtl")
			{
				ss >> tempString;
				mtl.push_back(tempString);
				//Use an illegal index to force a material change
				vertexIndices.push_back(-1);
				textureIndices.push_back(-1);
				normalIndices.push_back(-1);
			}
			if (firstToken == "v")
				for (int i=0;i<3;i++)
				{
					ss >> tempFloat;
					vertices.push_back(tempFloat);
				}

			if (firstToken == "vn")
				for (int i=0;i<3;i++)
				{
					ss >> tempFloat;
					normals.push_back(tempFloat);
				}

			if (firstToken == "vt")
				for (int i=0;i<2;i++)
				{
					ss >> tempFloat;
					uv.push_back(tempFloat);
				}

			if (firstToken == "f")
				while(ss.rdbuf()->in_avail() != 0)
				{
					ss >> tempString;
					size_t pos = 0;
					int count = 0;
					std::string token;
					std::string delimiter = "/";
					
					while ((pos = tempString.find(delimiter)) != std::string::npos) 
					{
						token = tempString.substr(0, pos);
						std::istringstream(token) >> tempShort;

						if (count == 0)
							vertexIndices.push_back(tempShort);
						if (count == 1)
							textureIndices.push_back(tempShort);

						count++;
						tempString.erase(0, pos + delimiter.length());
					}
					std::istringstream(tempString) >> tempShort;
					normalIndices.push_back(tempShort);
				}
		}
    }
    objfile.close();
    
    //Objects are made up of a collective of meshes
	Object tempObject;
	int mtlCount = 0;
    for (std::vector<int>::size_type i = 0;i<vertexIndices.size();i++)
    {
		//detect illegal index use to signify a change in materials
		if (vertexIndices[i] < 0)
		{
			Mesh tempMesh; 										//This goes out of scope as soon as it's added. Quite useful
			tempObject.meshCollection.push_back(tempMesh);
			
			std::string tex;
			tex = materials[materialMap[mtl[mtlCount]]].map_Kd;

			// Load textures
			GLuint textures[3];
			glGenTextures(3, textures);

			int width, height;
			unsigned char* image;

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textures[0]);
			image = SOIL_load_image(tex.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
			SOIL_free_image_data(image);
			
			tempObject.meshCollection[tempObject.meshCollection.size()-1].map_Kd = textures[0];
			tempObject.meshCollection[tempObject.meshCollection.size()-1].map_Ks = textures[0];
			
			
			glActiveTexture(GL_TEXTURE2);
			tex = materials[materialMap[mtl[mtlCount]]].map_bump;
			
			glBindTexture(GL_TEXTURE_2D, textures[2]);
			image = SOIL_load_image(tex.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
			SOIL_free_image_data(image);
			
			tempObject.meshCollection[tempObject.meshCollection.size()-1].map_bump = textures[2];
			
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D,0);
			mtlCount++;
		}
		else
		{
			for (int j=0;j<3;j++)
				tempObject.meshCollection[tempObject.meshCollection.size()-1].vertices.push_back(vertices[((vertexIndices[i]-1)*3)+j]);

			for (int j=0;j<2;j++)
				tempObject.meshCollection[tempObject.meshCollection.size()-1].uv.push_back(uv[((textureIndices[i]-1)*2)+j]);

			for (int j=0;j<3;j++)
				tempObject.meshCollection[tempObject.meshCollection.size()-1].normals.push_back(normals[((normalIndices[i]-1)*3)+j]);
		}
	}
	
	for (std::vector<Mesh>::size_type i = 0;i<tempObject.meshCollection.size();i++)
    { 
		tempObject.meshCollection[i].vertexCount = vertexIndices.size();
		tempObject.meshCollection[i].InitialiseVAO();
	}
	std::cout<<"Object loaded" << std::endl;
	return tempObject;
}
bool MeshManager::CreateMaterials(std::string _filename, std::vector<Material> &_materials, std::map<std::string,int> &_materialMap)
{
	int numMaterials = 0;
	std::string line;
	//float tempFloat;
	std::string tempString;

	Material tempMaterial;
	
	std::ifstream objfile (_filename);
	if (objfile.is_open())
	{
		while ( std::getline(objfile,line) )
		{
			std::string firstToken;
			std::stringstream ss(line);
			ss >> firstToken;
			
			if (firstToken == "newmtl")
			{
				_materials.push_back(tempMaterial);
				ss >> tempString;
				_materialMap[tempString] = _materials.size()-1;
				_materials[_materials.size()-1].name = tempString;
				numMaterials++;
			}
			if (firstToken == "map_Kd")
			{
				ss >> tempString;
				_materials[_materials.size()-1].map_Kd = tempString;
			}
			if (firstToken == "map_Ks")
			{
				ss >> tempString;
				_materials[_materials.size()-1].map_Ks = tempString;
			}
			if (firstToken == "map_bump" || firstToken == "bump")
			{
				ss >> tempString;
				_materials[_materials.size()-1].map_bump = tempString;
			}
		}
		if (numMaterials != 0)
			_materials.push_back(tempMaterial);

		std::cout << "Processed " << numMaterials << " materials" << std::endl;
	}
	objfile.close();
	return true;
}

