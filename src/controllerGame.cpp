
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
	Object tempObj;
	tempObj.z = -5.f;
	tempObj.ry = 0.f;
	tempObj.meshFilename = "cabin.obj";
	p_sceneManager->AddObject(tempObj);
	
	p_sceneManager->InitialiseShaders();
	bLoading = false;
	std::cout << "Load Complete " << settings.level << std::endl;
}

