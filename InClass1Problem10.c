//UNION
//only one data type can exist at any given time in a union
//The size allocated for a union will be the largest type.

#include <stdio.h>
#include <string.h>

//size allocated is 20 bytes. Regardless of which data you use. This way computer can change it at runtime
union Data {
   int i;  //4 bytes
   float f; //4 bytes
   char str[20];  //20 bytes
};

int main( ) {

   union Data data;

   printf( "Memory size occupied by data : %d\n",sizeof(data));

   return 0;
}
