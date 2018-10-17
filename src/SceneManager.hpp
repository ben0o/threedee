#ifndef SCENEMAN_H
#define SCENEMAN_H

#define GLM_ENABLE_EXPERIMENTAL

#include <vector>
#include "MeshManager.hpp"
#include "TextureManager.hpp"
#include "Structs.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

class SceneManager
{
public:
	SceneManager();
	SceneManager(MeshManager*,TextureManager*,Settings*);
	~SceneManager();
	
	void Draw(GLFWwindow*);
	void Update(double);
	void AddObject(Object);
	void InitialiseShaders();
private:

	
	Settings* p_settings;
	MeshManager* p_meshManager;
	TextureManager* p_textureManager;
	std::vector<Object>objects;
	
	
	GLuint vao;
	GLuint vbo;
	
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
};

#endif
