#include "menu_system.h"


menu_system::menu_system(void)
{
}


menu_system::~menu_system(void)
{
}

int menu_system::init()
{
	return 0;
}

// De-allocate memory from alllegro variables to avoid memory leak
// (!) Must be called before the main function returns a value
int menu_system::destroy()
{
	al_destroy_bitmap(background);
	al_destroy_bitmap(hoverButton);

	for(int i = 1; i <= buttonsNum; i++)
	{
		al_destroy_bitmap(button[i]);
	}

	al_destroy_font(buttonFont);

	return 0;
}

// Draw the background and buttons of a created
// menu
int menu_system::draw(int ax, int ay)
{
	int increments = 0;

	al_draw_bitmap(background, 0, 0, NULL);

	for(int i = 1; i <= buttonsNum; i++)
	{
		increments += ay;
		y[i] = increments;
		x[i] = ax;

		al_draw_bitmap(button[i], x[i], y[i], NULL);
	}

	return 0;
}

// Detect if the cursor is inside or hitting the borders of
// a button
int menu_system::detectButtonHover(int curX, int curY)
{
	for(int i = 1; i <= buttonsNum; i++)
	{
		if((curX >= x[i]) && (curX <= x[i]+w) && (curY >= y[i]) && (curY <= y[i]+h))
		{
			al_draw_bitmap(hoverButton, x[i], y[i], NULL);
			overButton[i] = true;
		}

		else 
		{
			overButton[i] = false;
		}
	}

	return 0;
}

int menu_system::reserveButtonNum(int num)
{
	buttonsNum = num;
	
	return 0;
}