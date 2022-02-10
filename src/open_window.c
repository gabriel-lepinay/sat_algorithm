/*
** EPITECH PROJECT, 2022
** open_window
** File description:
** Source code to open a window
*/
#include "open_window.h"

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, "SAT algorithm test", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void event_handling(sfRenderWindow *window, hitbox_sq_t *hitbox)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            hitbox->center.y -= 10;
            sfRectangleShape_setPosition(hitbox->rectangle, (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            hitbox->center.y += 10;
            sfRectangleShape_setPosition(hitbox->rectangle, (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            hitbox->center.x -= 10;
            sfRectangleShape_setPosition(hitbox->rectangle, (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            hitbox->center.x += 10;
            sfRectangleShape_setPosition(hitbox->rectangle, (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
    }
}

void open_window(int width, int height)
{
    sfRenderWindow *window;
    hitbox_sq_t static_hitbox;
    hitbox_sq_t moving_hitbox;

    init_hitbox1(&moving_hitbox);
    init_hitbox2(&static_hitbox);
    create_window(&window, width, height);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        event_handling(window, &moving_hitbox);
        manage_colision(&static_hitbox, &moving_hitbox);
        sfRenderWindow_drawRectangleShape(window, moving_hitbox.rectangle, NULL);
        sfRenderWindow_drawRectangleShape(window, static_hitbox.rectangle, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
