#include <stdio.h>
#include <string.h>
int main()
{
  struct
  {
    char a[50];
    short int h; /* data */
  } iron =
      {"HELLO WORLD", strlen(iron.a)};
  printf("SIZE OF A=%d", sizeof(iron));
  printf("LENGTH OF A=%d", iron.h);
  return 0;
}