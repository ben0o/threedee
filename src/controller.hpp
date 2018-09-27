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
	
	void SetForegroundStatus();					//used to switch between controllers
	bool GetForegroundStatus();
	virtual void Update(double);
	virtual void Draw();

	virtual void LoadScene(std::string);
	virtual void LoadAssets();
	Console* p_console;
	bool bActive;
	
private:
	
};
#endif
