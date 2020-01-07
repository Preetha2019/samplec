#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
int main(void);     // Define main() and the fact that this program doesn’t
// use any passed parameters.
#define MAX_CHARACTERS 32767 /* Total maximum characters */
#define MAX_LINES 1000       /* Total maximum lines */
#define BIGEST_LINE 128      /* The longest line readable from keyboard \
                              */
/* Although these variables are defined as external, they can
* be defined inside the function or be allocated dynamically,
* depending on the program’s needs and memory available.
*/
char szInput[BIGEST_LINE];
char szBuffer[MAX_CHARACTERS];
char *pBuffer[MAX_LINES];
int nBufferPointer = {0};
int nLine = 0;
int main()
{
    int i;
    printf(
        "Enter lines, when last one is entered\n"
        "provide a End-Of-File (ctrl-Z on most systems)\n"
        "to print the entered text\n\n");
    while (gets(szInput))
    {
        if ((nBufferPointer + strlen(szInput)) > MAX_CHARACTERS)
        { // The line won’t fit! End input loop.
            break;
        }
        pBuffer[nLine] = &szBuffer[nBufferPointer];
        // The strcpy() could have been written as:
        // strcpy(&szBuffer[nBufferPointer], szInput);
        strcpy(pBuffer[nLine], szInput);
        // the + 1 skips over the terminating NULL in each string.
        nBufferPointer += strlen(szInput) + 1;
        if (++nLine >= MAX_LINES)
        { // Too many lines! End input loop.
            break;
        }
    }
    //
    // Later, you add a sort to provide sorted output.
    //
}