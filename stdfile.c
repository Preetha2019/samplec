#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions.
#include <stdlib.h>  // Standard include items.
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
    FILE *OutputFile = NULL;
    int nFile = 0;
    int i;
    while (nFile < 1 || nFile > 3)
    {
        printf(
            " Which file to write to:\n"
            " 1 - stdprn (the printer)\n"
            " 2 - stdaux (the communications port)\n"
            " 3 - stdout (the console)\n"
            " enter 1, 2 or 3: ");
        scanf("%d", &nFile);
    }
    switch (nFile)
    {
    case 1:
        OutputFile = stdprn;
        break;
    case 2:
        OutputFile = stdaux;
        break;
    case 3:
        OutputFile = stdout;
        break;
    }
    for (i = 0; i < 50; i++)
    {
        /* stdprn is opened in the binary mode, so a CR/LF
* must be supplied explicitly, using \n\r
*/
        fprintf(OutputFile,
                " Line %2d of 50 lines"
                " being written to user-selected destination by a program.\n\r",
                i);
    }
    /* Use an explicit form feed to force a page eject if the
* printer is a laser printer.
*/
    fprintf(OutputFile, "\f");
    return (0);
}