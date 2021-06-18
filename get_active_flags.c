/*
** EPITECH PROJECT, 2021
** tree
** File description:
** get_active_flags
*/

#include "./include/my.h"

int *check_flags(int *flagarray, int ac, char **av)
{
    if (ac == 0)
        return (0);
    for (int a = 0; a < 7; a++) {
        flagarray[a] = 0;
    }
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-a") == 0)
            flagarray[0] = 1;
        if (my_strcmp(av[i], "-d") == 0)
            flagarray[1] = 1;
        if (my_strcmp(av[i], "-L") == 0)
            flagarray[2] = my_getnbr(av[i]);
        if (my_strcmp(av[i], "-f") == 0)
            flagarray[3] = 1;
    }
    if (flagarray[2] == 0)
        flagarray[2] = INT_MAX;
    return flagarray;
}

char *str_cp2(char **str)
{
    char *cp = malloc(sizeof(char) * my_strlen(*str));

    if (cp == NULL)
        return (NULL);
    cp[my_strlen(*str) - 1] = '\0';
    for (int i = 0; (*str)[i + 1] != '\0'; i++)
        cp[i] = (*str)[i];
    return (cp);
}