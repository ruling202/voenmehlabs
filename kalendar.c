#include <stdio.h>
#include <time.h>
#include <locale.h>
int main()
{   	
    setlocale(LC_ALL, "Rus");
    time_t now;
    struct tm * timeinfo;
    int year, m, i, j;
    char* month[] = { "Январь","Февраль", "Март","Апрель", "Май","Июнь", 
            "Июль", "Август","Сентябрь","Октябрь", "Ноябрь","Декабрь"};
    
    printf ("ГОД: "); scanf ("%d",&year);
    time (&now); 
    timeinfo = localtime (&now);
    timeinfo->tm_year = year-1900; 
 
    m =-1;
while(m<12)
{   for(i=1; i<33; i++) 
    {   timeinfo->tm_mday = i;
        mktime (timeinfo); 
 
        if(timeinfo->tm_mon > m) 
        {   printf("\n                        %s\n",month[timeinfo->tm_mon]);
            printf("<br>\n");
            printf("  Вс  Пн  Вт  Ср  Чт  Пт  Сб\n");
            printf("<br>\n");
            for(j=0;j<(timeinfo->tm_wday);j++)
                printf("    ");
            m++;
            break;
        }
        if (m==11 && timeinfo->tm_mon ==0) 
        {   m++;
            break;
        }
        
        printf("%4d",timeinfo->tm_mday); 
            
        if(timeinfo->tm_wday==6)
            printf("\n");
    }
}
    getchar();getchar();
    return 0;
}