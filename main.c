/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

void directory_printer(char **table, char *test_path, int *flags, int i)
{
    DIR *folder = NULL;

    folder = opendir(test_path);
    if (folder != NULL) {
        if (flags[0] == 1) {
            check_dash_a(table, test_path, flags, i);
        } else if (table[i][0] != '.'){
            check_dash_a(table, test_path, flags, i);
        }
    }
    closedir(folder);
}

void print_controller(char **table, char *test_path, int *flags, int i)
{
    if (flags[1] == 1) {
        directory_printer(table, test_path, flags, i);
    } else {
        if (flags[0] == 1) {
            check_dash_a(table, test_path, flags, i);
        } else if (table[i][0] != '.') {
            check_dash_a(table, test_path, flags, i);
        }
    }
}

void print_tree(int *flags, char *path, char **table)
{
    char *test_path = NULL;

    for (int i = 0; table[i] != NULL; i++) {
        if (i == 0 && flags[6] == 0)
            my_printf(".\n");
        test_path = add_path(path, table[i]);
        if (flags[2] > flags[6]) {
            print_controller(table, test_path, flags, i);
        }
        recursive_caller(table, path, flags, i);
    }
    free(test_path);
}

int main(int ac, char **av)
{
    int *flags = malloc(sizeof(int) * 7);

    flags = check_flags(flags, ac, av);
    get_path("./", flags);
    my_printf("\n%i directories, %i files\n", flags[4], flags[5]);
    free(flags);
}