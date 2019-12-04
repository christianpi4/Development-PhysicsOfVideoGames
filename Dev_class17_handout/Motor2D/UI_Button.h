#pragma once
#ifndef __UI_BUTTON_H__
#define __UI_BUTTON_H__

//#include "Animation.h"
#include "UI.h"
//#include "Label.h"
//#include "Image.h"
#include "UI_Button.h"
#include "p2List.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Button : public UI
{
public:
	Button(int x, int y, SDL_Rect idle, SDL_Rect hover, SDL_Rect click, UI* parent, /*Label* name,*/ j1Module* CallBack);

	~Button();

	bool CleanUp();

	bool Draw();

	bool Update(float dt);

public:
	//Label* text;

	SDL_Rect button_idle;
	SDL_Rect button_hover;
	SDL_Rect button_click;

	bool clicked = false;
};

#endif //__UI_BUTTON__