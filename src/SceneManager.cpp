
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
		glPushMatrix();
		glTranslatef(objects[i].x,objects[i].y,objects[i].z);
		glRotatef(objects[i].rx, 1.f, 0.f, 0.f);
		glRotatef(objects[i].ry, 0.f, 1.f, 0.f);
		glRotatef(objects[i].rz, 0.f, 0.f, 1.f);
		p_meshManager->Draw(objects[i].meshID);
		glPopMatrix();
	}
}
void SceneManager::Update(double _dt)
{
	
}
void SceneManager::AddObject(Object _object)
{
	_object.meshID = p_meshManager->LoadObj(_object.meshFilename);
	objects.push_back(_object);
}
