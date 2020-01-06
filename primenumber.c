#include <stdio.h>
void main()
{
    int i, num;
    printf("Enter a Number:");
    scanf("%d", &num);
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            break;
        }
    }
    if (num == i)
    {
        printf("\n The given Number %d is a prime Number", num);
    }
    else
    {
        printf("\n The given Number %d is not a prime Number", num);
    }
}
