#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main()
{
    int n;
    char *text;
    printf("Enter limit of the text: ");
    scanf("%d",&n);
    
    /*allocate memory dynamically*/
    text=(char*)malloc(n*sizeof(char));
    
    printf("Enter text: ");
    scanf(" "); /*clear input buffer*/
    gets(text);
    printf("Writing text:");
    puts(text);
    /*Free Memory*/
    free(text);
    
    return 0;
}