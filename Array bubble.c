#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
  int array[N],pl,i,k; //где i счётчик циклов, k текущий номер ячейки массива
/*Ввод массива*/
  printf("Enter an array:\n");
  for(i=0;i<5;i++)
    scanf("%i",&array[i]);
 /*сортировка*/
  for(i=0;i<4;i++) //До те пор пока количество циклов не больше размерности массива, выполняем цикл:
    {
        for(k=0;k<4;k++) //До тех пор пока не переберём все элементы массива, выполняем цикл:
          {
            if(array[k]<array[k+1])    // если текущий элемент массива меньше следующего, то
            {
             /*меняем их местами*/
             pl=array[k];
             array[k]=array[k+1];
             array[k+1]=pl;
            }
        }
    }
    
/*печать результата*/
    for(k=0;k<5;k++)
       printf("Sorted array:%i \n",array[k]);
    getch();
    
}