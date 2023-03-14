#include <stdio.h>
#include <stdlib.h>
struct semena //описание типа данных 
{
    char name[30];
    char vremya_vysadki[11];
    char kolvo_semyan_v_upakovke;
    float money;
    char razmer_upakovki[30];
};
void add (char*); // добавление записи
void edit (char*); // редактирование записи 
void show (char*); // вывод списка 
void search (char*); // поиск клиента 

int main (void)
{
    char file[50];
    char menu;
    puts ("Name of file:");
    gets (file);
    do

    {
 system ("CLS");
 puts ("1. Add");
 puts ("2. Edit");
 puts ("3. Show");
 puts ("4. Search");
 puts ("5. Exit");
 menu = getchar();
 switch (menu)
 {
    case '1': add (file); break;
    case '2': edit (file); break;
    case '3': show (file); break;
    case '4': search (file);
 }   
    }

    while (menu!='5');
    return 0;

}

struct semena input_plant (void) // заполнение одной записи (ввод данных)
{
    struct semena plant;
    int temp;
 fflush(stdin); /* очистка потока ввода */
 puts ("Name");
 gets (plant.name);
 puts ("Razmer_upakovki");
 gets (plant.razmer_upakovki);
 puts ("Vremya_vysadki");
 gets (plant.vremya_vysadki);
 puts ("Kolvo_semyan_v_upakovke");
 scanf ("%d", &temp);
 plant.kolvo_semyan_v_upakovke = temp;
 puts ("Money");
 scanf ("%f", &plant.money);
 return plant;
} 
void add (char* file) // добавление записи в файл 
{
    FILE * f;
 struct semena plant;
 system ("CLS");
 if ((f=fopen (file, "ab"))==NULL) // открываем для дозаписи
 {
    perror ("Error open file"); 
    system ("pause");
    return;
 } 
    plant = input_plant(); // ввод данных 
    fwrite (&plant, sizeof (plant), 1, f); // запись в файл 
    fclose (f);
}

void print1 (struct semena data) // печать одной записи
{
    printf ("Name : %s\nVremya_vysadki : %s\nKolvo_semyan_v_upakovke : %s\nRazmer_upakovki: %d\nSum : %.2f\n",
    data.name, data.vremya_vysadki, data.kolvo_semyan_v_upakovke, data.razmer_upakovki, data.money);
}

void edit (char* file) // редактирование записей

{
    FILE * f;
 struct semena plant;
 char name[30], yes;
 system ("CLS");
 if ((f=fopen (file, "rb+"))==NULL) // открываем файл для чтения и редактирования

{
    perror ("Error open file"); 
    system ("pause");
    return;

} 
    printf ("Name: ");
    fflush(stdin);
    gets (name); 
    while (fread(&plant,sizeof(plant), 1, f))
    if (!strcmp(plant.name, name)) // если совпадает 

{
    print1 (plant); // выводим запись 
    puts ("Redact? (y/n)");
    do
        yes=getchar();
    while (yes!='y' && yes!='Y' && yes!='n' && yes!='N');
    if (yes=='y' || yes=='Y')
    {//редактирование
        plant = input_plant();
        fseek(f,-sizeof(plant),SEEK_CUR);
        fwrite (&plant, sizeof (plant), 1, f);
        fseek(f,0,SEEK_CUR);


    }
}
    system ("pause");
    fclose(f);
}

void show (char* file) // вывод на экран
{
    FILE * f;
    struct semena plant;
    int k=0;
    system ("CLS");
    if ((f=fopen (file, "rb"))==NULL) // открываем файл для чтения

    {
        perror ("Error open file"); 
        system ("pause"); 
        return;

    }

    puts ("| N | Name | Vremya_vysadki | Kolvo_semyan_v_upakovke | Razmer_upakovki | Sum |"); // шапка таблицы 
 puts ("-------------------------------------------------------------------------");
 while (fread(&plant, sizeof(plant), 1, f)==1)
 printf ("|%3d |%30s |%11s |%8d |%30s  |%10.2f |\n", ++k, 
plant.name, plant.vremya_vysadki, plant.kolvo_semyan_v_upakovke, plant.razmer_upakovki, plant.money);
 puts ("-------------------------------------------------------------------------");
 fclose (f); 
 system ("pause");

}
   void search (char* file) // поиск  
{
    FILE * f;
    struct semena plant;
    float money;
    int max_kolvo_semyan_v_upakovke=0, pos;
    system ("CLS");
    if ((f=fopen (file, "rb"))==NULL) // открываем файл для чтения

    {
        perror ("Error open file"); 
        system ("pause"); 
        return;
    } 

    puts ("Kakoe kolichestvo semyan v upakovke?");
    scanf ("%f",&money);
    while (fread(&plant, sizeof(plant), 1, f)==1)

    {
        if (plant.money > money && plant.kolvo_semyan_v_upakovke > max_kolvo_semyan_v_upakovke)

    {
        max_kolvo_semyan_v_upakovke =  plant.kolvo_semyan_v_upakovke;
        pos = ftell(f); // запоминаем текущую позицию – конец записи 
    }
        if (max_kolvo_semyan_v_upakovke == 0) puts ("No upakovka");
            else

    {

        fseek(f,pos-sizeof(plant),SEEK_SET);
        /* возврат к началу запомненной записи */
        fread(&plant, sizeof(plant), 1, f);
        print1 (plant);
    }

     fclose(f);
     system ("pause");


    }

}
