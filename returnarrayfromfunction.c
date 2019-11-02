#include <stdio.h>
/* function to generate and return random numbers */
int * getRandom( )
{
    //extern file to file
    //static is local to a file
 static int r[10];
 //local variable
 int i;
 /* set the seed */
 srand( (unsigned)time( NULL ) ); // epoc function returns value from 1970/01/01
 //returns as  number
 for ( i = 0; i < 10; ++i)
 {
 r[i] = rand();
 printf( "r[%d] = %d\n", i, r[i]);
 }
 return r;
}
/* main function to call above defined function */
int main ()
{
 /* a pointer to an int */
 int *p;
 int imain;
 p = getRandom();
 for ( imain = 0; i < 10; i++ )
 {
 printf( "*(p + %d) : %d\n", imain, *(p + imain));
 }
 return 0;
}
