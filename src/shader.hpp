#ifndef SHADER_H
#define SHADER_H

#define GL_GLEXT_PROTOTYPES
#define GLM_ENABLE_EXPERIMENTAL

#include "GLFW/glfw3.h"
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

class Shader
{
public:
	Shader();
	~Shader();
	void LoadShader();
	void UseProgram();
	
	void SetMVP(glm::mat4);
	void SetMatM(glm::mat4);
	void SetMatV(glm::mat4);
	void SetMatP(glm::mat4);
	
	GLint GetTextureID(std::string);

	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
};


#endif
