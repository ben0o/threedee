#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct Settings
{
	std::string level;
	Settings()
	{
		level = "";
	}
};

struct Object
{
	std::string name;
	int meshID;
	float x;
	float y;
	float z;
	float rx;
	float ry;
	float rz;
	Object()
	{
		name = "";
		meshID = -1;
		x = 0.f;
		y = 0.f;
		z = 0.f;
		rx = 0.f;
		ry = 0.f;
		rz = 0.f;
	}
};

#endif
