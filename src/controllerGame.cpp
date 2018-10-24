
#include "controllerGame.hpp"
#include <iostream>


ControllerGame::ControllerGame()
{
}
ControllerGame::ControllerGame(Console* _ptrConsole, Settings* _ptrSettings,SceneManager* _ptrSceneMan)
{
	p_console = _ptrConsole;
	p_settings = _ptrSettings;
	p_sceneManager = _ptrSceneMan;
	bLoading = true;
	
	//Copy engine settings to local settings
	settings = *p_settings;
	bActive = false;
}
ControllerGame::~ControllerGame()
{
}
void ControllerGame::Update(double _dt)
{
	if (!bLoading)
		p_sceneManager->Update(_dt);
}
void ControllerGame::Draw(GLFWwindow* _window)
{
	if (!bLoading)
		p_sceneManager->Draw(_window);
}
void ControllerGame::CompareSettings()
{
	bool bChangeLevel = false;
	if (p_settings->level != settings.level)
		bChangeLevel = true;
	
	//Copy engine settings to local settings
	settings = *p_settings;
	
	if (bChangeLevel)
		LoadLevel();
}
void ControllerGame::MouseSetRotation(double _x,double _y)
{
	p_sceneManager->MouseSetRotation(_x,_y);
}
void ControllerGame::LoadLevel()
{
	//this needs to be threaded
	bLoading = true;
	std::cout << "Loading Level " << settings.level << std::endl;
	
	{
		glm::vec3 position = glm::vec3(0.0,0.0,0.0);
		glm::vec3 rotation = glm::vec3(0.0,0.0,0.0);
		
		Object tempObj(position,rotation);
		tempObj.meshFilename = "roughl.obj";
		p_sceneManager->AddObject(tempObj);
	}
	{
		glm::vec3 position = glm::vec3(0.0,5.0,0.0);
		glm::vec3 rotation = glm::vec3(0.0,0.0,0.0);
		
		Object tempObj(position,rotation);
		tempObj.meshFilename = "cube.obj";
		p_sceneManager->AddObject(tempObj);
	}
	{
		glm::vec3 position = glm::vec3(10.0,0.0,0.0);
		glm::vec3 rotation = glm::vec3(0.0,90.0,0.0);
		
		Object tempObj(position,rotation);
		tempObj.meshFilename = "lift_tri.obj";
		p_sceneManager->AddObject(tempObj);
	}
	{
		glm::vec3 position = glm::vec3(-10.0,0.0,0.0);
		glm::vec3 rotation = glm::vec3(0.0,45.0,0.0);
		
		Object tempObj(position,rotation);
		tempObj.meshFilename = "lift_tri.obj";
		p_sceneManager->AddObject(tempObj);
	}
	
	p_sceneManager->InitialiseShaders();
	bLoading = false;
	std::cout << "Load Complete " << settings.level << std::endl;
}

