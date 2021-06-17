/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

int cont_files(void)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir("./");
    while ( (entry = readdir(folder)) )
    {
        files++;
    }
    closedir(folder);
    return (files);
}

char **sort_table(char **table, int nb_files)
{
    char *tmp = malloc(sizeof(char) * 100);

    for (int i = 1; i < nb_files; i++)
        for (int j = 0; j < nb_files - i; j++) {
            if (strcmp(table[i], table[i + 1]) > 0) {
                tmp = strdup(table[i]);
                printf("BEFORE = %s\n", table[i]);
                table[i] = strdup(table[i + 1]);
                table[i] = strdup(tmp);
                printf("AFTER= %s\n", table[i]);
            }
        }
    return (table);
}

int get_path(char **table, int i, char *str)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    int nb_folders = 0;

    folder = opendir(str);
    while ( (entry = readdir(folder)) )
    { 
        table[i] = strdup(entry->d_name);
        if (entry->d_type == DT_DIR && (table[i][1] != '\0' && table[i][0] != '.')) {
            i++;
            str = strdup(entry->d_name);
            get_path(table, i, str);
            nb_folders++;
        }
        i++;
    }
    closedir(folder);
    return (nb_folders);
}

int main()
{
    int nb_files = cont_files();
    int nb_folders = 0;
    int i = 0;
    char *str = "./";
    char **table = malloc(sizeof(char *) * 50);

    nb_folders = get_path(table, i, str);
    table  = sort_table(table, nb_files);
    for(int i = 0; i < nb_files; i++)
        printf("TABLE[%d] = %s\n", i, table[i]);
}