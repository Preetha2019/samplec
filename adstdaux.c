#include <stdio.h>   // Make includes first part of the file
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
    for (i = 0; i < 100; i++)
    {
        /* Because stdaux is opened in the binary mode,
* CR/LF must be supplied explicitly, using \n\r
*/
        fprintf(stdaux,
                "Line %2d of 100 lines"
                " being written to stdaux by a program.\n\r",
                i);
    }
    return (0);
}