#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions.
#include <stdlib.h>  // Standard include items.
#include <process.h> // For exit(), etc.
#include <time.h>    // For time information.
#define ARG_HELP ‘?’
#define ARG_SLASH ‘/’
#define ARG_DASH ‘-’
int main(     // Define main() and the fact that
    int argc, // this program uses the passed parameters.
    char *argv[],
    char *envp[]);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    FILE *fpFilePointer;
    long lPosition;
    int i;
    int j;
    int nNumberBytesRead;
    unsigned int nHexNumber;
    char *pszTemp;
    /* strings for _splitpath() (which parses a file name) */
    char szDrive[_MAX_DRIVE];
    char szDir[_MAX_DIR];
    char szFname[_MAX_FNAME];
    char szExt[_MAX_EXT];
    char szInputFile[128];
    char szProgram[132];
    char szBuffer[132];
    char sBuffer[257];
    time_t tTime;
    struct tm *pTM;
    _splitpath(argv[0],
               szDrive,
               szDir,
               szFname,
               szExt);
    strncpy(szProgram, szFname, sizeof(szProgram) - 1);
    if (argc <= 1)
    {
        printf(“% s
               : -No file name given.\n”, szProgram);
        exit(4);
    }
    for (i = 1; argv[i]; i++)
    {
        if (argv[i][0] == ‘/’ || argv[i][0] == ‘-’)
        { /* You have an argument, convert to lowercase, and test. */
            pszTemp = strlwr(argv[i]);
            for (j = 1; j < strlen(pszTemp); j++)
            {
                switch (pszTemp[j])
                {
                case ARG_HELP:
                    printf(“Usage
                           : % s filename.ext \n”,
                             szProgram);
                    exit(4);
                    break;
                case ARG_SLASH:
                case ARG_DASH:
                    break;
                default:
                    printf(“% s
                           : -Invalid option ‘% c’.\n”,
                             pszTemp[j],
                             szProgram);
                    break;
                }
            }
        }
        else
        { /* Either a filename or width. */
            strcpy(szInputFile, argv[i]);
        }
    }
    if ((fpFilePointer = fopen(szInputFile, “r + b”)) == NULL)
    {
        printf(“% s
               : Unable to open file
               : % s\n”,
                 szProgram,
                 szInputFile);
        exit(16);
    }
    lPosition = 0l;
    printf(“\n”);
    time(&tTime);
    pTM = localtime(&tTime);
    /* format a time string, using strftime() (new with ANSI C) */
    strftime(szBuffer,
             sizeof(szBuffer),
“% A % B % d, % Y at % H
             : % M
             : % S”,
               pTM);
    printf(“Dump of % s, % s\n\n”,
           szInputFile,
           szBuffer);
    while ((nNumberBytesRead = fread((char *)sBuffer,
                                     sizeof(char), 16, fpFilePointer)) > 0)
    {
        printf(“ % 8.8X -”, lPosition);
        for (i = 0; i < 16; i++)
        {
            if (i == 8)
            {
                printf(“ - “);
            }
            else
            {
                if (i == 0 ||
                    i == 4 ||
                    i == 12)
                {
                    printf(“ “);
                }
            }
            if (i < nNumberBytesRead)
            {
                nHexNumber = (unsigned char)sBuffer[i];
                printf(“% 2.2X”, (unsigned int)nHexNumber);
            }
            else
            {
                printf(“ “);
            }
        }
        for (i = 0; i < nNumberBytesRead; i++)
        {
            if (sBuffer[i] < ‘ ‘ ||
                sBuffer[i] == ‘\xFF’)
            {
                sBuffer[i] = ‘.’;
            }
        }
        sBuffer[nNumberBytesRead] = ‘\0’;
        printf(“
               : % s”, sBuffer);
        printf(“ \n”);
        lPosition += 16;
    }
    return (0);
}