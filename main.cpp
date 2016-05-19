#include "game_system.h"	 
#include "menu_system.h"
#include "color_system.h"

/*
 * Title     : Guerrilla Warfare
 * Developer : Andrei Innoh Craig Reloza (Lead) 
 *
 * This header includes the main function
 * All important things will be implemented here
 */

#define MM_BUTTON_NUMBER 4
#define PAUSE_BUTTON_NUMBER 3

#define buttonFontSize 30

// objects
game_system game;
menu_system mainmenu;
menu_system pause;
color_system color;

// pre-defined functions
int init();
int destroy();

// pre-defined variables
ALLEGRO_COLOR buttonTextColor[8];

int curX, curY;
int result = 0;

int main()
{
	// Initialize class functions
	game.init();
	mainmenu.init();
	pause.init();
	color.init();

	init();
	mainmenu.reserveButtonNum(MM_BUTTON_NUMBER);
	pause.reserveButtonNum(PAUSE_BUTTON_NUMBER);


	// Game loops constantly if bool done of object game is false
	while(!game.done)
	{
		al_wait_for_event(game.evQueue, &game.ev);

		if(game.ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)						    // Close the game forcefully
		{
			result = al_show_native_message_box(game.window, gameTitle, "Warning", 
				"Closing the game from the control tab can damage your data \nClose?", NULL, ALLEGRO_MESSAGEBOX_WARN | ALLEGRO_MESSAGEBOX_YES_NO);

			if(result == 1) game.done = true;
		}

		if(game.ev.type == ALLEGRO_EVENT_MOUSE_AXES)							// Mouse is moving
		{
			curX = game.ev.mouse.x;
			curY = game.ev.mouse.y;
		}

		if(game.ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			// If the user is in main menu
			if(!mainmenu.done)
			{
				if(game.ev.mouse.button & 1)					// If Left Button is clicked

				if(mainmenu.overButton[1] == true) mainmenu.done = true;			// START
				if(mainmenu.overButton[2] == true) game.done = true;				// OPTIONS
				if(mainmenu.overButton[3] == true) game.done = true;				// CREDITS
				if(mainmenu.overButton[4] == true) game.done = true;				// QUIT
			}

			// If the use pauses the game
			if(!pause.done)
			{
				if(game.ev.mouse.button & 1)					// If Left Button is clicked

				if(pause.overButton[1] == true) pause.done = true;					// RESUME

				if(pause.overButton[2] == true)										// MAIN MENU
				{
					pause.done = true;
					mainmenu.done = false;
				}

				if(pause.overButton[3] == true) game.done = true;					// QUIT
			}
	
		}

		// If ESCAPE key is pressed
		if(game.ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			if(mainmenu.done)
			{
				if(pause.done) pause.done = false;
			}
		}

		if(game.ev.type == ALLEGRO_EVENT_TIMER)									// Frame rate per second
		{
			if(game.ev.timer.source == game.timer)			// 60 fps
			{
				game.redraw = true;

				if(!mainmenu.done)
				{
				}
			}
		}

		if(game.redraw)															// Redraw drawn objects every timer tick
		{
			// If main menu is enabled
			if(!mainmenu.done)			
			{
				for(int i = 1; i <= MM_BUTTON_NUMBER; i++)
				{
					if(mainmenu.overButton[i] == true) buttonTextColor[i] = color.black;
					else buttonTextColor[i] = color.white;
				}

				mainmenu.draw(gameWidth / 2 - (mainmenu.w / 2), 120);
				mainmenu.detectButtonHover(curX, curY);
				al_draw_text(mainmenu.buttonFont, buttonTextColor[1], gameWidth / 2 , mainmenu.y[1] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "START");
				al_draw_text(mainmenu.buttonFont, buttonTextColor[2], gameWidth / 2 , mainmenu.y[2] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "OPTIONS");
				al_draw_text(mainmenu.buttonFont, buttonTextColor[3], gameWidth / 2 , mainmenu.y[3] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "CREDITS");
				al_draw_text(mainmenu.buttonFont, buttonTextColor[4], gameWidth / 2 , mainmenu.y[4] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "QUIT");
			}

			else
			{
				if(!pause.done)
				{
					for(int i = 1; i <= PAUSE_BUTTON_NUMBER; i++)
					{
						if(pause.overButton[i] == true) buttonTextColor[i] = color.black;
						else buttonTextColor[i] = color.white;
					}

					pause.draw(gameWidth / 2 - (mainmenu.w / 2), 120);
					pause.detectButtonHover(curX, curY);
					al_draw_text(pause.buttonFont, buttonTextColor[1], gameWidth / 2 , pause.y[1] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "RESUME");
					al_draw_text(pause.buttonFont, buttonTextColor[2], gameWidth / 2 , pause.y[2] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "MAIN MENU");
					al_draw_text(pause.buttonFont, buttonTextColor[3], gameWidth / 2 , pause.y[3] + buttonFontSize, ALLEGRO_ALIGN_CENTER, "QUIT");
				}
			}

			al_flip_display();
			al_clear_to_color(color.black);
		}
	}

	game.destroy();
	mainmenu.destroy();
	pause.destroy();

	return 0;
}

// (!) Initialize resources that can't be declared in their native classes
int init()
{
	mainmenu.done = false;
	pause.done = true;

	// These functions/variables doesn't need to be destroyed as they are destroyed
	// automatically in their member functions

	// ----------------------------------------------------------------------------
	// Main Menu
	mainmenu.background = al_load_bitmap("res/bg/main_menu_bg_001.png");

	for(int i = 1; i <= MM_BUTTON_NUMBER; i++)
	{
		buttonTextColor[i] = color.white;
		mainmenu.button[i] = al_load_bitmap("res/bt/button_001.png");
		mainmenu.w = al_get_bitmap_width(mainmenu.button[i]);
		mainmenu.h = al_get_bitmap_height(mainmenu.button[i]);
	}

	mainmenu.hoverButton = al_load_bitmap("res/bt/over_button_001.png");

	mainmenu.buttonFont = al_load_font("res/fonts/Roboto-thin.ttf", buttonFontSize, NULL); 
	// ----------------------------------------------------------------------------

	// Pause
	pause.background = al_load_bitmap("res/bg/pause_bg_001.png");

	for(int i = 1; i <= PAUSE_BUTTON_NUMBER; i++)
	{
		buttonTextColor[i] = color.white;
		pause.button[i] = al_load_bitmap("res/bt/button_001.png");
		pause.w = al_get_bitmap_width(pause.button[i]);
		pause.h = al_get_bitmap_height(pause.button[i]);
	}

	pause.hoverButton = al_load_bitmap("res/bt/over_button_001.png");

	pause.buttonFont = al_load_font("res/fonts/Roboto-thin.ttf", buttonFontSize, NULL); 

	//-----------------------------------------------------------------------------

	return 0;
}

// (!) De-allocate memory from allegro variables to avoid memory leak
int destroy()
{
	return 0;
}
