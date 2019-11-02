#include <stdio.h>
int larg(int a);
int main ()
{
 int a = 10;
 larg(a);
 return(0);
}
 int larg(int a)
 {
 if( a < 20 )
 {
 printf("a is less than 20\n" );
 }
 printf("value of a is : %d\n", a);
 return 0;
 }
