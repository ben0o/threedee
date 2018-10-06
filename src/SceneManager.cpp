
#include "SceneManager.hpp"
SceneManager::SceneManager()
{
}
SceneManager::SceneManager(MeshManager* _ptrMeshMan, TextureManager* _ptrTexMan)
{
	p_meshManager = _ptrMeshMan;
	p_textureManager = _ptrTexMan;
}
SceneManager::~SceneManager()
{
}
void SceneManager::Draw()
{
	for (std::vector<Object>::size_type i = 0;i<objects.size();i++)
	{
		glRotatef(45, 1.f, 0.f, 0.f);
		p_meshManager->Draw(objects[i].meshID);
	}
}
void SceneManager::Update(double _dt)
{
	
}
void SceneManager::AddObject(float _x, float _y, float _z)
{
	int temp;
	temp = p_meshManager->LoadObj("cabin.obj");
	
	Object obj;
	obj.meshID = temp;
	obj.x = _x;
	obj.y = _y;
	obj.z = _z;
	
	objects.push_back(obj);
}
