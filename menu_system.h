#include "game_system.h"

/*
 * This class is specifically for creating menus
 */

#pragma once
class menu_system
{
private:
	// These variables/functions are set as private to avoid changes from non-members
	int buttonsNum;

public:
	menu_system(void);
	~menu_system(void);

	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *button[8];
	ALLEGRO_BITMAP *hoverButton;

	ALLEGRO_FONT *buttonFont;

	bool done;
	bool overButton[8];

	int x[8] , y[8];
	int w, h;

	char *buttonText[8];

	int init();
	int reserveButtonNum(int num);
	int detectButtonHover(int curX, int curY);
	int draw(int ax, int ay);
	int destroy();
};

