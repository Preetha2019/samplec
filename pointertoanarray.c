#include <stdio.h>
int main()
{
    int a = 10;
    char b[15];
    printf("Address of var1 variable: %x\n", &a);
    printf("Address of var2 variable: %x\n", &b[15]);
    return 0;
}