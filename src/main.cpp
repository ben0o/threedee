
#define GLEW_STATIC

#define SCREEN_WIDTH 1024.0f
#define SCREEN_HEIGHT 768.0f
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "engine.hpp"

Engine engine;

static void error_callback(int error, const char* description)
{
	std::cout << description << ":" << stderr << std::endl;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	engine.KeyCallback(key, scancode, action, mods);
}
static void mouse_callback(GLFWwindow* window,double x, double y)
{
	engine.MouseCallback(x, y);
}
void framebuffer_size_callback( GLFWwindow* window, int width, int height )
{
	glViewport( 0, 0, (int) width, (int) height );
}
int main(int argc, char **argv)
{
	glewExperimental = true;
	
	glfwSetErrorCallback(error_callback);
	glfwInit();
	
	std::cout << "Initialised GLFW" <<std::endl;
	
	glfwWindowHint(GLFW_SAMPLES, 4); 									// 4x AA
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 		// We don't want the old OpenGL 
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ThreeDee", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	//callbacks
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	
	glfwSwapInterval(1);

	glewInit();
	std::cout << "Initialised GLEW" <<std::endl;
	
	engine.Run(window);
	
	return 0;
}
