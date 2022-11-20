#include <stdio.h>
#include <stdlib.h>


#define MAX(a,b) a>b?a:b
int main()
{
    int a = 1, b=2;
    int res = MAX(a+1,b-2);
    printf("res=%d",res);
    return 0;
}