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

typedef unsigned int ui;

typedef long long int lli;

int my_modified_strcmp(char const *s1, char const *s2);

void my_putchar(char c);

void my_errchar(char c);

int my_putstr(char const *str);

int my_put_oct(lli count);

int my_put_hex(lli count);

int my_put_hex_up(lli count);

int my_put_bin(lli count);

int my_put_adress(lli count);

int put_sign_before(lli count);

int my_put_nbr(int nb);

int my_strlen(char *str);

void print_tree(int last, int *flags, char *path, char **table);