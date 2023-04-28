#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s task_code file_name [additional_arguments]\n", argv[0]);
        return 1;
    }

    int task_code = atoi(argv[1]);
    char *file_name = argv[2];
    // Обработка дополнительных аргументов при необходимости

    switch (task_code) {
        case 1:
            // Вызов функций для решения задачи 1
            break;
        case 2:
            // Вызов функций для решения задачи 2
            break;
        case 3:
            // Вызов функций для решения задачи 3
            break;
        default:
            printf("Invalid task code\n");
            return 1;
    }

    return 0;
}