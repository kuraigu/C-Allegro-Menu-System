#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <fstream>
#include <time.h>

using namespace std;

#define gameTitle "Guerrilla Warfare"
#define gameVersion "v1.0a Pre-Alpha"
#define gameBuild "Build 200905162016"
#define gameWidth 1024
#define gameHeight 720 

/*
 * This class is the core of the game. 
 * The framework will be initialized here.
 * (!) Declare the values at the implementation file only
 */

#pragma once
// Used globally especially for initializing the framework
// Ex.
// game_system game; <- Object
// init();
class game_system
{
public:
	game_system(void);
	~game_system(void);

	ALLEGRO_DISPLAY *window;

	ALLEGRO_EVENT_QUEUE *evQueue;
	ALLEGRO_EVENT ev;

	ALLEGRO_TIMER *timer;

	bool done;
	bool redraw;

	float fps;

	int init();
	int destroy();
};

