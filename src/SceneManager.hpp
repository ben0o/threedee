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
#include "object.hpp"
#include "shader.hpp"
#include "camera.hpp"

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
	void MouseSetRotation(double,double);
private:

	Settings* p_settings;
	MeshManager* p_meshManager;
	TextureManager* p_textureManager;
	
	std::vector<Object>objectCollection;
	
	GLuint vao;
	GLuint vbo;
	
	Shader* shader;
	
	Camera* p_camera;
};

#endif
