#ifndef OBJECT_H
#define OBJECT_H
#define GLM_ENABLE_EXPERIMENTAL

#include <string>
#include "Mesh.hpp"
#include "shader.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

class Object
{
public:
	Object();
	Object(glm::vec3, glm::vec3);
	~Object();
	
	void SetPosition(glm::vec3);
	void SetRotation(glm::vec3);
	
	void Draw(Shader*);
	std::string name;
	std::string meshFilename;
	glm::vec3 position;
	glm::vec3 rotation;
	std::vector<Mesh> meshCollection;
};


#endif
