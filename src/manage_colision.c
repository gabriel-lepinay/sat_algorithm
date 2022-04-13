/*
** EPITECH PROJECT, 2022
** manage_colision
** File description:
** Source code to manage colision
*/
#include "manage_colision.h"
#include <unistd.h>

int sat_algorithm(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    load_normals(hitbox1, hitbox2);

    if (projection(hitbox1, hitbox2) == 0 ||
        projection(hitbox2, hitbox1) == 0)
        return (0);
    else
        return (1);
}

void manage_colision(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2, hitbox_ci_t *circle_hitbox)
{
    load_vertices(hitbox1, hitbox2);
    if (sat_algorithm(hitbox1, hitbox2) == 1) {
        sfRectangleShape_setOutlineColor(hitbox1->rectangle, sfGreen);
        sfRectangleShape_setOutlineColor(hitbox2->rectangle, sfGreen);
    // } else if (point_in_rec(circle_hitbox->center, hitbox2->vertices, hitbox2->size) == 1) {
    //     sfRectangleShape_setOutlineColor(hitbox2->rectangle, sfRed);
    //     sfCircleShape_setOutlineColor(circle_hitbox->circle, sfRed);
    } else {
        sfRectangleShape_setOutlineColor(hitbox1->rectangle, sfWhite);
        sfRectangleShape_setOutlineColor(hitbox2->rectangle, sfWhite);
        sfCircleShape_setOutlineColor(circle_hitbox->circle, sfWhite);
    }
}
