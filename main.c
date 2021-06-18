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

int get_path(info *infos, char **table, int i, int j, char *str)
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
    int nb_folders = 0;
    char *prev_folder = NULL;

    table[nb_files] = NULL;
    folder = opendir(str);
    printf("STR = %s\n", str);
    while ( (entry = readdir(folder)) )
    { 
        table[i] = strdup(entry->d_name);
        printf("THE PLACE TO BE = %s\n", table[i]);
        if (entry->d_type == DT_DIR && (table[i][1] != '\0' && table[i][0] != '.')) {
            i++;
            str = strdup(entry->d_name);
            printf("FOLDERS_NAME = %s\n", str);
            infos->pos_folder[j] = i;
            j++;
            get_path(infos, table, i, j, str);
            nb_folders++;
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
    int j = 0;
    char *str = "./";
    char **table = malloc(sizeof(char *) * 50);
    info *infos = malloc(sizeof(info));
    infos->pos_folder = malloc(sizeof(int) * 50);
    

    nb_folders = get_path(infos, table, i, j, str);
    printf("FILES = %d\nFOLDERS = %d\n", nb_files, nb_folders);
    printf(".\n");
    for(int i = 0; i < nb_files; i++){
        if(table[i][0] != '.')
            if (infos->pos_folder[0] == i + 1){
                printf("|-- %s\n|   `--%s \n", table[i], table[i + 1]);
                i++;
            } else {
                printf("|-- %s\n",table[i]);
            }
    }
}