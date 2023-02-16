#include <stdio.h>
#include <string.h>
 
int main()  //Основная функция
{
 char * strings[] = {"Voenmeh","BMW","GG","pc","cpu","FFF","Sain-P.","SOS","aaa"};  //массив для обработки
 int i,l,ks; //переменные 
 
 ks = sizeof(strings)/4; //определяем размер строки
 
 for(i=0; i < ks; i++) //цикл перебора строки
 {
  l = strlen(strings[i]); // переменная l
  if(*strings[i] == strings[i][l-1]) //условие перебора, проверка сравнение значений слева и справа
  {
   printf("%s\n",strings[i]);
  }
 
 }
 
 return 0;
}