#include <stdio.h>

void swap(float *x, float *y)
{
    float tmp=*x;
    *x=*y;
    *y=tmp;
    return;
}

int main()
{
    float a=2.3;
    float b=-1.7;

    swap(&a,&b);

    printf("a=%f ; b=%f\n", a, b);

    return 0;
}
