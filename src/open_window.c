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

    *window = sfRenderWindow_create(mode, "SAT algorithm", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void event_handling(sfRenderWindow *window, hitbox_sq_t *hitbox)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            hitbox->center.y -= 5;
            sfRectangleShape_setPosition(hitbox->rectangle,
            (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            hitbox->center.y += 5;
            sfRectangleShape_setPosition(hitbox->rectangle,
            (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            hitbox->center.x -= 5;
            sfRectangleShape_setPosition(hitbox->rectangle,
            (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            hitbox->center.x += 5;
            sfRectangleShape_setPosition(hitbox->rectangle,
            (sfVector2f){hitbox->center.x, hitbox->center.y});
        }
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            hitbox->rotation += 5;
            sfRectangleShape_setRotation(hitbox->rectangle, hitbox->rotation);
        }
    }
}

void my_display_vertices(sfRenderWindow *window, hitbox_sq_t hitbox)
{
    for (int index = 0; index < 4; index++) {
        sfCircleShape *circle = sfCircleShape_create();
        sfVector2f pos;

        pos.x = hitbox.vertices[index]->x;
        pos.y = hitbox.vertices[index]->y;

        sfCircleShape_setPosition(circle, pos);
        sfCircleShape_setRadius(circle, 3);
        sfCircleShape_setFillColor(circle, sfRed);
        sfCircleShape_setOutlineThickness(circle, 0);
        sfRenderWindow_drawCircleShape(window, circle, sfFalse);       
    }
}

void open_window(int width, int height)
{
    sfRenderWindow *window;
    hitbox_sq_t static_hitbox;
    hitbox_sq_t moving_hitbox;
    hitbox_ci_t circle_hitbox;
    sfText *text = init_text();

    init_hitbox1(&moving_hitbox);
    init_hitbox2(&static_hitbox);
    init_hitbox_ci(&circle_hitbox);
    create_window(&window, width, height);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        event_handling(window, &moving_hitbox);
        manage_colision(&static_hitbox, &moving_hitbox, &circle_hitbox);
        sfRenderWindow_drawRectangleShape(window, moving_hitbox.rectangle, NULL);
        sfRenderWindow_drawRectangleShape(window, static_hitbox.rectangle, NULL);
        // sfRenderWindow_drawCircleShape(window, circle_hitbox.circle, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        // my_display_vertices(window, moving_hitbox);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
