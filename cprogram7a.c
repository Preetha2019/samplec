#include <stdio.h>
#include <conio.h>
int Factorial(int number);
int main()
{
    int number, f, i;
    printf("\nEnter an Integer:");
    scanf("%d", &number);
    // if(number<0)
    //     {
    //         printf("Error! Enter the valid number");
    //     }
    f = Factorial(number);
    printf("Factorial of %d is:%d", number, f);
    return (0);
}
int Factorial(int number)
{
    return number > 1 ? Factorial(number - 1) * number : 1;
}