#include <stdio.h> // Make includes first part of file
#include <string.h> // For string functions
#include <process.h> // For exit(), etc.
#include <malloc.h> // For malloc(), calloc(), realloc(), free()
#include <search.h> // For qsort()...
int main(void); // Define main() and the fact that this program
// does not use any passed parameters
int compare(void *arg1, void *arg2);
#define MAX_CHARACTERS 32767 /* Total maximum characters */
#define MAX_LINES 15500 /* Total maximum lines */
#define BIGEST_LINE 512 /* Largest line readable from keyboard */
#define MAX_BLOCKS 128 /* Allow 128 * MAX_CHARACTERS of memory */
/* Although these variables are defined as external, they could
* be defined inside the function or allocated dynamically,
* depending on the program’s needs and the available memory.
*/
char szInput[BIGEST_LINE];
char *szBuffer;
char *pBlocks[MAX_BLOCKS];
char *pBuffer[MAX_LINES];
int nCurrentBlock = 0;
int nBufferPointer = {MAX_CHARACTERS};
int nLine = 0;
int main()
{
int i;
/* Use fprintf(stderr...) to force prompts and error messages
* to be displayed on the user’s screen regardless of whether
* the output has been redirected.
*/
fprintf(stderr,
"\n"
"Peter's SORTFILE: Sorts large files at the speed of light!\n"
"\n"
" syntax: \n"
" sortfile <inputfile >outputfile \n"
"\n"
" where: \n"
" the program's I/O is redirected\n\n");
fprintf(stderr, "Reading input...\n");
while (gets(szInput))
{
if ((nBufferPointer + strlen(szInput)) > MAX_CHARACTERS)
{ // The line won’t fit! Allocate new memory:
szBuffer = (char *)malloc(MAX_CHARACTERS);
fprintf(stderr, " Allocating buffer (32K).\n");
nBufferPointer = 0;
pBlocks[nCurrentBlock] = szBuffer;
++nCurrentBlock;
if (szBuffer == NULL)
{
fprintf(stderr, "System sort memory exceeded, can't \
sort.\n");
exit(16);
}
}
pBuffer[nLine] = &szBuffer[nBufferPointer];
strcpy(pBuffer[nLine], szInput);
// The + 1 skips over the terminating NULL in each string.
nBufferPointer += strlen(szInput) + 1;
if (++nLine >= MAX_LINES)
{ // Too many lines! End the program.
fprintf(stderr, "Too many lines—cannot sort.\n");
exit(16);
}
}
//
// Now sort the input lines
//
fprintf(stderr, "Sorting, %d lines, in %d buffers.\n",
nLine,
nCurrentBlock);
qsort((void *)pBuffer,
(size_t)nLine,
sizeof(char *),
compare);
fprintf(stderr, "Writing output...\n");
for (i = 0; i < nLine; i++)
{
printf("%s\n", pBuffer[i]);
}
fprintf(stderr, "\n");
for (i = 0; i < nCurrentBlock; i++)
{
free(pBlocks[i]);
}
return (0);
}
int compare(
char **arg1,
char **arg2)
{
return strcmp(*(char**)arg1, *(char**)arg2);
}