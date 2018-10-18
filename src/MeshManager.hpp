#ifndef MESHMAN_H
#define MESHMAN_H


#include "Mesh.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Structs.hpp"
#include "object.hpp"
#include "SOIL/SOIL.h"

class MeshManager
{
public:
	MeshManager(Settings*);
	~MeshManager();
	
	Object LoadObj(std::string);

	std::vector<Object> object;
	std::map<std::string,int> objectMap;

	std::vector<Mesh> mesh;
	std::map<std::string,int> meshMap;
	
	std::vector<unsigned char*> texture;
	std::map<std::string,int> textureMap;
	
	private:
	bool CreateMaterials(std::string, std::vector<Material>&, std::map<std::string,int>&);
	
	Settings* p_settings;
};

#endif
