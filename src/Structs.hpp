#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include "glm/vec4.hpp"

struct Settings
{
	std::string level;
	Settings()
	{
		level = "";
	}
};

struct Material
{
	std::string name;
	glm::vec4 Ka;						//Ambient
	glm::vec4 Kd;						//Diffuse
	glm::vec4 Ks;						//Specular
	std::string map_Kd;					//Diffuse Map
	std::string map_Ks;					//Specular Map
	std::string map_bump;				//Bump Map
	
	int index_Kd;
	int index_Ks;
	int index_bump;
	Material()
	{
		Ka = glm::vec4(1.f,1.f,1.f,1.f);
		Kd = glm::vec4(1.f,1.f,1.f,1.f);
		Ks = glm::vec4(0.f,0.f,0.f,1.f);
		map_Kd = "";
		map_Ks = "";
		map_bump = "";
		index_Kd = -1 ;
		index_Ks = -1 ;
		index_bump = -1;
	}
};


#endif
