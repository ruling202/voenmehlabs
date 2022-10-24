#include <stdio.h>
int main(void)
{
    int a=0xff;
    double c =1.1;
    a=c;
    printf("%d\n",a);
    c=1;
    printf("%f,%d\n",c);
}
