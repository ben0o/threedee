#ifndef SCENEMAN_H
#define SCENEMAN_H

#include <vector>
#include "MeshManager.hpp"
#include "TextureManager.hpp"
#include "Structs.hpp"

class SceneManager
{
public:
	SceneManager();
	SceneManager(MeshManager*,TextureManager*);
	~SceneManager();
	
	void Draw();
	void Update(double);
	void AddObject(float, float, float);
	
private:
	MeshManager* p_meshManager;
	TextureManager* p_textureManager;
	std::vector<Object>objects;
};

#endif
