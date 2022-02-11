/*
** EPITECH PROJECT, 2022
** manage_colision
** File description:
** Header
*/
#ifndef COL_H_
    #define COL_H_
    #include "struct.h"
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>

void load_normals(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2);
void load_vertices(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2);
int projection(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2);
int point_in_rec(coord_t point, coord_t **vertices, int size);
#endif /*COL_H_*/
