#include<stdio.h>
#include<conio.h>
unsigned int Factorial( unsigned int number );
int main()
{
    unsigned int number,f,i;
    printf("\nEnter an Integer:");
    scanf("%d", &number);
    f= Factorial(number);
     printf("Factorial of %d is:%d", number, f);
     return(0);
}
    unsigned int Factorial( unsigned int number )
    {
            return number > 1 ? Factorial(number-1)*number : 1;
    }

