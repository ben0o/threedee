
#ifndef CAMERA_H
#define CAMERA_H

#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"

class Camera
{
public:
	Camera();
	Camera(glm::vec3);
	Camera(double,double,double);
	~Camera();
	
	void MouseSetRotation(double,double);
	
	void Update(double);
	void Draw();
	
private:
	glm::vec3 vec3Position;
	glm::vec3 vec3Rotation;
};


#endif
