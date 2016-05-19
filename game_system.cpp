#include "game_system.h"


game_system::game_system(void)
{
}


game_system::~game_system(void)
{
}

// (!) Initialize the game framework and addons
// Allegro Variables and native variables globally needed are
// iniitalized here
int game_system::init()
{
	// default values
	done = false;
	fps  = 60;

	if(!al_init())
	{
		al_show_native_message_box(window, gameTitle, "Error", "The framework was not initialized properly \n Please Restart", NULL, ALLEGRO_MESSAGEBOX_ERROR);		
		return -1;
	}

	// addons
	al_init_image_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	// modules
	al_install_audio();
	al_install_mouse();
	al_install_keyboard();

	window = al_create_display(gameWidth, gameHeight);
	al_set_window_title(window, gameTitle);

	if(!window)
	{
		al_show_native_message_box(window, gameTitle, "Error", "Failed to render window \n Please Restart", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	// input queue
	evQueue = al_create_event_queue();
	al_register_event_source(evQueue, al_get_display_event_source(window));
	al_register_event_source(evQueue, al_get_mouse_event_source());
	al_register_event_source(evQueue, al_get_keyboard_event_source());

	// fps regulation
	timer = al_create_timer(1 / fps);
	al_register_event_source(evQueue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	return 0;
}

// (!) De-allocate the memory from the allegro variables
// This will avoid memory leak
int game_system::destroy()
{
	al_destroy_display(window);
	al_destroy_event_queue(evQueue);
	al_destroy_timer(timer);

	return 0;
}

