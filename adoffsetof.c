#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
#include <stddef.h> // For offsetof()
#define MAX_SIZE 35
int main(void); // Define main(), and the fact that this program doesn’t
// use any passed parameters
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
        SAYING Peter1;
        SAYING Peter2;
        SAYING Peter3;
        SAYING Peter4;
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
                               " If you don't play to win,",
                               " you don't win.",
                               NULL /* Flag to mark the last saying */
                           }};
    printf(
        "sizeof(SAYING) = %d (each member's size)\n"
        "offsetof(OURSAYING, Peter) = %d (the second member)\n"
        "offsetof(OURSAYING, Peter3) = %d (the fifth member)\n",
        sizeof(SAYING),
        offsetof(OURSAYING, Peter),
        offsetof(OURSAYING, Peter4));
    return (0);
}