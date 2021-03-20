/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** algo
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "include/my.h"

char *change_map_in_number(char *buffer, int count)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (count == 1 && buffer[i] == '.') {
            buffer[i] = 'x';
            count = 2; }
        if (buffer[i] == 'o')
            buffer[i] = '0';
        if (buffer[i] == '.')
            buffer[i] = '1';
    }
    return (buffer);
}

char replace_map(char *buffer, int squares)
{
    int i = 0;
    int m = 0;
    int j = 0;
    int cond = 0;
    int place = 0;
    for (; buffer[j] != '\n'; j++); for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == squares + 48 && cond == 0) {
            place = i;
            cond = 1; } }
    for (int r = 0; r < squares; r++) {
        for (int e = 0; e < squares; e++) {
            buffer[place] = 'x';
            place--;
        } place = place - (j + 1) + squares; }
    for (; buffer[m] != '\0'; m++) {
        if (buffer[m] == '0') {
            buffer[m] = 'o';
        } else if (buffer[m] != 'x' && buffer[m] != '\n') {
            buffer[m] = '.';
        } } return (0);
}

char check_squares(char *buffer, int k)
{
    int j = 0;
    int above = 0;
    int tlc = 0;
    int corner = 0;
    for (; buffer[j] != '\n'; j++);
    above = k - (j + 1);
    tlc = above - 1;
    corner = k - 1;
    if (buffer[k] == '0') {
        return ('0');
    } else {
        if (buffer[above] <= buffer[tlc] && buffer[above] <= buffer[corner])
            return (buffer[above] + 1);
        if (buffer[tlc] <= buffer[above] && buffer[tlc] <= buffer[corner])
            return (buffer[tlc] + 1);
        if (buffer[corner] <= buffer[tlc] && buffer[corner] <= buffer[above])
            return (buffer[corner] + 1);
    }
    return (0);
}

char *algo_map(char *buffer)
{
    int k = 0;
    int count = 0;
    int op = 0;
    int biggest = 0;
    int squares = 0;
    for (int p = 0; buffer[p] != '\0'; p++) {
        if (buffer[p] == '\n' && buffer[p + 2] == '\n' && count == 0)
            count = 1;
        if (buffer[p] == '\n' && buffer[p + 1] == 0  && p < 500 && count == 0)
            count = 1; }
    change_map_in_number(buffer, count);
    for (; buffer[k] != '\0'; k++) { if (buffer[k] == '\n')
        op = 1; if (op == 1 && buffer[k - 1] != '\n' && buffer[k] != '\n') {
            buffer[k] = check_squares(buffer, k);
            biggest = buffer[k] - 48;
            if (biggest > squares) squares =  biggest;
        } else
            k++;
    } replace_map(buffer, squares);
    return (buffer);
}