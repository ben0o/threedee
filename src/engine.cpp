
#include "engine.hpp"

void Engine::MouseCallback(double x, double y)
{
	/*
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
	*/ 
}
void Engine::KeyCallback(int key, int scancode, int action, int mods)
{
	forward = 0;
	left = 0;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(p_window, GL_TRUE);

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
void Engine::Run(GLFWwindow* window)
{
	p_window = window;
	bGameRunning = false;
	bShowMenu = true;
	
	p_console = new Console(p_window);
	p_console->Message(0,"Console initialised");
	p_console->bShowFrameRate = true;
	p_cntrMenu = new ControllerMenu(p_console);
	p_cntrGame = new ControllerGame(p_console);
	
	p_cntrCurrent = p_cntrGame;
	
	double timeDelta = 1.0/30.0;
	double timeAccumulator = 0;
	double timeStart = glfwGetTime();
	double timeSimulatedThisIteration;
	while(!glfwWindowShouldClose(p_window))
	{
		timeStart = glfwGetTime();
		timeSimulatedThisIteration = 0;
		
		while ( timeAccumulator >= timeDelta )
		{
			Update(timeDelta);
			timeAccumulator -= timeDelta;
			timeSimulatedThisIteration += timeDelta;
		}
		
		Draw();
		glfwSwapBuffers(p_window);
		glfwPollEvents();    
		timeAccumulator += glfwGetTime() - timeStart;
	}
	glfwTerminate();
}
void Engine::Update(double dt)
{
	p_console->UpdateRate();
	p_cntrCurrent->Update(dt);
}
void Engine::Draw()
{
	double fovy = 45.0;
	double zNear = 0.1;
	double zFar = 1500;
	
	float ratio;
	int width, height;
	double xmin, xmax, ymin, ymax;
	
	glfwGetFramebufferSize(p_window, &width, &height);
	ratio = width / (float) height;
	glViewport(0, 0, width, height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	ymax = zNear * tan(fovy * M_PI / 360.0);
	ymin = -ymax;
	xmin = ymin * ratio;
	xmax = ymax * ratio;
	glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f,0.0f,-5.0f);
	
	p_cntrCurrent->Draw();
    p_console->DisplayFrameRate();
	p_console->FrameRate();
	p_console->CheckForErrors();

}
void Engine::Unload()
{
	p_console->Message(0,"User exit");
	exit(0);
}
