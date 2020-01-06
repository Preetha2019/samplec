#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
#define MAX_SIZE 35
int main(void); // Define main(), and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int i;
    typedef struct
    {
        char *szSaying[MAX_SIZE];
        int nLength[MAX_SIZE];
    } SAYING;
    typedef struct
    {
        SAYING Murphy;
        SAYING Peter;
    } OURSAYING;
    OURSAYING OurSaying = {{
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
                               " you don’t win.",
                               NULL /* Flag to mark the last saying */
                           }};
    OURSAYING *pOurSaying;
    SAYING *pSaying;
    pOurSaying = &OurSaying;
    pSaying = &OurSaying.Peter;
    printf(
        "sizeof(OURSAYING) = %d\n"
        "sizeof(OurSaying) = %d\n"
        "sizeof(SAYING) = %d\n"
        "sizeof(pOurSaying->Murphy) = %d\n"
        "sizeof(pOurSaying->Peter) = %d\n"
        "sizeof(pSaying) = %d\n"
        "sizeof(*(pSaying)) = %d\n",
        sizeof(OURSAYING),
        sizeof(OurSaying),
        sizeof(SAYING),
        sizeof(pOurSaying->Murphy),
        sizeof(pOurSaying->Peter),
        sizeof(pSaying),
        sizeof(*(pSaying)));
    for (i = 0; pOurSaying->Murphy.szSaying[i]; i++)
    {
        pOurSaying->Murphy.nLength[i] = strlen(pOurSaying->Murphy.szSaying[i]);
    }
    for (i = 0; pOurSaying->Murphy.szSaying[i]; i++)
    {
        printf("pOurSaying->Murphy %p %3d '%s'\n",
               &pOurSaying->Murphy.szSaying[i],
               pOurSaying->Murphy.nLength[i],
               pOurSaying->Murphy.szSaying[i]);
    }
    printf("\n\n");
    for (i = 0; pSaying->szSaying[i]; i++)
    {
        pSaying->nLength[i] = strlen(pSaying->szSaying[i]);
    }
    for (i = 0; pSaying->szSaying[i]; i++)
    {
        printf("pOurSaying->Peter %p %3d '%s'\n",
               &pSaying->szSaying[i],
               pSaying->nLength[i],
               pSaying->szSaying[i]);
    }
    printf("\n\n");
    return (0);
}