#include "controller.hpp"

Controller::Controller()
{
}
Controller::Controller(Console* _ptr)
{
	p_console = _ptr;
	bActive = false;
}
Controller::~Controller()
{
}
void Controller::SetForegroundStatus()
{
	bActive = true;
}
bool Controller::GetForegroundStatus()
{
	return bActive;
}
void Controller::Draw()							//virtual
{
}
void Controller::Update(double dt)				//virtual
{
}
void Controller::LoadScene(std::string strFileName)	//virtual
{
}
void Controller::LoadAssets()
{
}
