#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------

struct Layer
{
	p2SString name;
	uint width;
	uint height;
	uint* data;
};

struct TileSet {

	p2SString name;
	uint firstgid = 0u;
	uint tilewidth = 0u;
	uint tileheight = 0u;
	uint spacing =0u;
	uint margin = 0u;

	p2SString name_file;
	uint width_file;
	uint height_file;

	
};

// TODO 1: Create a struct needed to hold the information to Map node


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);
	
	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);
	
	

private:

	//Fill Info Map

	bool FillInfoMap(pugi::xml_node& conf);
	bool FillTileSet();
	bool FillLayer();
	void LogMapData(bool, bool, bool) const;
	void DrawTilesets(uint num = 0) const;

public:

	// TODO 1: Add your struct for map info as public for now
	struct Map {

		enum MapOrientation {

			OR_UNDEFINED,
			OR_ORTOGONAL,
			OR_ISOMETRIC,
			OR_HEXAGONAL,

		};
		enum MapRenderOrder {

			RE_UNDEFINED,
			RE_RIGHT_DOWN,
			RE_RIGHT_UP,
			RE_LEFT_DOWN,
			RE_LEFT_UP,
		};

		MapOrientation orientation ;
		MapRenderOrder renderer;

		uint width = 0u;
		uint height = 0u;
		uint tilewidth = 0u;
		uint tileheight = 0u;
		uint nextobjective = 0u;

	};

	Map map;
	p2List<TileSet*> tilesets;
	
	p2List<SDL_Texture*> tile_texture;
	p2List<Layer*> layers;

	uint Get(uint, uint, uint) const;
	p2Point<uint> GetTilePos(uint, uint) const;
	inline p2Point<uint> GetWorldPos(uint, uint) const;
	SDL_Rect tile_id(uint, uint*) const;

private:
	
	p2SString			path_map;
	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;

	

};

#endif // __j1MAP_H__