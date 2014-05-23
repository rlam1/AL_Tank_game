#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\joystick.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\keyboard.h>
#include <string>

#include "Game.h"
#include "Input.h"

#include "Gwen/Gwen.h"
#include "Gwen/Skins/Simple.h"
#include "Gwen/Skins/TexturedBase.h"
#include "Gwen/Input/Allegro.h"
#include "Gwen/Renderers/Allegro.h"

#include "Debug.h"

int main(int argc, char* argv [])
{
    Debug_ *deb = new Debug_("logfile.txt");

    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();

    ALLEGRO_DISPLAY *display = al_create_display(640, 480);

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
    char ch_test_[33];
    _itoa_s((int) test, ch_test_, 16);
    deb->log_("Image HEX =", ch_test_);

    int x = 320, y = 240;

    Game *game = new Game(deb);
    //*********************

    al_start_timer(timer);

    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);

        switch (ev.type)
        {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                game->update();
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    done = true;
                }
                else
                {
                    game->procInput(true, ev.keyboard.keycode);
                }
                break;
            case ALLEGRO_EVENT_KEY_UP:
                game->procInput(false, ev.keyboard.keycode);
                break;
            default:
                break;
        }

        if (redraw && al_is_event_queue_empty(queue))
        {
            redraw = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(test, 0, 0, NULL);

            al_draw_filled_circle(x, 240, 89, al_map_rgb(255, 0, 255));
            al_flip_display();
        }
    }

    delete deb;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}