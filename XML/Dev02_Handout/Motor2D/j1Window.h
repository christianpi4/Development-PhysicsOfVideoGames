#ifndef __j1WINDOW_H__
#define __j1WINDOW_H__

#include "j1Module.h"

struct SDL_Window;
struct SDL_Surface;

class j1Window : public j1Module
{
public:

	j1Window();

	bool Load();
	bool Save();
	bool	save;
	bool	load;
	pugi::xml_document	saveconfig_file;
	pugi::xml_node		saveconfig;
	pugi::xml_node		saveapp_config;

	// Destructor
	virtual ~j1Window();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before quitting
	bool CleanUp();

	// Changae title
	void SetTitle(const char* new_title);

	// Retrive window size
	void GetWindowSize(uint& width, uint& height) const;

	// Retrieve window scale
	uint GetScale() const;

public:
	//The window we'll be rendering to
	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* screen_surface;

private:
	p2SString	title;
	uint		width;
	uint		height;
	uint		scale;
};

#endif // __j1WINDOW_H__