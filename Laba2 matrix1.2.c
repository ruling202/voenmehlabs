#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define O 7
#define P 7
#define R 9
 
 
int main() {
    srand(time(NULL));
 
    FILE *in = fopen("1.txt", "w");
    FILE *out = fopen("2.txt", "w");
 
    int **a, *b;
    int i, j, max_znach = 0, min_znach = 1000, naib_poz = 0, naim_neg = 1000;
 
    a = calloc (O, sizeof(int*));
    for (i = 0; i < O; i++) {
        a[i] = calloc(P, sizeof(int));
        for (j = 0; j < P; j++)
            a[i][j] = rand() % 201 - 100;
    }
 
 
    b = calloc(R, sizeof (int));
 
    for (i = 0; i < O; i++) {
        for (j = 0; j < P; j++) {
            fprintf(in, "%d\t", a[i][j]);
        }
        fputc('\n', in);
    }
 
 
    for (i=0; i < O; i++){
        for (j = 0; j < P; j++)
        {
            if (a[i][j] > 0){
                b[0]++;
            }
            else if (a[i][j] < 0){
                b[1]++;
            }
            else{
                b[2]++;
            }
            b[3] += a[i][j];
 
        }
        }
 
    b[3] /= P*O; //среднее арифметическое
 
    for (i = 0; i < O; i++){
        for (j = 0; j < P; j++)
        {
            if (a[i][j] > max_znach) //максимум
                b[4] = a[i][j];
            if  (a[i][j] < min_znach) //минимум
                b[5] = a[i][j];
            if (a[i][j] > 0 && a[i][j] > naib_poz){ //наибольшее положительное
                b[6] = a[i][j];
            }
            if (a[i][j] < 0 && a[i][j] < naim_neg){ //наименьшее положительное
                b[7] = a[i][j];
            }
        }
    }
 
 
    for (j = 0; j < R; j++) {
        fprintf(out, "%d\t", b[j]);
    }
 
 
    fclose(in);
    fclose(out);
    return 0;
}