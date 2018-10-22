
#include "SceneManager.hpp"
SceneManager::SceneManager()
{
}
SceneManager::SceneManager(MeshManager* _ptrMeshMan, TextureManager* _ptrTexMan, Settings* _ptrSettings)
{
	p_meshManager = _ptrMeshMan;
	p_textureManager = _ptrTexMan;
	p_settings = _ptrSettings;
	p_camera = new Camera();
	shader = new Shader();
}
SceneManager::~SceneManager()
{
}
void SceneManager::Draw(GLFWwindow* _window)
{
	shader->UseProgram();
	glEnable(GL_DEPTH_TEST);
	int width, height;
    glfwGetFramebufferSize(_window, &width, &height);
	assert(width > 0 && height > 0);
	const float ratio = width / float(height);
							
	const glm::mat4 projection = glm::perspective(45.0f, ratio, 0.1f, 200.0f);
	glm::mat4 modelView = glm::mat4(1.0f);
	
	//camera
	modelView = p_camera->Draw(_window,modelView);
	modelView = glm::translate(modelView, glm::vec3(0.0,-5.0,-50.0));
	//modelView = glm::rotate(modelView, -0.8f, glm::vec3(0.0, 1.0, 0.0));
	
	const glm::mat4 MVP        = projection * modelView;
	
	glViewport(0, 0, width, height);
	
	shader->SetMVP(MVP);
	
	for (std::vector<Object>::size_type i = 0;i<objectCollection.size();i++)
		objectCollection[i].Draw(shader);
}
void SceneManager::Update(double _dt)
{
	
}
void SceneManager::AddObject(Object _object)
{
	_object = p_meshManager->LoadObj(_object.meshFilename);
	objectCollection.push_back(_object);
}

void SceneManager::InitialiseShaders()
{
	shader->LoadShader();
}
void SceneManager::MouseSetRotation(double _x,double _y)
{
	p_camera->MouseSetRotation(_x,_y);
}
