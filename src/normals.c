/*
** EPITECH PROJECT, 2022
** normals
** File description:
** Source code to get the normals of a shape
*/
#include "normals.h"

vector_t **init_vectors(coord_t **vertices)
{
    vector_t **vector_list = malloc((4 + 1) * sizeof(vector_t));
    vector_t *vector1 = malloc(sizeof(vector_t));
    vector_t *vector2 = malloc(sizeof(vector_t));
    vector_t *vector3 = malloc(sizeof(vector_t));
    vector_t *vector4 = malloc(sizeof(vector_t));

    vector1->x = vertices[1]->x - vertices[0]->x;
    vector1->y = vertices[1]->y - vertices[0]->y;
    vector2->x = vertices[2]->x - vertices[1]->x;
    vector2->y = vertices[2]->y - vertices[1]->y;
    vector3->x = vertices[3]->x - vertices[2]->x;
    vector3->y = vertices[3]->y - vertices[2]->y;
    vector4->x = vertices[0]->x - vertices[3]->x;
    vector4->y = vertices[0]->y - vertices[3]->y;
    vector_list[0] = vector1;
    vector_list[1] = vector2;
    vector_list[2] = vector3;
    vector_list[3] = vector4;
    vector_list[4] = NULL;
    return (vector_list);
}

vector_t **init_normals(vector_t **vector_list)
{
    vector_t **normals_list = malloc((4 + 1) * sizeof(vector_t));
    vector_t *normals1 = malloc(sizeof(vector_t));
    vector_t *normals2 = malloc(sizeof(vector_t));
    vector_t *normals3 = malloc(sizeof(vector_t));
    vector_t *normals4 = malloc(sizeof(vector_t));

    normals1->x = vector_list[0]->y * - 1;
    normals1->y = vector_list[0]->x;
    normals2->x = vector_list[1]->y * - 1;
    normals2->y = vector_list[1]->x;
    normals3->x = vector_list[2]->y * - 1;
    normals3->y = vector_list[2]->x;
    normals4->x = vector_list[3]->y * - 1;
    normals4->y = vector_list[3]->x;
    normals_list[0] = normalize_vector(normals1);
    normals_list[1] = normalize_vector(normals2);
    normals_list[2] = normalize_vector(normals3);
    normals_list[3] = normalize_vector(normals4);
    normals_list[4] = NULL;
    return (normals_list);
}

void load_normals(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2)
{
    vector_t **vector_list1 = init_vectors(hitbox1->vertices);
    vector_t **vector_list2 = init_vectors(hitbox2->vertices);

    hitbox1->normals = init_normals(vector_list1);
    hitbox2->normals = init_normals(vector_list2);
}
