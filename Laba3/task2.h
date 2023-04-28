#ifndef TASK1_H
#define TASK1_H

#define MAX_MATRIX_SIZE 100

void read_matrix(char* filename, double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int* rows, int* cols);
void round_matrix(double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rows, int cols);
void write_matrix(char* filename, double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rows, int cols);

#endif