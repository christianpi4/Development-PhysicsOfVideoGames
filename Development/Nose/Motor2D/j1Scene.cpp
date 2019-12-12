#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Player.h"
#include "j1Collider.h"

#include <string>

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	pugi::xml_node map;
	for (map= config.child("map"); map; map = map.next_sibling("map"))
	{
		p2SString* lvl = new p2SString();

		lvl->create(map.attribute("name").as_string());
		
		maps.add(lvl->GetString());
	}

	bool ret = true;

	return ret;
}

// Called before the first frame

// Loads map and audio
bool j1Scene::Start()
{
	LOG("LOADING MAP");
	current_map = maps.start->data;
	App->map->Load(current_map.GetString());

	//load audio from map 1
	if (current_map == "Map.tmx") {

		App->audio->PlayMusic("audio/music/map1_music.ogg");
		jump_FX= App->audio->LoadFx("audio/fx/Jump.wav");
		death_FX = App->audio->LoadFx("audio/fx/Death.wav");


	}

	//load audio from map 2
	else if(current_map=="map2.tmx") {
		
		App->audio->PlayMusic("audio/music/map2_music.ogg");
		jump_FX = App->audio->LoadFx("audio/fx/Jump.wav");
		death_FX = App->audio->LoadFx("audio/fx/Death.wav");
	}
	
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	
	p2List_item<p2SString>* i = maps.start;

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN) {


		current_map.create("Map.tmx");				// it starts in map 1 

		App->map->CleanUp();
		App->player->CleanUp();						//clean all map and player stuff 

		if (current_map == "Map.tmx") {												//load audio from map 1

			App->audio->PlayMusic("audio/music/map1_music.ogg");
			jump_FX = App->audio->LoadFx("audio/fx/Jump.wav");
			death_FX = App->audio->LoadFx("audio/fx/Death.wav");

		}

		App->map->Load(current_map.GetString());
		App->player->Start();
		App->map->Draw();
		
		App->player->data_player.position.x = 100;
		App->player->data_player.position.y = 300;				// initial position in map 1 by default

	}

	i = i->next;

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {


		current_map.create("map2.tmx");								// it starts in map 1 

		App->map->CleanUp();
		
		App->player->CleanUp();

		//charge map 2 position when player presses F2
		if (current_map == "map2.tmx") {

		App->audio->PlayMusic("audio/music/map2_music.ogg");						//load audio from map 1
		jump_FX = App->audio->LoadFx("audio/fx/Jump.wav");
		death_FX = App->audio->LoadFx("audio/fx/Death.wav");

		}

		App->map->Load(current_map.GetString());
		
		App->player->Start();
		App->map->Draw();
		
		//charge map 2 position when F2 is pressed
		App->player->data_player.position.x = 55;
		App->player->data_player.position.y = 10;

	}

	else {


		App->map->Draw();		//draws the correspondant map

	}

	//restart map and puts the player at the beginning of it
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		if(current_map=="Map.tmx"){
		App->player->data_player.position.x = 100;
		App->player->data_player.position.y = 300;
		App->player->data_player.player_flip = SDL_FLIP_NONE;
		}

		else {
			App->player->data_player.position.x = 55;
			App->player->data_player.position.y = 10;
			App->player->data_player.player_flip = SDL_FLIP_NONE;
		}
	}

	//save player position in every map
	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
		
		App->SaveGame();

		App->player->data_player.position.y -= 20;
	}
		
	//load player position in every map
	if (App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)						
	App->LoadGame();


	
	 // Show player and map colliders
	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN)						
	{
		if (App->player->data_player.showcolliders == false)
		{
			App->player->data_player.showcolliders = true;
		}
		else if (App->player->data_player.showcolliders == true)
		{
			App->player->data_player.showcolliders = false;
		}
	}

	
	

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;


	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	return true;
}

//load function
bool j1Scene::Load(pugi::xml_node& data)
{
	LOG("Loading Scene state");
	App->map->CleanUp();
	App->collider->CleanUp();																//cleans the colliders and map
	
	current_map.create(data.child("scene").attribute("name").as_string());					//check which map have to be loaded and load it
	App->map->Load(current_map.GetString());
	App->collider->Start();
	App->player->Start();
	
	return true;
}


bool j1Scene::Save(pugi::xml_node& data) const
{
	LOG("Saving Scene state");
	pugi::xml_node scene = data.append_child("scene");
	scene.append_attribute("name") = current_map.GetString();

	return true;
}

void j1Scene::SecondMap() {
	
	App->map->CleanUp();
	App->collider->CleanUp();


	p2List_item<p2SString>* i;
	for (i = maps.start; i->data != current_map.GetString(); i = i->next) {
		LOG("%s  %s", i->data.GetString(), current_map.GetString());
	}

	if (i->next != NULL) { i = i->next; }
	else { i = maps.start; }
	current_map = i->data;

	App->map->Load(current_map.GetString());
	App->map->Draw();
	App->collider->Start();
	
	//charge map 1 position when initialize the game

	if (current_map == "Map.tmx") {

		App->player->data_player.position.x = 100;
		App->player->data_player.position.y = 500;
		
		App->audio->PlayMusic("audio/music/map1_music.ogg");
		jump_FX = App->audio->LoadFx("audio/fx/Jump.wav");
		death_FX = App->audio->LoadFx("audio/fx/Death.wav");
		App->player->Start();
	}

	//charge map 2 position when player completes level 1
	else if(current_map=="map2.tmx"){

		App->player->data_player.position.x = 55;
		App->player->data_player.position.y = 10;

		App->audio->PlayMusic("audio/music/map2_music.ogg");
		jump_FX = App->audio->LoadFx("audio/fx/Jump.wav");
		death_FX = App->audio->LoadFx("audio/fx/Death.wav");
		App->player->Start();
	}

	
	
}