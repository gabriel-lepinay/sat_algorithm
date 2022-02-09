/*
** EPITECH PROJECT, 2022
** create_shape
** File description:
** Source code to create the shape to test
*/
#include "create_shape.h"

sfRectangleShape *create_square(int x, int y, int size, double rotation)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfColor transparent = {0, 0, 0, 0};
    sfVector2f position = {x, y};
    sfVector2f origin = {size / 2, size / 2};
    sfVector2f len = {size, size};

    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setRotation(rectangle, rotation);
    sfRectangleShape_setOrigin(rectangle, origin);
    sfRectangleShape_setFillColor(rectangle, transparent);
    sfRectangleShape_setSize(rectangle, len);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    return (rectangle);
}

void init_hitbox1(hitbox_sq_t *hitbox)
{
    hitbox->center.x = 300;
    hitbox->center.y = 300;
    hitbox->size = 50;
    hitbox->rotation = 60;
    hitbox->rectangle = create_square(hitbox->center.x, hitbox->center.y, hitbox->size, hitbox->rotation);
}

void init_hitbox2(hitbox_sq_t *hitbox)
{
    hitbox->center.x = 760;
    hitbox->center.y = 540;
    hitbox->size = 50;
    hitbox->rotation = 0;
    hitbox->rectangle = create_square(hitbox->center.x, hitbox->center.y, hitbox->size, hitbox->rotation);
}
