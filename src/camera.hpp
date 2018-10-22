#ifndef CAMERA_H
#define CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL

#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include <cmath>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include <iostream>


class Camera
{
public:
	Camera();
	Camera(glm::vec3);
	Camera(double,double,double);
	~Camera();
	
	void MouseSetRotation(double,double);
	
	void Update(double);
	glm::mat4 Draw(GLFWwindow*,glm::mat4);
	
private:
	glm::vec3 vec3Position;
	glm::vec3 vec3Rotation;
};


#endif
