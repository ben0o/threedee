#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include "MeshManager.hpp"
#include "TextureManager.hpp"
#include "Structs.hpp"
#include <string.h>
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu();
	ControllerMenu(Console*,Settings*,SceneManager*);
	~ControllerMenu();

	virtual void Update(double);
	virtual void Draw();
	std::string GetCurrentLevel();
	
	
protected:
	SceneManager* p_sceneManager;
	
};
#endif
