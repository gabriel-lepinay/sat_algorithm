/*
** EPITECH PROJECT, 2022
** vertices
** File description:
** Program to get vertices of a square
*/
#include "vertices.h"

coord_t **get_vertices_sq(coord_t center, int size)
{
    coord_t **vertices_list = malloc((4 + 1) * sizeof(coord_t));
    coord_t *vertix1 = malloc(sizeof(coord_t));
    coord_t *vertix2 = malloc(sizeof(coord_t));
    coord_t *vertix3 = malloc(sizeof(coord_t));
    coord_t *vertix4 = malloc(sizeof(coord_t));

    vertix1->x = center.x - size / 2;
    vertix1->y = center.y + size / 2;
    vertix2->x = center.x + size / 2;
    vertix2->y = center.y + size / 2;
    vertix3->x = center.x + size / 2;
    vertix3->y = center.y - size / 2;
    vertix4->x = center.x - size / 2;
    vertix4->y = center.y - size / 2;
    vertices_list[0] = vertix1;
    vertices_list[1] = vertix2;
    vertices_list[2] = vertix3;
    vertices_list[3] = vertix4;
    vertices_list[4] = NULL;
    return (vertices_list);
}

coord_t **get_rot_vertices_sq(coord_t center, double rotation, coord_t **vertices_list)
{
    double rotated_x;
    double rotated_y;
    double origin_x;
    double origin_y;

    rotation = (rotation * -1) * (M_PI / 180);
    for (int index = 0; vertices_list[index] != NULL; index++) {
        origin_x = vertices_list[index]->x - center.x;
        origin_y = vertices_list[index]->y - center.y;
        rotated_x = origin_x * cos(rotation) - origin_y * sin(rotation);
        rotated_y = origin_x * sin(rotation) + origin_y * cos(rotation);
        vertices_list[index]->x = rotated_x + center.x;
        vertices_list[index]->y = rotated_y + center.y;
    }
    return (vertices_list);
}

void load_vertices(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    hitbox1->vertices = get_rot_vertices_sq(hitbox1->center, hitbox1->rotation,
                        get_vertices_sq(hitbox1->center, hitbox1->size));
    hitbox2->vertices = get_rot_vertices_sq(hitbox2->center, hitbox2->rotation,
                        get_vertices_sq(hitbox2->center, hitbox2->size));


}
