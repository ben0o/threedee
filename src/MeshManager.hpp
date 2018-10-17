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


class MeshManager
{
public:
	MeshManager(Settings*);
	~MeshManager();
	
	void Update(double);
	void Draw(int);
	
	int LoadObj(std::string);

	std::vector<Mesh> mesh;
	std::map<std::string,int> meshMap;
	
	private:
	Settings* p_settings;
};

#endif
