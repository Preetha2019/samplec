#include <stdio.h>
const int MAX = 3;
int main ()
{
int var[] = {10, 100, 200};
int i, *a;
/* let us have array address in pointer */
a = var[MAX-1];
for ( i = 0; i < MAX; i++)
{
printf("Address of var[%d] = %x\n", i, a );
printf("Value of var[%d] = %d\n", i, *a );
/* move to the next location */
a++;
}
return 0;
}