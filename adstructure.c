#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
int main(void);     // Define main() and the fact that this
// program doesn’t use any passed parameters
int main()
{
    int i;
    struct
    {
        char szSaying[129];
        int nLength;
    } MySaying[] = {
        "Firestone's Law of Forecasting:",
        0,
        " Chicken Little has to be right only once.",
        0,
        "",
        0,
        "",
        0,
        "Manly's Maxim:",
        0,
        " Logic is a systematic method of coming to",
        0,
        " the wrong conclusion with confidence.",
        0,
        "",
        0,
        "",
        0,
        "Moer's truism:",
        0,
        " The trouble with most jobs is the job holder's",
        0,
        " resemblance to being one of a sled dog team. No one",
        0,
        " gets a change of scenery except the lead dog.",
        0,
        "",
        0,
        "",
        0,
        "Cannon's Comment:",
        0,
        " If you tell the boss you were late for work because you",
        0,
        " had a flat tire, the next morning you will have a flat tire.",
        0,
    };
    for (i = 0;
         i < (sizeof(MySaying) / sizeof(MySaying[0]));
         i++)
    {
        MySaying[i].nLength = strlen(MySaying[i].szSaying);
    }
    printf("sizeof(MySaying) = %d\n", sizeof(MySaying));
    printf("Number of elements = %d\n",
           (sizeof(MySaying) / sizeof(MySaying[0])));
    for (i = 0;
         i < (sizeof(MySaying) / sizeof(MySaying[0]));
         i++)
    {
        printf("MySaying[%2d] %p %3d '%s'\n",
               i,
               &MySaying[i].szSaying,
               MySaying[i].nLength,

               MySaying[i].szSaying);
    }
    printf("\n\n");
    return (0);
}