#include <stdio.h>

// After this line HYD is replaced by
// "Hyderabad"
#define HELLO 'h'
#define CLOUD 'c'
int main()
{
    char ch1, ch2, y;
    do
    {
        printf("\nEnter your choice\t");
        scanf("%s", &ch1);
        switch (ch1)
        {
        case HELLO:
            printf("\n HELLO WORLD & %s ", HELLO);
            break;
        case CLOUD:
            printf("\n HAI MUKILAN, R U IN %s ", CLOUD);
            break;
        }
        printf("\n Do you want to continue(y/n):");
        scanf("%s", &ch2);
    } while (ch2 == 'y');
    return 0;
}