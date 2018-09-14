#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "console.hpp"

class Controller
{
public:
	Controller();
	Controller(Console*);
	~Controller();
	
	virtual void Update(double);
	virtual void Draw();

	virtual void LoadScene(std::string);
	virtual void LoadAssets();
	Console* p_console;
private:
	
};
#endif
