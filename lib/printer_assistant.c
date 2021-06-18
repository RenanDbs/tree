/*
** EPITECH PROJECT, 2020
** numeric_printer.c
** File description:
** recode of the forbidden fruit ;)
*/

#include "../include/my.h"

int put_sign_before(lli count)
{
    if (count < 0) {
        my_putchar('-');
    } else {
        my_putchar('+');
    }
    return (0);
}