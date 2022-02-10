/*
** EPITECH PROJECT, 2022
** main
** File description:
** header
*/
#ifndef PROJ_H_
    #define PROJ_H_
    #include "struct.h"
    #include <stdlib.h>

double dot_product(coord_t *vertix, vector_t *vector);
#endif /*PROJ_H_*/


#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics.h>

typedef struct coord_s {
    double x;
    double y;

} coord_t;

typedef struct vector_s {
    double x;
    double y;

} vector_t;

typedef struct hitbox_sq_s {
    coord_t center;
    int size;
    double rotation;
    coord_t **vertices;
    vector_t **normals;
    sfRectangleShape *rectangle;

} hitbox_sq_t;

#endif /*STRUCT_H_*/
