/*
** EPITECH PROJECT, 2022
** point_in_rec
** File description:
** Source code to know if a point is in a rectangle
*/
#include "point_in_rec.h"

int point_in_rec(coord_t point, coord_t **vertices, int size)
{
    double area1 = fabs((vertices[1]->x * vertices[0]->y - vertices[0]->x * vertices[1]->y)
                       + (point.x * vertices[1]->y - vertices[1]->x * point.y)
                       + (vertices[0]->x * point.y - point.x * vertices[0]->y)) / 2;
    double area2 = fabs((vertices[2]->x * vertices[1]->y - vertices[1]->x * vertices[2]->y)
                       + (point.x * vertices[2]->y - vertices[2]->x * point.y)
                       + (vertices[1]->x * point.y - point.x * vertices[1]->y)) / 2;
    double area3 = fabs((vertices[3]->x * vertices[2]->y - vertices[2]->x * vertices[3]->y)
                       + (point.x * vertices[3]->y - vertices[3]->x * point.y)
                       + (vertices[2]->x * point.y - point.x * vertices[2]->y)) / 2;
    double area4 = fabs((vertices[3]->x * vertices[0]->y - vertices[0]->x * vertices[3]->y)
                       + (point.x * vertices[3]->y - vertices[3]->x * point.y)
                       + (vertices[0]->x * point.y - point.x * vertices[0]->y)) / 2;
    double rec_area = pow(size, 2);

    if (area1 + area2 + area3 + area4 > rec_area)
        return(0);
    return(1);
}
