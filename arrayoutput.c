#include <stdio.h>
int main ()
{
 int n[ 10 ]; /* n is an array of 10 integers */
 int i,j;
 /* initialize elements of array n to 0 */
 for ( i = 0; i < 10; i++ )
 {
 n[ i ] = i + 100; /* set element at location i to i + 100 */
 printf("Element[%d] = %d\n", i, n[i] );
 }
 return 0;
}
