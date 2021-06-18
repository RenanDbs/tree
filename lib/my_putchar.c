/*
** EPITECH PROJECT, 2020
** 01my_putchar.c
** File description:
** .
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_errchar(char c)
{
    write(2, &c, 1);
}