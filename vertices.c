/*
** EPITECH PROJECT, 2022
** vertices.c
** File description:
** Source code
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int get_vertices()
{
    double vertix1_x = cx - size / 2;
    double vertix1_y = cy + size / 2;

    double vertix2_x = cx + size / 2;
    double vertix2_y = cy + size / 2;

    double vertix3_x = cx + size / 2;
    double vertix3_y = cy - size / 2;

    double vertix4_x = cx - size / 2;
    double vertix4_y = cy - size / 2;
}

int main(int ac, char **av)
{
    if (ac != 5) {
        printf("./a.out <x> <y> <size> <rotation>\n");
        return (84);
    }

    double cx = atof(av[1]);
    double cy = atof(av[2]);
    int size = atoi(av[3]);
    double rotation = (atof(av[4]) * -1) * (M_PI / 180);

    printf("cx: %.2f\ncy:%.2f\nsize: %i\nrotation (rad): %.2f\n", cx, cy, size, rotation);

// translate point to origin
    double tempX = vertix1_x - cx;
    double tempY = vertix1_y - cy;
    printf("(%.2f, %2f)\n", tempX, tempY);

// now apply rotation
    double rotatedX = tempX * cos(rotation) - tempY * sin(rotation);
    double rotatedY = tempX * sin(rotation) + tempY * cos(rotation);

// translate back
    vertix1_x = rotatedX + cx;
    vertix1_y = rotatedY + cy;

    printf("(%.2f, %.2f)\n", vertix1_x, vertix1_y);
    /* printf("Vertix 1: (%.2f, %.2f)\n", vertix1_x, vertix1_y); */
    return (0);
}
