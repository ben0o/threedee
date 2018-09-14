
#include "engine.hpp"

void Engine::GLCallbackMouseMove(int x, int y)
{
	int centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	int centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

	int deltaX =  x - centerX;
	int deltaY =  y - centerY;

	if(deltaX != 0 || deltaY != 0) 
	{
		magnitudeMouseX = deltaX * 0.2f;
		magnitudeMouseY = deltaY * 0.2f;

		glutWarpPointer(centerX, centerY);
	}
}
void Engine::GLCallbackKeyPress(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'w':
		{
			forward = 1;
			break;
		}
		case 's':
		{
			forward = -1;
			break;
		}
		case 'a':
		{
			left = 1;
			break;
		}
		case 'd':
		{
			left = -1;
			break;
		}
		case '3':
		{
			break;
		}
		case 'q':
		{
			Unload();
		}
	}
}
void Engine::GLCallbackKeyRelease(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'w':
		{
			forward = 0;
			break;
		}
		case 's':
		{
			forward = 0;
			break;
		}
		case 'a':
		{
			left = 0;
			break;
		}
		case 'd':
		{
			left = 0;
			break;
		}
	}
}
void Engine::FirstRunInitialise()
{
	bGameRunning = false;
	bShowMenu = true;
	
	p_console = new Console();
	p_console->Message(0,"Console initialised");
	p_console->bShowFrameRate = true;
	p_cntrMenu = new ControllerMenu(p_console);
	p_cntrGame = new ControllerGame(p_console);
	p_cntrCurrent = p_cntrGame;
}
void Engine::ToggleMenu()
{
	//if (bGameRunning && !p_cntrCurrent->bShowLoadingScreen)
	//{
		if (!bShowMenu)
		{ //Show menu
			p_console->Message(0,"Assign Menu to Controller Pointer");
			p_cntrCurrent = p_cntrMenu;
			bShowMenu = true;
		}
		else
		{ //Show game
			p_console->Message(0,"Assign Game to Controller Pointer");
			p_cntrCurrent = p_cntrGame;
			bShowMenu = false;
		}
	//}
}
void Engine::Update()
{
	double dt;
	p_console->UpdateRate();
	p_cntrCurrent->Update(dt);
}
void Engine::Draw()
{
	p_cntrCurrent->Draw();
    p_console->DisplayFrameRate();
	p_console->FrameRate();

}
void Engine::Unload()
{
	p_console->Message(0,"User exit");
	exit(0);
}
