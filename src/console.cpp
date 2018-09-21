#include "console.hpp"

Console::Console(GLFWwindow* window)
{
	p_window = window;
	bEnableVBO = true;
	bEnableFBO = true;
	bShowFrameRate = false;
	basetime = 0;
	frames = 0;
	updates = 0;

	//Not user configurable
	bPlayerCameraInitialised = false;
	bAllowRendering = false;
}
Console::~Console()
{
}
void Console::Message(int level,std::string msg)
{
	std::string leveltext;

	if (level == 0)
		leveltext = "> ";
	if (level == 1)
		leveltext = "Warning> ";
	if (level == 2)
		leveltext = "Error> ";

	std::cout << leveltext << msg << std::endl;
	
}
void Console::Message(int level,std::string msg,float val)
{
	std::cout  << msg << " " << val <<std::endl;
}
void Console::CheckForErrors()
{
	GLenum err (glGetError());
	if(err!=GL_NO_ERROR) 
	{
		std::string error;
		switch(err) 
		{
			case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
			case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
			case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
			case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
		}
		std::cout << "ERROR> " << error << std::endl;
	}
}
void Console::FrameRate()
{
	
	float time = glfwGetTime();
	++frames;
	if ((time - basetime) > 1.0)
	{
		framesPerSecond=frames;
		updatesPerSecond = updates;
		basetime = time;
		frames=0;
		updates=0;
	}
}
void Console::UpdateRate()
{
	updates++;
}
void Console::DisplayFrameRate()
{
	//GLFW doesn't directly support text so we'll do some console stuff instead
	system ("clear"); //We're targeting linux
	std::cout << "FPS:" << framesPerSecond << std::endl;
	
	//std::cout << updatesPerSecond << std::endl;
	
	/*
	int width, height;

	glMatrixMode(GL_PROJECTION);
    glPushMatrix();             
    glLoadIdentity();   
    
	glfwGetFramebufferSize(p_window, &width, &height);

    glOrtho( 0, width, 0, height, -1, 1 );

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable( GL_DEPTH_TEST ); 

    glDisable( GL_LIGHTING );

	int len, len2, j;
	std::stringstream ss;//create a stringstream
	std::stringstream ss2;
	
	ss << "FPS:" << framesPerSecond;
	ss2 << "UPS:" << updatesPerSecond;
	
	std::string str = ss.str();
	std::string str2 = ss2.str();
	
	glColor3f( 255, 255, 255 );
	len = str.size();
	len2 = str2.size();
	
	//glRasterPos3i(0, 0,10);
	glRasterPos2i(10, height - 20);
	for (j = 0; j < len; j++) 
	{
		//glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[j]);
	}
	glRasterPos2i(10, height - 40);
	for (j = 0; j < len2; j++) 
	{
		//glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str2[j]);
	}
	//glEnable( GL_LIGHTING );

	//std::cout<< str << std::endl;
	//std::cout<< str2 << std::endl;

    glEnable (GL_DEPTH_TEST);     

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();  
    */ 
}
