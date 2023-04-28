#include <stdio.h>
#include <stdlib.h>
#include "task3.h"
#include "utils.h"

void remove_or_append_int(char* filename, int num) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int file_size = get_file_size(fp);
    int* buffer = malloc(file_size);
    int count = file_size / sizeof(int);
    int new_count = 0;

    for (int i = 0; i < count; i++) {
        int current_num;
        fread(&current_num, sizeof(int), 1, fp);
        if (current_num != num) {
            buffer[new_count] = current_num;
            new_count++;
        }
    }

    fclose(fp);

    if (new_count == count) {
        // Number not found, append to end of file
        fp = fopen(filename, "ab");
        if (fp == NULL) {
            printf("Error opening file %s\n", filename);
            exit(1);
        }
        fwrite(&num, sizeof(int), 1, fp);
        fclose(fp);
    } else {
        // Number found, rewrite file
        fp = fopen(filename, "wb");
        if (fp == NULL) {
            printf("Error opening file %s\n", filename);
            exit(1);
        }
        fwrite(buffer, sizeof(int), new_count, fp);
        fclose(fp);
    }

    free(buffer);
}