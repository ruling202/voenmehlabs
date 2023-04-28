#include <stdio.h>
#include <math.h>
#include "task2.h"
#include "utils.h"

void read_matrix(char* filename, double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int* rows, int* cols) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d %d", rows, cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(fp, "%lf", &matrix[i][j]);
        }
    }

    fclose(fp);
}

void round_matrix(double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = round(matrix[i][j] * 10) / 10;
        }
    }
}

void write_matrix(char* filename, double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rows, int cols) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%.1lf ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}