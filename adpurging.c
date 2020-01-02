#include <stdlib.h> // For standard functions
#include <stdio.h> // Make includes first part of file
#include <string.h> // For string functions
#include <process.h> // For exit(), etc
#include <malloc.h> // For malloc(), calloc(), realloc(), free()
#include <search.h> // For qsort()...
int main(int argc, char *argv[], char *envp[]);
int compare(char **arg1, char **arg2);
#define BIGEST_LINE 512 /* The largest readable line */
#define NEED_RECORD 1 /* A record is needed from the file */
#define END_OF_FILE 2 /* This file is finished */
#define ALL_OK 3 /* No record needed, not EOF */
/* Although these variables are defined as external, they could
* be defined inside the function or allocated dynamically,
* depending on the program’s needs and available memory.
*/
char szInput[BIGEST_LINE];
char szInput1[BIGEST_LINE];
char szInput2[BIGEST_LINE];
int main(
int argc,
char *argv[],
char *envp[]
)
{
FILE *InFile1;
FILE *InFile2;
FILE *OutFile;
char szProgram[30];
/* Strings for _splitpath(), which parses a file name */
char szDrive[_MAX_DRIVE];
char szDir[_MAX_DIR];
char szFname[_MAX_FNAME];
char szExt[_MAX_EXT];
int i;
int j;
int nCompare = 0;
int nFileOneStatus = NEED_RECORD;
int nFileTwoStatus = NEED_RECORD;
/* Use fprintf(stderr...) to force prompts and error messages to be
* displayed on the user’s screen regardless of whether the output
* has been redirected.
*/
_splitpath(argv[0],
szDrive,
szDir,
szFname,
szExt);
strncpy(szProgram, szFname, sizeof(szProgram) - 1);
if (argc <= 3)
{
fprintf(stderr,
"\n"
"%s -\n"
"\n"
"Peter's PURGEFILE: Merges two sorted files, \n"
" purging all duplicate lines!\n"
"\n"
" inputfile1 and inputfile2 can be the same file,\n"
" if you want to de-dup only one file.\n"
"\n"
" syntax: \n"
"\n"
" %s inputfile1 inputfile2 outputfile \n"
"\n",
szProgram,
szProgram);
return(16);
}
InFile1 = fopen(argv[1], "rt");
InFile2 = fopen(argv[2], "rt");
OutFile = fopen(argv[3], "wt");
while (
nFileOneStatus != END_OF_FILE ||
nFileTwoStatus != END_OF_FILE)
{
while(
nFileOneStatus == NEED_RECORD ||
nFileTwoStatus == NEED_RECORD)
{
switch(nFileOneStatus)
{
case NEED_RECORD: /* Read a record */
if (fgets(szInput, sizeof(szInput), InFile1) == NULL)
{
nFileOneStatus = END_OF_FILE;
}
else
{
if (strcmp(szInput, szInput1) != 0)
{
strcpy(szInput1, szInput);
nFileOneStatus = ALL_OK;
}
}
break;
case ALL_OK: /* Nothing needed */
break;
case END_OF_FILE: /* Can’t do anything */
break;
}
switch(nFileTwoStatus)
{
case NEED_RECORD: /* Read a record */
if (fgets(szInput, sizeof(szInput), InFile2) == NULL)
{
nFileTwoStatus = END_OF_FILE;
}
else
{
if (strcmp(szInput, szInput2) != 0)
{
strcpy(szInput2, szInput);
nFileTwoStatus = ALL_OK;
}
}
break;
case ALL_OK: /* Nothing needed */
break;
case END_OF_FILE: /* Can’t do anything */
break;
}
}
if (nFileOneStatus == END_OF_FILE)
{
if (nFileTwoStatus != END_OF_FILE)
{
fputs(szInput2, OutFile);
nFileTwoStatus = NEED_RECORD;
}
}
else
{
if (nFileTwoStatus == END_OF_FILE)
{
if (nFileOneStatus != END_OF_FILE)
{
fputs(szInput1, OutFile);
nFileOneStatus = NEED_RECORD;
}
}
else
{
nCompare = strcmp(szInput1, szInput2);
if (nCompare < 0)
{/* File one is written */
fputs(szInput1, OutFile);
nFileOneStatus = NEED_RECORD;
}
else
{
if (nCompare > 0)
{/* File two is written */
fputs(szInput2, OutFile);
nFileTwoStatus = NEED_RECORD;
}
else
{/* They are the same; write one and discard the
other. */
fputs(szInput1, OutFile);
nFileOneStatus = NEED_RECORD;
nFileTwoStatus = NEED_RECORD;
}
}
}
}
}
fclose(InFile1);
fclose(InFile2);
fclose(OutFile);
return (0);
}