#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
#define NUMBER_ELEMENTS 35
int main(void); // define main(), and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int i;
    struct
    {
        char *szSaying[NUMBER_ELEMENTS];
        int nLength[NUMBER_ELEMENTS];
    } OurSaying = {
        "Firestone's Law of Forecasting:",
        " Chicken Little has to be right only once.",
        "",
        "",
        "Manly's Maxim:",
        " Logic is a systematic method of coming to",
        " the wrong conclusion with confidence.",
        "",
        "",
        "Moer's truism:",
        " The trouble with most jobs is the job holder's",
        " resemblance to being one of a sled dog team. No one",
        " gets a change of scenery except the lead dog.",
        "",
        "",
        "Cannon's Comment:",
        " If you tell the boss you were late for work because you",
        " had a flat tire, the next morning you will have a flat tire.",
        NULL /* Flag to mark the last saying */
    };
    for (i = 0; OurSaying.szSaying[i]; i++)
    {
        OurSaying.nLength[i] = strlen(OurSaying.szSaying[i]);
    }
    printf("sizeof(OurSaying) = %d\n", sizeof(OurSaying));
    for (i = 0; OurSaying.szSaying[i]; i++)
    {
        printf("OurSaying %p %3d '%s'\n",
               &OurSaying.szSaying[i],
               OurSaying.nLength[i],
               OurSaying.szSaying[i]);
    }
    printf("\n\n");
    return (0);
}