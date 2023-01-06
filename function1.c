double Average(int nFirst, ...);
#include <stdio.h>
int main (void) {
    double aver = Average (2, 3, 4, -1);
    printf("%df\n", aver);
    return 0;
}

double Average(int first, ...){
  int count=0, sum=0;
  int* p = &first;
  while(*p !=-1){
    
    sum +=*p;
    p++;
    count++;

    }

    printf("PASSED!\n");
    return 0;

}

  