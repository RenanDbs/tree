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
                // printf("BEFORE = %s\n", table[i]);
                table[i] = strdup(table[i + 1]);
                table[i] = strdup(tmp);
                // printf("AFTER= %s\n", table[i]);
            }
        }
    return (table);
}

int my_strlen(char *str)
{
    int returned = 0;

    for (int i = 0; str[i] != '\0'; i++)
        returned++;
    return (returned);
}

char *add_path(char *str, char *path)
{
    char *returned = malloc(sizeof(char) * (my_strlen(str) + my_strlen(path) + 2));
    int pos = 0;
    int j = 0;

    printf("%s %s\n", str, path);
    for (int i = pos; str[i] != '\0'; i++, pos++)
        returned[i] = str[i];
    printf("pos: %i\n", pos);
    for (int i = pos; path[j] != '\0'; i++, pos++, j++) {
        returned[i] = path[i - my_strlen(str)];
        printf("passed %c %c\n", path[i - my_strlen(str) - 1], returned[i]);
        printf("+%s+\n", returned);
    }
    printf("pos2: %i\n", pos);
    for (int i = 0; returned[i] != '\0'; i++)
        printf("%c", returned[i]);
    returned[pos] = '/';
    returned[pos + 1] = '\0';
    return (returned);
}

void get_path(int depth, char *str)
{
    int nb_files = cont_files();
    char **table = malloc(sizeof(char *) * (nb_files + 1));
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    int i = 0;
    struct stat *buf = NULL;

    table[nb_files] = NULL;
    folder = opendir(str);
    printf("%s\n", str);
    while ( (entry = readdir(folder)) )
    { 
        table[i] = strdup(entry->d_name);
        printf("%i %s\n", i, entry->d_name);
        // if (entry->d_type == DT_DIR && (table[*i][1] != '\0' && table[*i][0] != '.')) {
        //     *i += 1;
        //     str = strdup(entry->d_name);
        //     get_path(table, i, str);
        //     nb_folders++;
        // } else
        i += 1;
    }
    // table  = sort_table(table, nb_files);
    for (int i = 0; table[i] != NULL; i++) {
        printf("%s %i\n", table[i], depth);
        buf = malloc(sizeof(struct stat));
        stat(table[i], buf);
        if (((buf->st_mode & S_IFMT) == S_IFDIR) && (table[i][1] != '\0' && table[i][0] != '.')) {
            str = add_path(str, table[i]);
            printf("%s\n", str);
            get_path(depth + 1, str);
        }
        free(buf);
    }
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
    closedir(folder);
}

int main()
{
    int nb_files = cont_files();
    int nb_folders = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 3);
    char **table = malloc(sizeof(char *) * 50);

    str[0] = '.';
    str[1] = '/';
    str[2] = '\0';
    get_path(0, str);
    // table  = sort_table(table, nb_files);
    // for(int i = 0; i < nb_files; i++)
    //     printf("TABLE[%d] = %s\n", i, table[i]);
}