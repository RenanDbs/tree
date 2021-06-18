/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h> 
#include <stdarg.h>
#include <limits.h>

typedef unsigned int ui;

typedef long long int lli;

typedef struct info
{
    int *pos_folder;
} info ;

char *my_strcpy(char *dest, char const *src);

int my_modified_strcmp(char const *s1, char const *s2);

void my_putchar(char c);

void my_errchar(char c);

int my_putstr(char const *str);

int my_err_str(char const *str);

int my_put_oct(lli count);

int my_put_hex(lli count);

int my_put_hex_up(lli count);

int my_put_bin(lli count);

int my_put_adress(lli count);

int put_sign_before(lli count);

int my_put_nbr(int nb);

int my_strlen(char *str);

int my_getnbr(char const *str);

void print_tree(int *flags, char *path, char **table);

int my_strcmp(char const *s1, char const *s2);

int my_printf(const char *format, ...);

int *check_flags(int *flagarray, int ac, char **av);

int str_compare(char *str1, char *str2);

int cont_files(char *path);

char *add_path(char *str, char *path);

char **sort_table(char **table);

char big_letter(char c);

char *str_cp2(char **str);

int str_compare2(char *str1, char *str2);

char *my_strdup(char *str);

void get_path(char *path, int *flags);

void print_tree_path(char **table, char *test_path, int *flags, int i);

void print_tree_entry(char **table, int *flags, int i);

void print_controller(char **table, char *test_path, int *flags, int i);

void check_dash_a(char **table, char *test_path, int *flags, int i);

void recursive_caller(char **table, char *path, int *flags, int i);