
#include "controllerMenu.hpp"

ControllerMenu::ControllerMenu()
{
}
ControllerMenu::ControllerMenu(Console* _ptr)
{
	p_console = _ptr;
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
void ControllerMenu::LoadScene(std::string)
{
}
 
