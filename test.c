#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARG_LEFT 'l'
#define ARG_RIGHT 'r'
#define ARG_JUSTIFY 'j'
#define ARG_SLASH '/'
#define ARG_DASH '-'
#define ARG_HELP '?'
#define LEFT 1
#define RIGHT 2
#define JUSTIFY 3
#define NOINNAME 1
int main()
{
    int ch1, a;
    int i;
    int nJustification;
    printf("\nEnter your Choice");
    scanf("%d", &ch1);
    switch (ch1)
    {
    case ARG_LEFT:
        printf("\n Hello World");
        break;
    case ARG_RIGHT:
        printf("\n Beautiful thing");
        break;
    case ARG_JUSTIFY:
        printf("\n Entire world");
        break;
    case ARG_SLASH:
    case ARG_DASH:
        break;
    }
    return 0;
}