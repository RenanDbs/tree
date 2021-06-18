/*
** EPITECH PROJECT, 2020
** 05my_putstr.c
** File description:
** .
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

void my_errchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_err_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_errchar(str[i]);
        i++;
    }
    return (0);
}