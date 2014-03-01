#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\keyboard.h>
#include <string>

#include "Game.h"

#ifdef _DEBUG
#include "Debug.h"
#endif

int main(int argc, char* argv [])
{
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();

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

#ifdef _DEBUG
    Debug_ deb;
#endif

    //**********************
    ALLEGRO_BITMAP *test = al_load_bitmap("data/background.png");
#ifdef _DEBUG
    char ch_test_[33];
    _itoa_s((int) test, ch_test_, 16);
    deb.log_("Image HEX =", ch_test_);
#endif

    int x = 320, y = 240;
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
                    switch (ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_LEFT:
                            x--;
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            x++;
                            break;
                        default:
#ifdef _DEBUG
                            deb.log_("Invalid input", deb.intToStr(ev.keyboard.keycode));
#endif
                    }
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

            al_draw_filled_circle(x, 240, 89, al_map_rgb(255, 0, 255));
            al_flip_display();
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}