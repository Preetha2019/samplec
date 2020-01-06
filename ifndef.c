#include <stdio.h>

#define MAX 20

void main()
{
#ifndef MAX
#define MIN 90
#else
#define MIN 100
#endif

      printf("MIN number : %d", MIN);
}