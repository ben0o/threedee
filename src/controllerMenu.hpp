#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include <string.h>
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu();
	ControllerMenu(Console*);
	~ControllerMenu();

	virtual void Update(double);
	virtual void Draw();
	virtual void LoadScene(std::string);	
};
#endif
