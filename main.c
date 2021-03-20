/*
** EPITECH PROJECT, 2020
** main
** File description:
** bsq
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "include/my.h"

int error_handling(char *buffer, int size_buffer)
{
    int i = 0;
    if (size_buffer == 0) {
        my_putstr("Empty map");
        my_putchar('\n');
        return (84);
    }
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i]
        != '\n' && buffer[i] != '\0')
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    struct stat buf;
    int op = open(av[1], O_RDONLY);
    int size_buffer = 0;
    int a = 0;
    stat(av[1], &buf);
    size_buffer = buf.st_size;
    char *buffer = malloc(sizeof(char) * (size_buffer + 1));
    a = read(op, buffer, size_buffer);
    while ((*buffer >= '0' && *buffer <= '9') || *buffer == '\n')
        *buffer++;
    if (error_handling(buffer, size_buffer) == 84) {
        return (84);
    }
    else
        algo_map(buffer);
    write(1, buffer, my_strlen(buffer));
}