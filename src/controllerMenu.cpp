
#include "controllerMenu.hpp"

ControllerMenu::ControllerMenu()
{
}
ControllerMenu::ControllerMenu(Console* _ptrConsole, Settings* _ptrSettings,SceneManager* _ptrSceneMan)
{
	p_console = _ptrConsole;
	p_settings = _ptrSettings;
	p_sceneManager = _ptrSceneMan;
	bActive = false;
}
ControllerMenu::~ControllerMenu()
{
}
void ControllerMenu::Update(double)
{
	bActive = false;
}
void ControllerMenu::Draw()
{
}
 
