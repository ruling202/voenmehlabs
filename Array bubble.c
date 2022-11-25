#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
  int array[N],pl,i,k; 
/*Ввод массива*/
  printf("Enter an array:\n");
  for(i=0;i<5;i++)
    scanf("%i",&array[i]);
 /*сортировка*/
  for(i=0;i<4;i++)
    {
        for(k=0;k<4;k++) 
          {
            if(array[k]<array[k+1])    
            {
          
             pl=array[k];
             array[k]=array[k+1];
             array[k+1]=pl;
            }
        }
    }
    

    for(k=0;k<5;k++)
       printf("Sorted array:%i \n",array[k]);
    getch();
    
}
