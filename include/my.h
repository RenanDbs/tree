/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h> 

typedef struct info
{
    int *pos_folder;
} info ;

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);