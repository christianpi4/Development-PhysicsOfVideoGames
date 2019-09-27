#pragma once
#include "Module.h"
#include "Globals.h"

class b2World;
class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();
	
	b2World* world = nullptr;
	
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 8; 
	int32 positionIterations = 3;

	b2BodyDef groundBodyDef;
	

private:

	bool debug;
};