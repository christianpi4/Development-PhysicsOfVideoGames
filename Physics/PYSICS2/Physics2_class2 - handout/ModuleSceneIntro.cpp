#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

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
	// TODO 5: Move all creation of bodies on 1,2,3 key press here in the scene
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->physics->Shape(50, App->input->GetMouseX(), App->input->GetMouseY(), true);

	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{

		App->physics->ShapeBox(App->input->GetMouseX(), App->input->GetMouseY(), 15, 15, true);

	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{

		App->physics->ShapeChain(1, App->input->GetMouseX(), App->input->GetMouseY(), true);

	}

	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
	{
		App->physics->ShapeChain(2, App->input->GetMouseX(), App->input->GetMouseY(), true);

	}

	if (App->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN)
	{

		App->physics->ShapeChain(3, App->input->GetMouseX(), App->input->GetMouseY(), true);

	}
	// TODO 7: Draw all the circles using "circle" texture

	return UPDATE_CONTINUE;
}
