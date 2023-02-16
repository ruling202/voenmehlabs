#include<stdio.h>
const int x = 32; 	// вводится константа 
 
// Конвертация верхнего регистра в нижний 
char * toLowerCase(char *a)
{
    for (int i=0; a[i]!='\0'; i++)		///В этом случае "for(int i = 0; a[i]; i++)" ваш цикл продолжает свое выполнение до тех пор, пока один из его элементов не станет нулевым элементом. Всегда, когда вы видите это выражение, это всегда одно и то же значение, которое проверяет, является ли элемент null или нет, чтобы остановить цикл.
        a[i] = a[i] | x;					
 
    return a;
}
 
// Основная функция
int main()
{
    int num;
    char str[] = "SanjaYKannA faldfjlffa";
    printf("Set number: ");
    scanf("%f", &num);
    printf("%s", toLowerCase(str));
    return 0;
}