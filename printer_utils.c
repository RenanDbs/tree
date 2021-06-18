/*
** EPITECH PROJECT, 2021
** tree
** File description:
** printer_utils
*/

#include "./include/my.h"


void recursive_caller(char **table, char *path, int *flags, int i)
{
    char *test_path = add_path(path, table[i]);
    DIR *folder = NULL;
    
    folder = opendir(test_path);
    if (folder != NULL && !str_compare(table[i], ".") && \
    !str_compare(table[i], "..")) {
        flags[6] += 1;
        if (((flags[0] == 1) || (table[i][0] != '.' && flags[0] == 0)) && \
        flags[2] > flags[6]) {
            flags[4] += 1;
            get_path(test_path, flags);
        }
        flags[6] -= 1;
    } else if (folder == NULL)
        flags[5] += 1;
    closedir(folder);
}

void check_dash_a(char **table, char *test_path, int *flags, int i)
{
    if (flags[3] == 1) {
        print_tree_path(table, test_path, flags, i);
    } else {
        print_tree_entry(table, flags, i);
    }
}

void print_tree_entry(char **table, int *flags, int i)
{
    if (!str_compare(table[i], ".") && !str_compare(table[i], "..")) {
        for (int c = 0; c < flags[6]; c++)
            my_printf("%s", "|   ");
        if (table[i + 1] == NULL)
            my_printf("`-- ");
        else
            my_printf("%s", "|-- ");
        my_printf("%s\n", table[i]);
    }
}

void print_tree_path(char **table, char *test_path, int *flags, int i)
{
    char *path_cp = NULL;

    if (!str_compare(table[i], ".") && !str_compare(table[i], "..")) {
        for (int x = 0; x < flags[6]; x++)
            my_printf("%s", "|   ");
        if (table[i + 1] == NULL)
            my_printf("`-- ");
        else
            my_printf("%s", "|-- ");
        path_cp = str_cp2(&test_path);
        my_printf("%s\n", path_cp);
        free(path_cp);
    }
}