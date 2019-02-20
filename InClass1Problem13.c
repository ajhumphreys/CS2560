#include <stdio.h>

void swap(int *x,int *y)  //defining function called swap
{
    int z = *x;
    *x = *y;
    *y = z;
}


int main()
{
    int a = 45, b =35;
    printf("Before Swap\n");
    printf("a = %d b = %d\n",a,b);

    swap(&a, &b);

    printf("After Swap with pass by reference\n");
    printf("a = %d b = %d\n",a,b);
    return 0;
}
