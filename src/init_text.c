/*
** EPITECH PROJECT, 2022
** init_text
** File description:
** Source code to initialize text
*/

#include "init_text.h"

sfText *init_text(void)
{
    sfText *text = sfText_create();
    sfVector2f pos = {10, 10};
    sfFont *font = sfFont_createFromFile("asset/font/DeterminationMonoWebRegular-Z5oq.ttf");

    sfText_setString(text, "Movements:\nright: <right arrow>\nleft: <left arrow>\nup: <up arrow>\ndown: <down arrow>\nrotate: <r>");
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setRotation(text, 0);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlue);
    sfText_setOutlineThickness(text, 1.5);
    sfText_setLineSpacing(text, 1.5);
    sfText_setLetterSpacing(text, 0.8);
    return (text);
}