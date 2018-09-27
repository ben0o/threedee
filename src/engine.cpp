
#include "engine.hpp"

void Engine::MouseCallback(double x, double y)
{
	float deltaX =  x - oldMousePosX;
	float deltaY =  y - oldMousePosY;
	
	mouseSensitivity = 0.01;
	deltaX *= mouseSensitivity;
	deltaY *= mouseSensitivity;

	//Direct hook into camera rotation from mouse movement to prevent lag
	p_camera->MouseSetRotation(deltaX,deltaY);
	
	oldMousePosX = x;
	oldMousePosY = y;
}
void Engine::KeyCallback(int key, int scancode, int action, int mods)
{

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
			p_cntrCurrent->SetForegroundStatus();
			bShowMenu = true;
		}
		else
		{ //Show game
			p_console->Message(0,"Assign Game to Controller Pointer");
			p_cntrCurrent = p_cntrGame;
			p_cntrCurrent->SetForegroundStatus();
			bShowMenu = false;
		}
	//}
}
void Engine::Run(GLFWwindow* window)
{
	p_window = window;
	
	p_console = new Console(p_window);
	p_console->Message(0,"Console initialised");

	p_cntrMenu = new ControllerMenu(p_console);
	p_cntrGame = new ControllerGame(p_console);
	
	//Set the menu as the current controller object
	p_cntrCurrent = p_cntrMenu;
	p_cntrCurrent->SetForegroundStatus();
	bShowMenu = true;
	p_console->Message(0,"Assign Menu to Controller Pointer");
	
	//Camera
	p_camera = new Camera(0.0,0.0,-10.5);
	oldMousePosX = 0.0;
	oldMousePosY = 0.0;
	
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
	p_camera->Update(dt);
	if (!p_cntrCurrent->GetForegroundStatus())
	{
		//Current controller has slipped into the background, bring other controller to the front 
		ToggleMenu();
	}
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
	
	p_camera->Draw();
	
	//Draw world here
	
	//***************
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
