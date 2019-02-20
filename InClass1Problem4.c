//function  --> scope of variable local vs global vs static
//local variables go in Frame of calling function in STACK
//static variable, go in STATIC, accessible by all functions in file declared
//global variable, go in STATIC, accessible by all functions in program

#include<stdio.h>

// Global variables
int A;
int B;

int fun()
{
  static int count = 0; //Static Variable
  count++;
  return count;
}

int Add()
{
    return A + B;
}

int main()
{
    int answer; // Local variable
    A = 5;
    B = 7;
    answer = Add();
    printf("%d\n",answer);
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}
