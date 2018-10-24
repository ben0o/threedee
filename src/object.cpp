#include "object.hpp"

Object::Object()
{
	name = "";
	meshFilename = "";

}
Object::Object(glm::vec3 _pos, glm::vec3 _rot)
{
	position = _pos;
	rotation = _rot;
}
Object::~Object()
{
	
}
void Object::SetPosition(glm::vec3 _pos)
{
	position = _pos;
}
void Object::SetRotation(glm::vec3 _rot)
{
	rotation = _rot;
}
void Object::Draw(Shader* _shader)
{
	for (std::vector<Mesh>::size_type i = 0;i<meshCollection.size(); i++)
	{
		meshCollection[i].Draw(_shader);
	}
}
