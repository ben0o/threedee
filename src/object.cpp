#include "object.hpp"

Object::Object()
{
	name = "";
	meshFilename = "";
	x = 0.f;
	y = 0.f;
	z = 0.f;
	rx = 0.f;
	ry = 0.f;
	rz = 0.f;
}
Object::~Object()
{
	
}
void Object::Draw(Shader* _shader)
{
	for (std::vector<Mesh>::size_type i = 0;i<meshCollection.size(); i++)
	{
		meshCollection[i].Draw(_shader);
	}
}
