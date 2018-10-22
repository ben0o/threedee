#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H
#define GL_GLEXT_PROTOTYPES

#include "GLFW/glfw3.h"
#include "controller.hpp"
#include "SceneManager.hpp"
#include "Structs.hpp"
#include <string.h>
#include <cmath>
 
class ControllerGame : public Controller
{
public:
	ControllerGame();
	ControllerGame(Console*,Settings*,SceneManager*);
	~ControllerGame();

	virtual void Update(double);
	virtual void Draw(GLFWwindow*);
	
	virtual void CompareSettings();

	void MouseSetRotation(double,double);
private:
	void LoadLevel();

protected:
	SceneManager* p_sceneManager;
	Settings settings;
	bool bLoading;

	
};
#endif
