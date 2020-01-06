#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions.
#define MAX_LINES 25
#define MAX_LENGTH 80
int main(void); // Define main() and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int i;
    char szSaying[MAX_LINES][MAX_LENGTH] =
        {
            "Firestone's Law of Forecasting:",
            " Chicken Little only has to be right once.",
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
            " had a flat tire, the next morning you will have a flat tire."};
    printf(
        "Number of lines is %d\n"
        "size of item is %d\n"
        "size of (char) is %d\n",
        sizeof(szSaying) / sizeof(szSaying[0]), // Number of elements.
        sizeof(szSaying[0]),                    // Size of char *
        sizeof(szSaying[0][0]));                // Size of char
    switch (sizeof(char *))
    {
    case 2: // Near pointers
        printf("Addr len saying\n");
        break;
    case 4: // Far pointers, 808x segmented pointers.
        printf("Address len saying\n");
        break;
    }
    for (i = 0; i < sizeof(szSaying) / sizeof(szSaying[0]); i++)
    {
        printf("%p %3d '%s'\n",
               szSaying[i],
               strlen(szSaying[i]),
               szSaying[i]);
    }
    return (0);
}