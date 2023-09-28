#include "Emulator.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>

int i, j;
int done = 0;

void controlUpdate(int keycode, int dir)
{
	//Keys = ([7]0) ([6]0) ([5]back) ([4]select) ([3]up) ([2]down) ([1]left) ([0]right)
	switch (keycode)
	{
		case(ALLEGRO_KEY_W):
		case(ALLEGRO_KEY_UP):
			Keys ^= dir << 3;
			break;
		case(ALLEGRO_KEY_S):
		case(ALLEGRO_KEY_DOWN):
			Keys ^= dir << 2;
			break;
		case(ALLEGRO_KEY_A):
		case(ALLEGRO_KEY_LEFT):
			Keys ^= dir << 1;
			break;
		case(ALLEGRO_KEY_D):
		case(ALLEGRO_KEY_RIGHT):
			Keys ^= dir;
			break;
		case(ALLEGRO_KEY_SPACE):
		case(ALLEGRO_KEY_ENTER):
			Keys ^= dir << 4;
			break;
		case(ALLEGRO_KEY_ESCAPE):
		case(ALLEGRO_KEY_LCTRL):
			Keys ^= dir << 5;
			break;
	}
}

void transformBuffer()
{
	for (i = 0; i < DISPLAY_W; i++)
	{
		for (j = 0; j < DISPLAY_H; j++)
		{
			al_draw_filled_rectangle(i*DISPLAY_COEFICIENT, j*DISPLAY_COEFICIENT,
									 (i + 1)*DISPLAY_COEFICIENT, (j + 1)*DISPLAY_COEFICIENT,
									 al_map_rgb(((Buffer[j][i] & 0b100) >> 2) * 255,
												((Buffer[j][i] & 0b010) >> 1) * 255,
												((Buffer[j][i] & 0b001) >> 0) * 255));
		}
	}
}

void updateKeys()
{
	KeysDown = (~lastKeys & Keys);
	KeysUp = (lastKeys & ~Keys);
	lastKeys = Keys;
}

void mainLoop()
{
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY* display = al_create_display(DISPLAY_W*DISPLAY_COEFICIENT,
                                DISPLAY_H*DISPLAY_COEFICIENT);
    ALLEGRO_EVENT_QUEUE * eventQueue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT event;

    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    int canDraw = 0;
    Keys = 0;

    Buffer = malloc(sizeof(char*)*DISPLAY_W);
    for (i = 0; i < DISPLAY_W; i++) {
        Buffer[i] = malloc(sizeof(char)*DISPLAY_H);
    }

    al_start_timer(timer);

	start();
	srand(time(NULL));
    while(!done)
    {
        al_wait_for_event(eventQueue, &event);
        switch (event.type)
        {
        case(ALLEGRO_EVENT_TIMER):
			updateKeys();
			(*mainUpd)();
            canDraw = true;
            break;
        case(ALLEGRO_EVENT_KEY_DOWN):
            controlUpdate(event.keyboard.keycode, 1);
            printf("Key : %d\n", Keys);
            break;
        case(ALLEGRO_EVENT_KEY_UP):
            controlUpdate(event.keyboard.keycode, 1);
            printf("Key : %d\n", Keys);
            break;
        case(ALLEGRO_EVENT_DISPLAY_CLOSE):
            done = true;
            break;
        default:
            break;
        }

        if(canDraw)
        {
			(*mainDraw)();
			transformBuffer();
            al_flip_display();
            canDraw = false;
        }
    }

	for (i = 0; i < DISPLAY_W; i++) free(Buffer[i]);
	free(Buffer);
}

void drawBack(byte color)
{
	for (i = 0; i < DISPLAY_W; i++)
		for (j = 0; j < DISPLAY_H; j++)
			Buffer[j][i] = color;
}

void quit()
{
	done = 1;
}

long random(long min, long max)
{
	return rand() % (max - min) + min;
}
