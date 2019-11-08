#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	
	App->camera->Position.x += 1;
	App->camera->Position.y += 1;

	App->camera->LookAt((10.0f,10.0f,0.0f));
	//App->camera->LookAt(position);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	Plane grown(0.0f, 1.0f, 0.0f, 1.0f);
	grown.axis = true;
	grown.Render();

	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere sphere1(0.5f);
	sphere1.SetPos(10.0f, 0.0f, 0.0f);
	sphere1.SetRotation(15, vec3(0.0f, 1.0f, 0.0f));
	sphere1.Render();

	Cylinder cylinder1(1.0f, 1.0f);
	cylinder1.SetPos(20.0f, 0.0f, 0.0f);
	cylinder1.SetRotation(90, vec3(0.0f, 1.0f, 0.0f));
	cylinder1.Render();

	Cube cube1(1.0f, 2.0f, 1.0f);
	cube1.SetPos(30.0f, 0.0f, 0.0f);
	cube1.SetRotation(270, vec3(0.0f, 0.0f, 1.0f));
	cube1.Render();

	return UPDATE_CONTINUE;
}

