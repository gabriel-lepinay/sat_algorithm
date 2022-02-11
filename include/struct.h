/*
** EPITECH PROJECT, 2022
** header
** File description:
** header
*/
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

typedef struct hitbox_ci_s {
    coord_t center;
    int radius;
    sfCircleShape *circle;

} hitbox_ci_t;

#endif /*STRUCT_H_*/
