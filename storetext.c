#include<stdio.h>
int main()
{
    char str[100];
    char *ptr;
    printf("Enter a text:\n");
    gets(str);
    ptr=str;
    printf("Entered text is:\n");
    puts(str);
    return 0;
}