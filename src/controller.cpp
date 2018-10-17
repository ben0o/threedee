#include "controller.hpp"

Controller::Controller()
{
}
Controller::Controller(Console* _ptrConsole, Settings* _ptrSettings,SceneManager* _ptrSceneMan)
{
	p_console = _ptrConsole;
	p_settings = _ptrSettings;
	bActive = false;
}
Controller::~Controller()
{
}
void Controller::SetForegroundStatus()
{
	bActive = true;
	p_settings->level = "one";
}
bool Controller::GetForegroundStatus()
{
	return bActive;
}

