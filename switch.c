#include <stdio.h>
int swit(char grade);
int main()
{
    /* local variable definition */
    char grade;
    printf("Please Enter the grade of student:");
    scanf("%c", grade);
    swit(grade);
    return 0;
}
int swit(char grade)
{
    switch (grade)
    {
    case 'A':
        printf("Excellent!\n", grade);
        break;
    case 'B':
    case 'C':
        printf("Well done\n", grade);
        break;
    case 'D':
        printf("You passed\n", grade);
        break;
    case 'F':
        printf("Better try again\n", grade);
        break;
    default:
        printf("Invalid grade\n", grade);
    }
    printf("Your grade is %C\n", grade);
    return 0;
}
