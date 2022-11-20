#include <stdio.h>
#include <stdlib.h>


#define IMAX(a,b) (a)>(b)?(a):(b)
int main()
{
    int a = 1, b=2;
    int res = IMAX(a+1,b-2);
    printf("res=%d",res);
    return 0;
}