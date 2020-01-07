#include <stdio.h>
int whi(int a);
int main()
{
    /* local variable definition */
    int a = 10;
    whi(a);
    return 0;
}
int whi(int a)
{
    /* while loop execution */
    while (a < 20)
    {
        printf("value of a: %d\n", a);
        a++;
    }
}
