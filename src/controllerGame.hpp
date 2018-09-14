#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H

#include "controller.hpp"
#include <string.h>
 
class ControllerGame : public Controller
{
public:
	ControllerGame();
	ControllerGame(Console*);
	~ControllerGame();

	virtual void Update(double);
	virtual void Draw();
	virtual void LoadScene(std::string);	
};
#endif
