#include <ctype.h>
#include "utils.h"

int is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


#include <stdio.h>
#include "utils.h"
#define MAX_MATRIX_SIZE 100
void print_matrix(double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}


#ifndef UTILS_H
#define UTILS_H

int get_file_size(FILE* fp);

#endif