#ifndef MESH_H
#define MESH_H
#define GLEW_STATIC
#define GL_GLEXT_PROTOTYPES
#include <vector>
#include "GLFW/glfw3.h"
#include <iostream>
#include "shader.hpp"

class Mesh
{
public:
	Mesh();
	~Mesh();
	
	void InitialiseVAO();
	void Draw(Shader*);

	std::vector<float>vertices;
	std::vector<int>indices;
	std::vector<float>normals;
	std::vector<float>uv;
	
	GLuint vao;
	GLuint vertexId;
	GLuint normalId;
	GLuint uvId;
	int vertexCount;
	
	GLuint map_Kd;
	GLuint map_Ks;
	GLuint map_bump;
};
#endif
