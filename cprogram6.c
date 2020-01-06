#include <stdio.h>
#include <conio.h>
unsigned int factorial(unsigned int number)
{
    unsigned int n, factorial = 1, i;
    printf("\nEnter an Integer:");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Error! Factorial of a negative number doesn't exit.");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            return number <= 1 ? number : factorial(number - 1) * number;
        }
        printf("Factorial of %d is:%d", n, factorial);
    }
}
