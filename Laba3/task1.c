#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "task1.h"
#include "utils.h"

int count_lines(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        count++;
    }

    fclose(fp);
    return count;
}

int count_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            count++;
        }
    }

    fclose(fp);
    return count;
}

int count_chars(char* filename, int with_spaces) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (with_spaces || !isspace(c)) {
            count++;
        }
    }

    fclose(fp);
    return count;
}