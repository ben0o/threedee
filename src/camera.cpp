
#include "camera.hpp"

Camera::Camera()
{
	vec3Position.x = 0.0;
	vec3Position.y = 0.0;
	vec3Position.z = 0.0;
	
	vec3Rotation.x = 0.0;
	vec3Rotation.y = 0.0;
	vec3Rotation.z = 0.0;
}
Camera::Camera(glm::vec3 _position)
{
	vec3Position = _position;
	vec3Rotation.x = 0.0;
	vec3Rotation.y = 0.0;
	vec3Rotation.z = 0.0;
}
Camera::Camera(double _x, double _y, double _z)
{
	vec3Position.x = _x;
	vec3Position.y = _y;
	vec3Position.z = _z;
	vec3Rotation.x = 0.0;
	vec3Rotation.y = 0.0;
	vec3Rotation.z = 0.0;
}
Camera::~Camera()
{
}
void Camera::MouseSetRotation(double _x, double _y)
{
	//purposely reversed
	vec3Rotation.x += _y;
	vec3Rotation.y += _x;
}
void Camera::Update(double dt)
{
}
glm::mat4 Camera::Draw(GLFWwindow* _window, glm::mat4 _viewMatrix)
{
	/*
	double fovy = 45.0;
	double zNear = 0.1;
	double zFar = 1500;
	
	float ratio;
	int width, height;
	double xmin, xmax, ymin, ymax;
	
	glfwGetFramebufferSize(_window, &width, &height);
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
	
	glRotatef(vec3Rotation.x, 1.f, 0.f, 0.f);
	glRotatef(vec3Rotation.y, 0.f, 1.f, 0.f);
	glRotatef(vec3Rotation.z, 0.f, 0.f, 1.f);
	glTranslatef(vec3Position.x,vec3Position.y,vec3Position.z);
	*/

	_viewMatrix = glm::translate(_viewMatrix, vec3Position);
	_viewMatrix = glm::rotate(_viewMatrix, vec3Rotation.x, glm::vec3(1.0, 0.0, 0.0));
	_viewMatrix = glm::rotate(_viewMatrix, vec3Rotation.y, glm::vec3(0.0, 1.0, 0.0));
	_viewMatrix = glm::rotate(_viewMatrix, vec3Rotation.z, glm::vec3(0.0, 0.0, 1.0));
	
	return _viewMatrix;
}
