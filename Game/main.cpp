#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\joystick.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\keyboard.h>
#include <allegro5\config.h>

#include "TestObject.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "Sprite.h"

#include <string>
#include <list>
#include <algorithm>

int main(int argc, char* argv [])
{
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();

	ALLEGRO_CONFIG *configFile = al_load_config_file("data/config/config.ini");
	if (configFile == NULL)
	{
		al_show_native_message_box(NULL, "A fatal error has ocurred!",
			"The configuration file has not been found!", 
			"Be sure to always have a valid conf.ini in /data/config/ for the program to work...", "Understood", ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	const char *dispW = al_get_config_value(configFile, "DISPLAY", "RESX");
	const char *dispH = al_get_config_value(configFile, "DISPLAY", "RESY");
	const char *fullscreenMode = al_get_config_value(configFile, "DISPLAY", "FULLSCREEN");

	int iDispW = atoi(dispW);
	int iDispH = atoi(dispH);
	bool bfullscreenMode = atoi(fullscreenMode);

	assert(iDispW < 5000 && iDispW > 0);
	assert(iDispH < 5000 && iDispH > 0);

	if (bfullscreenMode == true)
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	ALLEGRO_DISPLAY *display = al_create_display(atoi(dispW), atoi(dispH));
	if (display == NULL)
	{
		al_show_native_message_box(NULL, "A fatal error has ocurred!",
			"Display creation failed!",
			"The resolution selected is not supported by your screen/video card...", "Understood", ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

    al_clear_to_color(al_map_rgb(255, 0, 0));
    al_flip_display();

    bool done = false;
    bool redraw = false;

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    //**********************
    ALLEGRO_BITMAP *test = al_load_bitmap("data/background.png");

    int x = 320, y = 240;

	Vec2D size(40.0f, 40.0f);

	TestObject gameObject(Vec2D(10.0f, 10.0f));
	gameObject.AddComponent(new RenderComponent());

	Sprite testSprite = Sprite(size);
    //*********************

    al_start_timer(timer);

	//newManager.AddComponent(new PhysicsComponent(Vec2D(), Vec2D(), Vec2D(5.0f, 10.0f), false));

    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);

        switch (ev.type)
        {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    done = true;
                }
                //************
                else
                {
					// NOTHING
                }
                //************
                break;
            default:
                break;
        }

        if (redraw && al_is_event_queue_empty(queue))
        {
            redraw = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(test, 0, 0, NULL);

			//PhysicsComponent *test = (PhysicsComponent*) newManager.GetComponentByType(COMP_PHYSICS);
			//Vec2D pos = test->GetPosition();

            al_draw_filled_circle(x, y, 89, al_map_rgb(255, 0, 255));

			al_draw_bitmap(testSprite.GetSprite(), 30, 30, NULL);
            al_flip_display();
        }
    }

	al_destroy_config(configFile);
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}