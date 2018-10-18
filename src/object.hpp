#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "Mesh.hpp"
#include "shader.hpp"

class Object
{
public:
	Object();
	~Object();
	
	void Draw(Shader*);
	std::string name;
	std::string meshFilename;
	float x;
	float y;
	float z;
	float rx;
	float ry;
	float rz;
	
	std::vector<Mesh> meshCollection;
};


#endif
