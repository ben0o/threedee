
#include "MeshManager.hpp"

MeshManager::MeshManager(Settings* _ptrSettings)
{
	p_settings = _ptrSettings;
}
MeshManager::~MeshManager()
{
}
void MeshManager::Update(double dt)
{
}
void MeshManager::Draw(int _meshID)
{
	mesh[_meshID].Draw();
}
int MeshManager::LoadObj(std::string _filename)
{
	if (meshMap[_filename] != 0 )
		return meshMap[_filename];
	
	Mesh tempMesh;
	std::vector<float>vertices;
	std::vector<float>uv;
	std::vector<float>normals;
	std::vector<int>vertexIndices;
	std::vector<int>textureIndices;
	std::vector<int>normalIndices;
	
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

    for (std::vector<int>::size_type i = 0;i<vertexIndices.size();i++)
		for (int j=0;j<3;j++)
			tempMesh.vertices.push_back(vertices[((vertexIndices[i]-1)*3)+j]);
	
    for (std::vector<int>::size_type i = 0;i<textureIndices.size();i++)
		for (int j=0;j<2;j++)
			tempMesh.uv.push_back(uv[((textureIndices[i]-1)*2)+j]);

    for (std::vector<int>::size_type i = 0;i<normalIndices.size();i++)
		for (int j=0;j<3;j++)
			tempMesh.normals.push_back(normals[((normalIndices[i]-1)*3)+j]);
	
	tempMesh.vertexCount = vertexIndices.size();
	tempMesh.InitialiseVAO();	
	mesh.push_back(tempMesh);

	meshMap[_filename] = mesh.size()-1;

	return meshMap[_filename];;
}
