/*
** EPITECH PROJECT, 2022
** manage_colision
** File description:
** Source code to manage colision
*/
#include "manage_colision.h"

coord_t **get_vertices_sq(coord_t center, int size, float rotation)
{
    coord_t vertex1;
    coord_t vertex2;
    coord_t vertex3;
    coord_t vertex4;
    coord_t *vertices_tab[5];
    double x = center.x * cos(rotation) - center.y * sin(rotation);
    double y = center.x * sin(rotation) + center.y * cos(rotation);

    vertices_tab[0] = {center.x + 1/2*size()};/
    vertices_tab[1] = ;
    vertices_tab[2] = ;
    vertices_tab[3] = ;
    vertices_tab[4] = NULL;
    return (vertices_tab);
}

int sat_algorithm(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    hitbox1->vertices = get_vertices_sq(hitbox1->center, hitbox1->size, hitbox1->);
    hitbox1->vertices = get_vertices_sq(hitbox2->center, hitbox2->size, hitbox2->);
}

void manage_colision(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    if (sat_algorithm(hitbox1, hitbox2) == 1) {
        sfRectangleShape_setOutlineColor(hitbox1->rectangle, sfGreen);
        sfRectangleShape_setOutlineColor(hitbox2->rectangle, sfGreen);
    } else {
        sfRectangleShape_setOutlineColor(hitbox1->rectangle, sfWhite);
        sfRectangleShape_setOutlineColor(hitbox2->rectangle, sfWhite);
    }
}
