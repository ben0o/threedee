
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
	vec3Rotation.y += _x;
	vec3Rotation.x += _y;
}
void Camera::Update(double dt)
{
}
void Camera::Draw()
{
	glRotatef(vec3Rotation.x, 1.f, 0.f, 0.f);
	glRotatef(vec3Rotation.y, 0.f, 1.f, 0.f);
	glRotatef(vec3Rotation.z, 0.f, 0.f, 1.f);
	glTranslatef(vec3Position.x,vec3Position.y,vec3Position.z);
}
