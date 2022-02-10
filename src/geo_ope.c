*/*
** EPITECH PROJECT, 2022
** geo_ope
** File description:
** SOurce code of geometrical operation
*/
#include "geo_ope.h"

double dot_product(coord_t *vertix, vector_t *vector)
{
    double res = vertix->x * vector->x + vertix->y * vector->y;

    return (res);
}

vector_t *normalize_vector(vector_t *vector)
{
    double magnitude = sqrt(pow(vector->x, 2) + pow(vector->y, 2));

    vector->x /= magnitude;
    vector->y /= magnitude;
    return (vector);
}
