#include <stdio.h>      // Make includes first part of file
#include <string.h>     // For string functions
#include <process.h>    // For abort(), spawn(), exit(), etc.
#include <malloc.h>     // For memory allocation functions
#include <conio.h>      // For console getch(), getche(), etc.
#include <ctype.h>      // For character conversion functions
#define MAX_LINES 15500 /* Allow 64K for indexes */
#define MAX_LENGTH 513  /* Longest line is 512 + NULL */
#define DELETED_LINE -1 /* A line that has been deleted */
long lLineIndex[MAX_LINES];
char szInputLine[MAX_LENGTH];
int main(
    int argc,     /* Count of arguments */
    char *argv[], /* Array of pointers to arguments */
    char *envp[]  /* Array of pointers to environment */
);
int EditLine(char *szInputLine); /* Used to edit a given line */
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    FILE *DataFile = NULL;
    FILE *WorkFile = NULL;
    char szFileName[25];
    char szBuffer[257];
    char szTempName[L_tmpnam];
    char szNewName[L_tmpnam];
    char szCommand[81];
    char chChar;
    int i;
    int nMaxLines = 0;
    int nStartLine;
    int nEndLine;
    /* First, get the filename to edit */
    if (argc >= 2)
    {
        DataFile = fopen(argv[1], "rt");
        if (DataFile == NULL)
        {
            printf("ERROR: File '%s' couldn't be opened.\n", argv[1]);
        }
        else
        {
            strcpy(szFileName, argv[1]);
        }
    }
    while (DataFile == NULL)
    {
        printf("\nPlease enter name of file to edit: ");
        gets(szFileName);
        DataFile = fopen(szFileName, "rt");
        if (DataFile == NULL)
        {
            printf("ERROR: File '%s' couldn't be opened.\n", szFileName);
        }
    }
    printf("\n");
    /* Next, get a temporary filename, read the original file, and
* write it to the work file. Create a line-number index so that
* you can access the records.
*/
    tmpnam(szTempName);
    if (strlen(szTempName) == 0)
    {
        printf("Couldn't get a work file name...\n");
        exit(4);
    }
    WorkFile = fopen(szTempName, "w+t");
    for (i = 0; i < MAX_LINES; i++)
    {
        lLineIndex[i] = DELETED_LINE;
    }
    nMaxLines = 1;
    lLineIndex[nMaxLines] = 0;
    while (fgets(szInputLine, sizeof(szInputLine), DataFile))
    {
        lLineIndex[nMaxLines++] = ftell(WorkFile);
        fputs(szInputLine, WorkFile);
    }
    fclose(DataFile);
    printf("Total lines in file %d.\n", nMaxLines - 1);
    szCommand[0] = '\0';
    while (szCommand[0] != 'q') // Quit without saving (use w command to
    // save)
    {
        printf("Command? ");
        gets(szCommand);
        strlwr(szCommand);
        nEndLine = -1;
        sscanf(&szCommand[1], "%d%d",
               &nStartLine,
               &nEndLine);
        if (nEndLine < nStartLine)
        {
            nEndLine = nStartLine;
        }
        if (nEndLine >= nMaxLines)
        {
            nEndLine = (nMaxLines - 1);
        }
        switch (szCommand[0])
        {
        case 'e': /* Edit the specified line */
            if (nStartLine == 0)
            {
                printf("Line number must be 1 to %d\n", nMaxLines);
            }
            else
            {
                if (lLineIndex[nStartLine] == DELETED_LINE)
                {
                    printf("Line %d has been deleted, "
                           "and cannot be edited.\n",
                           nStartLine);
                }
                if (nStartLine < nMaxLines &&
                    lLineIndex[nStartLine] != DELETED_LINE)
                {
                    fseek(WorkFile,
                          lLineIndex[nStartLine], SEEK_SET);
                    fgets(szInputLine,
                          sizeof(szInputLine), WorkFile);
                    if (EditLine(szInputLine))
                    {
                        fseek(WorkFile, 0, SEEK_END);
                        lLineIndex[nStartLine] = ftell(WorkFile);
                        fputs(szInputLine, WorkFile);
                    }
                }
            }
            break;
        case 'l': /* List the specified line */
            if (nStartLine == 0)
            {
                nStartLine = 1;
                while (nStartLine < nMaxLines)
                {
                    if (lLineIndex[nStartLine] != DELETED_LINE)
                    {
                        fseek(WorkFile,
                              lLineIndex[nStartLine], SEEK_SET);
                        fgets(szInputLine,
                              sizeof(szInputLine), WorkFile);
                        printf("%4d - %s",
                               nStartLine,
                               szInputLine);
                    }
                    else
                    {
                        printf("%4d ***DELETED LINE***\n",
                               nStartLine);
                    }
                    ++nStartLine;
                }
                nStartLine = 0;
            }
            else
            {
                while (nStartLine <= nEndLine)
                {
                    if (lLineIndex[nStartLine] != DELETED_LINE)
                    {
                        fseek(WorkFile,
                              lLineIndex[nStartLine], SEEK_SET);
                        fgets(szInputLine,
                              sizeof(szInputLine), WorkFile);
                        printf("%4d - %s",
                               nStartLine,
                               szInputLine);
                    }
                    else
                    {
                        printf("%4d ***DELETED LINE***\n",
                               nStartLine);
                    }
                    ++nStartLine;
                }
            }
            break;
        case 'd': /* Delete the specified line */
            if (nStartLine > 0 &&
                nStartLine < nMaxLines)
            {
                printf("Do you really want to delete line %d? (y|n) ",
                       nStartLine);
                chChar = getche();
                printf("\n");
                if (chChar == 'y' || chChar == 'Y')
                {
                    lLineIndex[nStartLine] = DELETED_LINE;
                }
            }
            break;
        case 'w': /* Write; continue editing? */
            szNewName[0] = '\0';
            tmpnam(szNewName);
            if (strlen(szNewName) == 0)
            {
                printf("Error getting a temporary file name...\n");
            }
            rename(szFileName, szNewName);
            DataFile = fopen(szFileName, "wt");
            nStartLine = 1;
            while (nStartLine < nMaxLines)
            {
                if (lLineIndex[nStartLine] != DELETED_LINE)
                {
                    fseek(WorkFile,
                          lLineIndex[nStartLine], SEEK_SET);
                    fgets(szInputLine,
                          sizeof(szInputLine), WorkFile);
                    fputs(szInputLine, DataFile);
                }
                ++nStartLine;
            }
            nStartLine = 0;
            fclose(DataFile);
            /* In this version, the original file is simply deleted.
* A better programming practice is to rename it to .BAK
* so the user can recover the original file.
*
* Question:
* When renaming to .BAK, does the user recover from the
* last save or the original file?
*/
            remove(szNewName); /* Could be renamed to .BAK */
            break;
        case 'q': /* Quit, with no save */
            break;
        default:
            printf("Error: the command '%c' is not supported!\n",
                   szCommand[0]);
            break;
        }
    }
    fclose(WorkFile);
    remove(szTempName);
    return (0);
}
int EditLine(
    char *szInputLine)
{
    char chChar = 'A'; // To fool while() the first time!
    int nCurrentChar = 0;
    printf("%s", szInputLine);
    while (chChar)
    {
        chChar = getch();
        if (chChar == '\0')
        {
            chChar = getch();
            switch (chChar)
            {
            case '\x4D':
                printf("%c", szInputLine[nCurrentChar]);
                ++nCurrentChar;
                break;
            default: /* No other keys implemented yet */
                printf("\a");
                break;
            }
        }
        else
        {
            switch (chChar)
            {
            case '\n':
            case '\x0d':
                chChar = '\0';
                break;
            default: /* Change current character to typed character */
                szInputLine[nCurrentChar] = chChar;
                printf("%c", szInputLine[nCurrentChar]);
                ++nCurrentChar;
                break;
            }
        }
    }
    printf("\n");
    return (1);
}