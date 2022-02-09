/*
** EPITECH PROJECT, 2022
** vertices.c
** File description:
** Source code
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 5) {
        printf("./a.out <x> <y> <size> <rotation>\n");
        return (84);
    }
    double cx = atof(av[0]);
    double cy = atof(av[1]);
    int size = atoi(av[2]);
    double rotation = atof(av[2]);

    double vertix1_x = cx - size / 2;
    double vertix1_y = cy + size / 2;

    double temp_x = vertix1_x - cx;
    double temp_y = vertix1_y - cy;

    /* double vertix2_x = x + size / 2; */
    /* double vertix2_y = y + size / 2; */

    /* double vertix3_x = x + size / 2; */
    /* double vertix3_y = y - size / 2; */

    /* double vertix4_x = x - size / 2; */
    /* double vertix4_y = y - size / 2; */

    double rotate_x = temp_x * cos(rotation) - temp_y * sin(rotation);
    double rotate_y = temp_x * sin(rotation) + temp_y * cos(rotation);

    vertix1_x = rotate_x + cx;
    vertix1_y = rotate_y + cy;

    printf("Vertix 1: (%2.f, %2.f)\n", vertix1_x, vertix1_y);
    /* printf("Vertix 2: (%2.f, %2.f)\n", vertix2_x, vertix2_y); */
    /* printf("Vertix 3: (%2.f, %2.f)\n", vertix3_x, vertix3_y); */
    /* printf("Vertix 4: (%2.f, %2.f)\n", vertix4_x, vertix4_y); */
    return (0);
}
