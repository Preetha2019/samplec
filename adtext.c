#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions
#include <process.h> // For abort(), spawn(), exit(), etc.
#include <malloc.h>  // For memory allocation functions
#include <conio.h>   // For console getch(), getche(), etc.
#include <ctype.h>   // For character-conversion functions
#define MAX_LINES 25
#define MAX_LENGTH 80
char szSaying[MAX_LINES][MAX_LENGTH] =
    {
        "\nFirestone's Law of Forecasting: \n",
        "\n Chicken Little has to be right only once. \n",
        "\n \n\n",
        "\nManly's Maxim: \n",
        "\n Logic is a systematic method of coming to \n",
        "\n the wrong conclusion with confidence. \n",
        "\n \n\n",
        "\nMoer's truism: \n",
        "\n The trouble with most jobs is the job holder's \n",
        "\n resemblance to being one of a sled dog team. No one \n",
        "\n gets a change of scenery except the lead dog. \n",
        "\n \n\n",
        "\nCannon's Comment: \n",
        "\n If you tell the boss you were late for work because you \n",
        "\n had a flat tire, the next morning you will have a flat tire.\n",
        "\n \n\n",
};
int main(void); // Define main() and the fact that this program
// does not use any passed parameters
int main()
{
    FILE *DataFile = NULL;
    char szFileName[25];
    char szBuffer[257];
    char szMode[5] = "w\0\0";
    int i;
    int nNumberRecords = 0;
    int nRecord = 0;
    int nResult = 0;
    long lNewPosition = 0;
    long lOldPosition = 0;
    char t, b;
    /* Prompt the user to supply the mode, either lowercase t
* for a text file or lowercase b for a binary file.
*/
    while (DataFile == NULL)
    {
        if (szMode[1] != 'b' && szMode[1] != 't')
        {
            printf("\nPlease enter 't' for text file, 'b' for binary: ");
            /* For non-Microsoft C systems, use tolower() (no leading underscore) */
            szMode[1] = tolower(getche());
        }
        printf("\nPlease enter name of file to write: ");
        gets(szFileName);
        DataFile = fopen(szFileName, szMode);
        if (DataFile == NULL)
        {
            printf("ERROR: File '%s' couldn't be opened.\n", szFileName);
        }
    }
    printf("\n");
    switch (szMode[1])
    {
    case 't':
        printf("Demo of a text file\n\n");
        break;
    case 'b':
        printf("Demo of a binary file\n\n");
        break;
    }
    for (i = 0; strlen(szSaying[i]); i++)
    {
        lOldPosition = ftell(DataFile);
        fwrite(szSaying[i],
               strlen(szSaying[i]),
               1,
               DataFile);
        lNewPosition = ftell(DataFile);
        printf(
            "Start position %5ld "
            "end %5ld, "
            "strlen(...) %d but "
            "wrote %5ld bytes'\n",
            lOldPosition,
            lNewPosition,
            strlen(szSaying[i]),
            (long)lNewPosition - lOldPosition);
    }
    fclose(DataFile);
    printf("\n");
    switch (szMode[1])
    {
    case 't':
        printf("Note the bytes written don't"
               " equal the string's length\n\n");
        break;
    case 'b':
        printf("Note the bytes written always"
               " equal the string's length\n\n");
        break;
    }
    return (0);
}