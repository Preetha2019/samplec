// g++ ./test.c -o a.exe 
// a.exe
// run programs from images attached for this
// 1[sort numbers](testMallocCreationsImg0.png) and ![sortTexts](testMallocCreationsImg1.png)
//https://pubs.opengroup.org/onlinepubs/9699919799/

#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions
//#include <process.h> // For exit(), etc.
#include <malloc.h>  // For malloc(), calloc(), realloc(), free()
#include <search.h>  // For qsort()...
#include <limits.h> //https://pubs.opengroup.org/onlinepubs/009695399/basedefs/limits.h.html
#include <stdlib.h> // atoi 
// atoi - https://pubs.opengroup.org/onlinepubs/9699919799/functions/atoi.html
// exit - https://pubs.opengroup.org/onlinepubs/9699919799/functions/exit.html
// qsort - https://pubs.opengroup.org/onlinepubs/9699919799/functions/qsort.html

#define MAX_CHARACTERS 50 // temporarily set to 50 instead of 32767 /* Total maximum characters */
#define MAX_LINES 10 //temporarily set to 10 instead of  15500      /* Total maximum lines */
#define BIGGEST_LINE 512      /* Largest line readable from keyboard */
#define MAX_BLOCKS 128       /* Allow 128 * MAX_CHARACTERS of memory */


int main(void);      // Define main() and the fact that this program
                    // does not use any passed parameters
int cmp(const void *, const void *); //define comparator function so it compiles. ideally in header file


char szInput[LINE_MAX];
char *szBuffer;
char *pBlocks[MAX_BLOCKS];
char *pBuffer[MAX_LINES];
int nCurrentBlock = 0;
int nBufferPointer = {MAX_CHARACTERS};
int nLine = 0;
int ln=0;



int main() {
    //char *pstring=(char *)malloc(LINE_MAX);int i;
// https://pubs.opengroup.org/onlinepubs/009695399/functions/fgets.html
    while(fgets(szInput, BIGGEST_LINE, stdin) != NULL)
    {
        printf("fgets: %s.", szInput);
        if(szInput[0] == '\n') 
        {
            break;
        }

        if ((nBufferPointer + strlen(szInput)) > MAX_CHARACTERS)
        { // The line won’t fit! Allocate new memory:
            szBuffer = (char *)malloc(MAX_CHARACTERS);
            // sending to standard error output as warning
            fprintf(stderr, " Allocating buffer (32K).\n");
            nBufferPointer = 0;
            pBlocks[nCurrentBlock] = szBuffer;
            ++nCurrentBlock;
            if (szBuffer == NULL)
            {
                fprintf(stderr, "System sort memory exceeded, can't sort.\n");
                //exit(16);
                break;
            }
        }

        pBuffer[nLine] = &szBuffer[nBufferPointer];
        strcpy(pBuffer[nLine], szInput);
        // The + 1 skips over the terminating NULL in each string.
        nBufferPointer += strlen(szInput) + 1;
        printf("nline: %d \n",nLine);
        if (++nLine >= MAX_LINES)
        { // Too many lines! End the program.
            fprintf(stderr, "Too many lines—cannot sort.\n");
            //exit(16);
            break;
        }
    }

    //
    // Now sort the input lines
    //
    fprintf(stderr, "Sorting, %d lines, in %d buffers.\n", nLine, nCurrentBlock);
    //qsort is a standard c program to sort when a comparator is given to compare two different lienes
    qsort((void *)pBuffer,
          (size_t)nLine,
          sizeof(char *),
          cmp);
    //
    fprintf(stderr, "Writing output...\n");
    for (int i = 0; i < nLine; i++)
    {
        printf("%s\n", pBuffer[i]);
    }
    fprintf(stderr, "\n");

    printf("The printing string drama. \n");
    return 0;
}


int cmp(const void *a, const void *b)
{//function to compare two characters that are passed. qsort calls this for each character in the two lines being compared
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;
    int n1 = atoi(pa);
    int n2 = atoi(pb);
    return ((n1 > n2)) - (n1 < n2);
}
