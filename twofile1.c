#define EXTERN extern
extern void GiveHelp(int nLevel, char *psItem);
#include "twofile.h" /* TWOFILE’s include has all other #includes. */
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    char *pszTemp;
    char szBuffer[129]; /* Temporary work buffer. */
    char szProgram[30];
    char szInputFile[132];  /* Make large enough for your OS. */
    char szOutputFile[132]; /* Make large enough for your OS. */
    /* strings for _splitpath() (which parses a file name) */
    char szDrive[_MAX_DRIVE];
    char szDir[_MAX_DIR];
    char szFname[_MAX_FNAME];
    char szExt[_MAX_EXT];
    int i;
    int j;
    int nCurrentParameter = INNAME;
    int nTempWidth = 0;
    int nLineWidth = 80;
    int nJustification = LEFT;
    if (argc <= 2)
    {
        GiveHelp(argc, NULL);
        return (16);
    }
    _splitpath(argv[0],
               szDrive,
               szDir,
               szFname,
               szExt);
    strncpy(szProgram, szFname, sizeof(szProgram) - 1);
    for (i = 1; argv[i]; i++)
    {
        if (argv[i][0] == '/' || argv[i][0] == '-')
        { /* You have an argument, convert to lowercase, and test. */
            pszTemp = strlwr(argv[i]);
            for (j = 1; j < (int)strlen(pszTemp); j++)
            {
                switch (pszTemp[j])
                {
                case ARG_LEFT:
                    nJustification = LEFT;
                    break;
                case ARG_RIGHT:
                    nJustification = RIGHT;
                    break;
                case ARG_JUSTIFY:
                    nJustification = JUSTIFY;
                    break;
                case ARG_SLASH:
                case ARG_DASH:
                    break;
                default:
                    GiveHelp(BAD_OPTION, &pszTemp[j]);
                    break;
                }
            }
        }
        else
        { /* Either a filename or width. */
            switch (nCurrentParameter)
            {
            case INNAME:
                strcpy(szInputFile, argv[i]);
                nCurrentParameter = OUTNAME;
                break;
            case OUTNAME:
                strcpy(szOutputFile, argv[i]);
                nCurrentParameter = WIDTH;
                break;
            case WIDTH:
                sscanf(argv[i], "%d", &nTempWidth);
                if (nTempWidth < 20 || nTempWidth > 128)
                {
                    GiveHelp(BAD_WIDTH, NULL);
                }
                else
                {
                    nLineWidth = nTempWidth;
                }
                nCurrentParameter = LAST_THING;
                break;
            default:
                GiveHelp(BAD_PARM, NULL);
                break;
            }
        }
    }
    if (nCurrentParameter < WIDTH)
    { /* Didn’t get two file names! */
        GiveHelp(NAME_MISSING, NULL);
        return (16);
    }
    printf("\n");
    printf(
        "%s would read the file '%s' and write the file '%s'\n\n",
        szProgram,
        szInputFile,
        szOutputFile);
    switch (nJustification)
    {
    case LEFT:
        printf("The lines would be %d characters long, left \
aligned\n",
               nLineWidth);
        break;
    case RIGHT:
        printf("The lines would be %d characters long, right \
aligned\n",
               nLineWidth);
        break;
    case JUSTIFY:
        printf("The lines would be %d characters long, justified\n",
               nLineWidth);
        break;
    }
    /* In the final version of this program, the files next
* are opened, and the input file is read into a buffer,
* formatted according to what the user wants, and written
* out to the output file. At the end, the files are closed,
* and perhaps some statistical information can be presented
* to the user.
*/
    printf("HelloWorld");
    return (0);
}