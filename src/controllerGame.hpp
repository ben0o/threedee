#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H

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
	virtual void Draw();
	
	virtual void CompareSettings();

private:
	void LoadLevel();

protected:
	SceneManager* p_sceneManager;
	Settings settings;
	
};
#endif
