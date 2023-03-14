#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char *argv[])
{
        //Описание переменных
        char fnick[14];
        int g=0,h=0;
        double average=0,number=0;
        FILE *input,*output;
        //Запрашиваем имя файла и создаем его
        printf("Enter filename:\n");
        gets(fnick);
        input=fopen(fnick,"wb+");
        //Запрашиваем количество вводимых чисел
        printf("How much numbers?\n");
        scanf("%d",&g);
        //Запрашиваем числа для ввода и пишем в файл
        for (h=0;h<g;h++)
                {
                        printf("Number %d:\n",h+1);
                        scanf("%lf",&number);
                        //fwrite(input,"%lf ",num);
                        fwrite(&number, sizeof(double),1, input);
                }
        fclose(input);
        //Открываем файл для чтения
        input=fopen(fnick,"rb");
        g=0; number=0;
        //Считываем числа и считаем среднее
        printf("Source file content:\n");
        while(!feof(input))
                {
                        //fscanf(input,"%lf ",&num);
                fread(&number, sizeof(double), 1, input);  
                printf("%lf ",number);
                        average+=number;
                        g++;
                }
        average/=g;
        printf("\nAverage: %lf\n",average);
        //Ставим курсор снова в начало файла
        rewind(input);
        //присоединение строки
        output=fopen("tmp.tmp","wb+");
        //Считываем числа из файла и сравниваем их с средним значением
        //Записываем результаты во временный файл
        while(!feof(input))
                {
                    //fscanf(input,"%lf ",&num);
                        fread(&number, sizeof(double), 1, input);
                        if (number>average) number=1;
              //     fprintf(output,"%lf ",num);
                        fwrite(&number, sizeof(double), 1, output);
                }
        fclose(input);
        fclose(output);
        //удалить input,переименовать output
        remove(fnick);
        rename("tmp.tmp",fnick);
        input=fopen(fnick,"rb");
        //Считать данные из полученного файла и вывести на экран
        printf("Result file content:\n");
        while(!feof(input))
                {
                        fread(&number, sizeof(double), 1, input);
                      printf("%lf ",number);
                }
        fclose(input);
 
getchar();
return EXIT_SUCCESS;
}