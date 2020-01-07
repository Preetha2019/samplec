#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions
#include <stdlib.h>  // Standard include items
#include <process.h> // For exit(), etc.
int main(            // Define main() and the fact that this program
    int argc,        // uses the passed parameters
    char *argv[],
    char *envp[]);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    int i;
    for (i = 0; i < 50; i++)
    {
        /* Because stdprn is opened in the binary mode,
* CR/LF must be supplied explicitly, using \n\r
*/
        fprintf(stdprn,
                "Line %2d of 50 lines"
                " being written to stdprn by a program.\n\r",
                i);
    }
    /* An explicit form feed is used to force a page eject
* if the printer is a laser printer
*/
    fprintf(stdprn, "\f");
    return (0);
}