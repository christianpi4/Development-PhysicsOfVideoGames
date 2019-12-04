#pragma once
#ifndef __UI_H__
#define __UI_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"
//#include "Animation.h"
#include "j1Render.h"
#include "j1App.h"

struct SDL_Texture;

class UI
{

public:

	//Constructor
	UI() {}
	UI(int x, int y, UI* parent, j1Module* CallBack);

	//Destructor
	virtual ~UI() {}

	// Called each loop iteration
	virtual bool Update(float dt);

	// Called each loop iteration
	virtual bool Draw();

	// Called before quitting
	virtual bool CleanUp();

	bool Intersection();

public:
	fPoint position;

	SDL_Texture* atlas = nullptr;

	SDL_Texture* texture = nullptr;

	SDL_Rect debug_UI;

	SDL_Rect rect;

	UI* parent;

	j1Module* callback = nullptr;

	bool destroy = false;
};

#endif //__UI__H