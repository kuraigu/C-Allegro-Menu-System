#include "game_system.h"

/*
 * Reserve name for RGB colors
 * Ex. ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
 */

#pragma once
class color_system
{
public:
	color_system(void);
	~color_system(void);

	// Primary
	ALLEGRO_COLOR black;
	ALLEGRO_COLOR white;

	ALLEGRO_COLOR red;
	ALLEGRO_COLOR green;
	ALLEGRO_COLOR blue;

	void init();
};

