#ifndef WORLD_H
#define WORLD_H

class World
{
public:
	World();
	~World();
	
	void AddObjectToScene();
	void CalculateVisibility();
	void DrawScene();
protected:
};

#endif
