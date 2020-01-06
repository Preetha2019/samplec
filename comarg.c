#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions.
int main(           // Define main() and the fact that this program uses
    int argc,       // the passed parameters.
    char *argv[],
    char *envp[]);
int main(int argc, char *argv[], char *envp[])
{
    int i;
    printf("\n");
    printf("Program name is '%s'\n\n", argv[0]);
    // argc includes the program name, so decrement for actual
    // passed parameters.
    printf("Number of parameters %d \n\n", argc - 1);
    // It's just as valid is to use:
    // for (i = 1; i < argc; i++)
    for (i = 1; argv[i]; i++)
    {
        printf("Passed parameter %2d is '%.50s'\n", i, argv[i]);
    }
    printf("\n");
    // Environment variables may not be meaningful for all
    // operating systems. Check the compiler's documentation.
    // If this information is not available on your system,
    // delete the below for() loop.
    for (i = 0; envp[i]; i++)
    {
        printf("Environment string %2d is '%.70s'\n", i, envp[i]);
    }
    return (0);
}