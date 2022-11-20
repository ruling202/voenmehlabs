#define ISQUARE(x) (x)*(x)
int main()
{
    int m = 5;
    int res = ISQUARE(m);
    printf("res=%d",res);
    return 0;
    int res1 = ISQUARE(m-1);
    printf("res1=%d",res1);
    return 0;
    int res2 = ISQUARE(m++);
    printf("res2=%d",res2);
    return 0;
}


