#include "controller.hpp"

Controller::Controller()
{
}
Controller::Controller(Console* _ptr)
{
	p_console = _ptr;
}
Controller::~Controller()
{
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
