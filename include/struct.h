/*
** EPITECH PROJECT, 2022
** struct
** File description:
** header
*/
#include <SFML/Graphics.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct coord_s {
    double x;
    double y;

} coord_t;

typedef struct vector_s {
    double x;
    double y;

} vector_s;

typedef struct hitbox_sq_s {
    coord_t center;
    int size;
    double rotation;
    coord_t **vertices;
    coord_t **normal;
    sfRectangleShape *rectangle;

} hitbox_sq_t;

#endif /*STRUCT_H_*/
