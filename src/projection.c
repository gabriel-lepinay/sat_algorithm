/*
** EPITECH PROJECT, 2022
** project
** File description:
** Source code of the projection of a vertix onto a vector
*/
#include "projection.h"

double **malloc_map_int(int nb_rows, int nb_cols)
{
    double **arr;
    int row;

    arr = malloc((nb_rows + 1) * sizeof(double *));
    for (row = 0; row < nb_rows; row++) {
        arr[row] = malloc(nb_cols * sizeof(double));
    }
    arr[nb_rows] = NULL;
    return (arr);
}

double find_biggest(double *list)
{
    double biggest = list[0];

        for (int number = 0; number < 4; number++) {
            if (list[number] > biggest)
                biggest = list[number];
        }
    return (biggest);
}

double find_smallest(double *list)
{
    double smallest = list[0];

        for (int number = 0; number < 4; number++) {
            if (list[number] < smallest)
                smallest = list[number];
        }
    return (smallest);
}

int is_a_gap(double *dot_p1, double *dot_p2)
{
    double biggest1 = find_biggest(dot_p1);
    double smallest1 = find_smallest(dot_p1);
    double biggest2 = find_biggest(dot_p2);
    double smallest2 = find_smallest(dot_p2);

    if ((smallest1 < biggest2 && smallest1 > smallest2) ||
        (smallest2 < biggest1 && smallest2 > smallest1))
        return (1);
    return (0);
}

int projection(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    double **proj_tab1 = malloc_map_int(4, 4);
    double **proj_tab2 = malloc_map_int(4, 4);


    for (int norm_i = 0; hitbox1->normals[norm_i] != NULL; norm_i++) {
        for (int vert_i = 0; hitbox1->vertices[vert_i] != NULL; vert_i++) {
            proj_tab1[norm_i][vert_i] = dot_product(hitbox1->vertices[vert_i],
                                                    hitbox1->normals[norm_i]);
            proj_tab2[norm_i][vert_i] = dot_product(hitbox2->vertices[vert_i],
                                                    hitbox1->normals[norm_i]);
        }
        if (is_a_gap(proj_tab1[norm_i], proj_tab2[norm_i]) == 0)
            return (0);
    }
    return (1);
}
