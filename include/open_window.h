/*
** EPITECH PROJECT, 2022
** open_window
** File description:
** Header
*/

#ifndef WIN_H_
    #define WIN_H_
    #include "struct.h"
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

void init_hitbox1(hitbox_sq_t *hitbox);
void init_hitbox2(hitbox_sq_t *hitbox);
void manage_colision(hitbox_sq_t *hitbox1, hitbox_sq_t *hitbox2);
#endif /*WIN_H_*/