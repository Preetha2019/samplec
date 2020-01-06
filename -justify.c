#include <stdio.h> // Make includes first part of file
#include <string.h> // For string functions.
#include <stdlib.h> // Standard include items.
#include <process.h> // For exit() etc.
#define LEFT 1
#define RIGHT 2
#define JUSTIFY 3
#define INNAME 1
#define OUTNAME 2
#define WIDTH 3
#define LAST_THING 4
#define ARG_LEFT 'l'
#define ARG_RIGHT 'r'
#define ARG_JUSTIFY 'j'
#define ARG_SLASH '/'
#define ARG_DASH '-'
#define ARG_HELP '?'
#define NOINNAME 1
#define NOOUTNAME 2
#define BAD_WIDTH 3
#define BAD_PARM 4
#define BAD_OPTION 5
#define NAME_MISSING 6
int main( // Define main() and the fact that this program uses
int argc, // the passed parameters.
char *argv[],
char *envp[]
);
void GiveHelp(
int nLevel,
char *psItem);
int main(
int argc,
char *argv[],
char *envp[]
)
{
char *pszTemp;
char szBuffer[129]; // Temporary work buffer.
char szProgram[30];
char szInputFile[132]; // Make large enough for your OS.
char szOutputFile[132]; // Make large enough for your OS.
/* strings for _splitpath() (which parses a filename) */
char szDrive[_MAX_DRIVE];
char szDir[_MAX_DIR];
char szFname[_MAX_FNAME];
char szExt[_MAX_EXT];
int i;
int j;
int nCurrentParameter = INNAME;
int nTempWidth = 0;
int nLineWidth = 80;
int nJustification = RIGHT ;
if (argc <= 2)
{
GiveHelp(argc, NULL);
return(16);
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
for (j = 1; j < strlen(pszTemp); j++)
{
switch(pszTemp[j])
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
case ARG_HELP:
GiveHelp(NOINNAME, NULL);
exit(4);
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
switch(nCurrentParameter)
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
{ /* Didn't get two filenames! */
GiveHelp(NAME_MISSING, NULL);
return(16);
}
printf("\n");
printf(
"%s would read the file '%s' and write the file '%s'\n\n",
szProgram,
szInputFile,
szOutputFile);
switch(nJustification)
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
/* In the final version of this program, the files would
* be opened next and the input file would be read into a buffer,
* formatted according to the wishes of the user, and written
* to the output file. At the end, the files would be closed,
* and perhaps some statistical information could be
* presented to the user.
*/
return (0);
}
void GiveHelp(
int nLevel,
char *psItem)
{
printf("\n");
switch(nLevel)
{
case NOINNAME:
case NOOUTNAME: // Not enough parameters!
printf(
"FORMAT [-r|-l|-j] inputfile outputfile width\n"
" where \n"
" Options - -r (or /r) to right align \n"
" -l (or /l) to left align \n"
" -j (or /j) to justify\n"
"\n"
" inputfile - is the input file name \n"
" outputfile - is the output file name \n"
"\n"
" width is the desired output width (20 to 128)\n"
" (default is 80 characters).\n"
"\n"
" Note: lines are concatenated, paragraph breaks are\n"
" signaled with a blank line\n\n");
break;
case BAD_WIDTH:
printf(
"The width parameter must be between 20 and 128!\n"
"the width is ignored\n");
break;
case BAD_PARM:
printf("Excessive parameters have been entered\n");
/* Force a display of full help! */
GiveHelp(NOINNAME, NULL);
break;
case BAD_OPTION:
printf("'%c' is an invalid option! (Use only -l, -r or -j)\n",
*psItem);
break;
case NAME_MISSING:
printf("One or both of the required file names is missing!\n");
/* Force a display of full help! */
GiveHelp(NOINNAME, NULL);
break;
default:
printf(
"An unspecified error occurred! FORMAT has ended!\n"
);
exit(16);
break;
}
}