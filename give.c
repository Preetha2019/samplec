#include <stdio.h>

void main()
{
#ifndef MAX
#define MIN 90
#else
#define MIN 100
#endif

      printf("MIN number : %d", MIN);
}