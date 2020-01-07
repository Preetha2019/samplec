#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions.
#include <stdlib.h>  // Standard include items.
#include <process.h> // For exit() etc.
int main()
{
    unsigned char cTemp[10];
    unsigned char *pcTemp;
    int nYear = 1992;
    long int lYearYear = 19921992;
    char szHello[] = "Hello";
    pcTemp = (unsigned char *)&nYear;
    cTemp[0] = *(pcTemp++);
    cTemp[1] = *(pcTemp);
    printf("nYear = %d decimal, %4.4X hex, in memory %2.2X %2.2X\n",
           nYear,
           nYear,
           cTemp[0],
           cTemp[1]);
    pcTemp = (unsigned char *)&lYearYear;
    cTemp[0] = *(pcTemp++);
    cTemp[1] = *(pcTemp++);
    cTemp[2] = *(pcTemp++);
    cTemp[3] = *(pcTemp);
    printf("lYearYear = %ld decimal %8.8lX hex, in memory %2.2X %2.2X \
%2.2X %2.2X\n",
           lYearYear,
           lYearYear,
           cTemp[0],
           cTemp[1],
           cTemp[2],
           cTemp[3]);
    pcTemp = (unsigned char *)&szHello[0];
    cTemp[0] = *(pcTemp++); // H
    cTemp[1] = *(pcTemp++); // e
    cTemp[2] = *(pcTemp++); // l
    cTemp[3] = *(pcTemp++); // l
    cTemp[4] = *(pcTemp++); // o
    cTemp[5] = *(pcTemp++); // \0 (NULL)
    printf("szHello = '%s' (string), in memory '%c' '%c' '%c' '%c' '%c' \
'%c' \n",
           szHello,
           cTemp[0],
           cTemp[1],
           cTemp[2],
           cTemp[3],
           cTemp[4],
           cTemp[5]);
    return (0);
}