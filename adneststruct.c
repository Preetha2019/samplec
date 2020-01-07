#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
int main(void);     // Define main(), and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int i;
    struct SAYING
    {
        char *szSaying[500];
        int nLength[500];
    };
    struct
    {
        struct SAYING Murphy;
        struct SAYING Peter;
    } OurSaying = {{
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
                   },
                   {
                       "David's rule:",
                       " Software should be as easy to use as a Coke machine.",
                       "",
                       "",
                       "Peter's Maxim:",
                       " To be successful, you must work hard, but",
                       " Hard work doesn’t guarantee success.",
                       "",
                       "",
                       "Teacher's truism:",
                       " Successful people learn.",
                       "",
                       "",
                       "Player's Comment:",
                       " If you don’t play to win,",
                       " you don't win.",
                       NULL /* Flag to mark the last saying */
                   }};
    for (i = 0; OurSaying.Murphy.szSaying[i]; i++)
    {
        OurSaying.Murphy.nLength[i] =
            strlen(OurSaying.Murphy.szSaying[i]);
    }
    printf("sizeof(OurSaying.Murphy) = %d\n", sizeof(OurSaying.Murphy));
    for (i = 0; OurSaying.Murphy.szSaying[i]; i++)
    {
        printf("OurSaying.Murphy %p %3d '%s'\n",
               &OurSaying.Murphy.szSaying[i],
               OurSaying.Murphy.nLength[i],
               OurSaying.Murphy.szSaying[i]);
    }
    printf("\n\n");
    for (i = 0; OurSaying.Peter.szSaying[i]; i++)
    {
        OurSaying.Peter.nLength[i] = strlen(OurSaying.Peter.szSaying[i]);
    }
    printf("sizeof(OurSaying.Peter) = %d\n", sizeof(OurSaying.Peter));
    for (i = 0; OurSaying.Peter.szSaying[i]; i++)
    {
        printf("OurSaying.Peter %p %3d '%s'\n",
               &OurSaying.Peter.szSaying[i],
               OurSaying.Peter.nLength[i],
               OurSaying.Peter.szSaying[i]);
    }
    printf("\n\n");
    return (0);
}