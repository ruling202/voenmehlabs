#define SQUARE(x) x*x
int main()
{
    int m = 5;
    int res = SQUARE(m);
    printf("res=%d",res);
    return 0;
    int res1 = SQUARE(m-1);
    printf("res1=%d",res1);
    return 0;
    int res2 = SQUARE(m++);
    printf("res2=%d",res2);
    return 0;
}


