#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int main()
{
    FILE *fin,*fout;
    char buffer[255];
    fin =fopen( "input.txt", "r"); // открываем входной файл
 
fout=fopen ("output.txt", "w");
int i=0; int c=0; int j = 0;
while (1){
fscanf(fin,"%s",buffer);//чаровский массив
if (feof(fin)) break;
if (i%2==0) {
 for(j=0; buffer[j]; j++) {
   if ('a' <= buffer[j]  && buffer[j]<='z')
        buffer[j] -= 32;
 }
}
fputs(buffer, fout);
i++;
}
fclose(fout);
fclose(fin);
system("pause");
return 0;
}