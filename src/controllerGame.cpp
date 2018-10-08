
#include "controllerGame.hpp"
#include <iostream>
#include "GLFW/glfw3.h"

ControllerGame::ControllerGame()
{
}
ControllerGame::ControllerGame(Console* _ptrConsole, Settings* _ptrSettings,SceneManager* _ptrSceneMan)
{
	p_console = _ptrConsole;
	p_settings = _ptrSettings;
	p_sceneManager = _ptrSceneMan;
	
	//Copy engine settings to local settings
	settings = *p_settings;
	bActive = false;
}
ControllerGame::~ControllerGame()
{
}
void ControllerGame::Update(double _dt)
{
	p_sceneManager->Update(_dt);
}
void ControllerGame::Draw()
{
	p_sceneManager->Draw();
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
void ControllerGame::LoadLevel()
{
	std::cout << "Loading Level " << settings.level << std::endl;
	Object tempObj;
	tempObj.z = -5.f;
	tempObj.ry = -90.f;
	tempObj.meshFilename = "cabin.obj";
	p_sceneManager->AddObject(tempObj);
	
	tempObj.z = 45.f;
	tempObj.x = -2.f;
	tempObj.y = 0.5f;
	tempObj.ry = -45.f;
	tempObj.meshFilename = "cube.obj";
	p_sceneManager->AddObject(tempObj);
	
}
