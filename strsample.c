#include <stdio.h>
#include <string.h>
void main()
{
    struct
    {
        char c[100];
        int nlength;
    } hello =
        {"WE AER THE KING",
         strlen(hello.c)};
    printf("Enter the String");
    scanf("%s", hello.c);
    printf("Size of string %d", sizeof(hello.c));
    printf("length of string %d", strlen(hello.c));
}