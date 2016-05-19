#include "color_system.h"


color_system::color_system(void)
{
}


color_system::~color_system(void)
{
}

// Map the RGB colors to individual reserved color names
// Shall only be called once game_system->init was called
void color_system::init()
{
	black = al_map_rgb(0, 0, 0);
	white = al_map_rgb(255, 255, 255);

	red = al_map_rgb(255, 0, 0);
	green = al_map_rgb(0, 255, 0);
	blue = al_map_rgb(0, 0, 255);
}