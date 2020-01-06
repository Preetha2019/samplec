#include <stdio.h>
int preced(int a, int b, int c, int d, int e);
int main()
{
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;
    printf("The precedence operations results of %d,%d,%d,%d\n is %d", a, b, c, d, e);
    preced(a, b, c, d, e);
    return (0);
}
int preced(int a, int b, int c, int d, int e)
{
    e = (a + b) * c / d; // ( 30 * 15 ) / 5
    printf("Value of (a + b) * c / d is : %d\n", e);
    e = ((a + b) * c) / d; // (30 * 15 ) / 5
    printf("Value of ((a + b) * c) / d is : %d\n", e);
    e = (a + b) * (c / d); // (30) * (15/5)
    printf("Value of (a + b) * (c / d) is : %d\n", e);
    e = a + (b * c) / d; // 20 + (150/5)
    printf("Value of a + (b * c) / d is : %d\n", e);
}
