#include <stdio.h>
/* function declaration */
void swap(int *a, int *b);
int main()
{
    /* local variable definition */
    int a = 100;
    int b = 200;
    printf("Before swap, value of a : %d\n", a);
    printf("Before swap, value of b : %d\n", b);
    /* calling a function to swap the values.
 * &a indicates pointer to a i.e. address of variable a and
 * &b indicates pointer to b i.e. address of variable b.
 */
    return 0;
}
void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
    printf("\n After Swapping the value are:%d\t%d", *x, *y);
}