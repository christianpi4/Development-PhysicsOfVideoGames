#ifndef __ModuleColliders_H__
#define __ModuleColliders_H__

#define MAX_COLLIDERS 100

#include "Module.h"
#include "ModuleRender.h"


enum ColliderType	//Set Type of Colliders
{
	COLLIDER_NONE = -1,
	COLLIDER_FLOOR,
	COLLIDER_PLAYER,
	COLLIDER_MAX,

};

struct Collider
{
	SDL_Rect rect = {0, 0, 0, 0};
	bool to_delete = false;
	ColliderType type = COLLIDER_NONE;
	Module* callback = nullptr;

	Collider(SDL_Rect* rectangle, ColliderType type, Module* callback = nullptr) :
		rect(*rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;

	bool Enabled = true;
};

class ModuleColliders : public Module
{
public:

	ModuleColliders();
	~ModuleColliders();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();


	Collider* AddCollider(SDL_Rect rect, ColliderType type, Module* callback = nullptr);
	
	void DebugDraw();

	

private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug = false;
};

#endif //__ModuleCollision_H__