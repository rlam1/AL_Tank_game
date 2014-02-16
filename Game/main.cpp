#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\keyboard.h>
#include <string>

#ifdef _DEBUG
#include <iostream>
#endif

int main(int argc, char* argv [])
{
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *display = al_create_display(640, 480);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    bool done = false;

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);

        switch (ev.type)
        {
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
#ifdef _DEBUG
                    char key_id[33];
                    _itoa_s(ev.keyboard.keycode, key_id, 10);
                    std::cout << key_id << " pressed" << std::endl;
#endif
                }
                break;
            case ALLEGRO_EVENT_TIMER:
                al_clear_to_color(al_map_rgb(255,255,0));
                al_flip_display();
                break;
            default:
                break;
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}