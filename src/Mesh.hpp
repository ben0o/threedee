#ifndef MESH_H
#define MESH_H

#include <vector>
#include "GLFW/glfw3.h"

class Mesh
{
public:
	Mesh();
	~Mesh();
	
	void Draw();

	std::vector<float>vertices;
	std::vector<int>indices;
	std::vector<float>normals;
	std::vector<float>uv;
	
	GLuint vertexId;
	GLuint normalId;
	GLuint uvId;
	int vertexCount;
	int IndexCount;
};
#endif
