
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
	
	glm::mat4 model 	 = glm::mat4(1.0f);	
	glm::mat4 view 		 = glm::mat4(1.0f);				
	glm::mat4 projection = glm::perspective(45.0f, ratio, 0.1f, 200.0f);
	
	//camera
	view = p_camera->Draw(_window,view);
	view = glm::translate(view, glm::vec3(0.0,-5.0,-10.0));
	
	shader->SetMatV(view);
	shader->SetMatP(projection);
	
	for (std::vector<Object>::size_type i = 0;i<objectCollection.size();i++)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, objectCollection[i].position);
		model = glm::rotate(model, (objectCollection[i].rotation.x * 3.142f) / 180.f, glm::vec3(1.0, 0.0, 0.0));
		model = glm::rotate(model, (objectCollection[i].rotation.y * 3.142f) / 180.f, glm::vec3(0.0, 1.0, 0.0));
		model = glm::rotate(model, (objectCollection[i].rotation.z * 3.142f) / 180.f, glm::vec3(0.0, 0.0, 1.0));
		
		shader->SetMatM(model);
		
		objectCollection[i].Draw(shader);
	}
}
void SceneManager::Update(double _dt)
{
	
}
void SceneManager::AddObject(Object _object)
{
	Object tempObject = p_meshManager->LoadObj(_object.meshFilename);
	tempObject.name = _object.name;
	tempObject.meshFilename = _object.meshFilename;
	tempObject.position = _object.position;
	tempObject.rotation = _object.rotation;
	objectCollection.push_back(tempObject);
}

void SceneManager::InitialiseShaders()
{
	shader->LoadShader();
}
void SceneManager::MouseSetRotation(double _x,double _y)
{
	p_camera->MouseSetRotation(_x,_y);
}
