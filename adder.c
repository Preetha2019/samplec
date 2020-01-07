#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions.
#include <limits.h> // For integer value limits.
#define TRUE 1
#define FALSE 0
int main(void); // Define main() and the fact that this program doesn’t
// use any passed parameters.
int DoAdd(int *nResult, int nFirstValue, int nSecondValue);
int main()
{
    int nFirst = 3000;
    int nSecond = 700;
    int nSum = 0;
    printf("BEFORE: nSum = %4d nFirst = %4d nSecond = %4d\n",
           nSum,
           nFirst,
           nSecond);
    if (!DoAdd(&nSum, nFirst, nSecond))
    {
        printf("%d + %d don’t fit in an int\n",
               nFirst,
               nSecond);
    }
    printf("AFTER: nSum = %4d nFirst = %4d nSecond = %4d\n,
           nSum,
           nFirst,
           nSecond);
    return (0);
}
int DoAdd(
    int *nResult,
    int nFirstValue,
    int nSecondValue)
{
    if ((long)nFirstValue + (long)nSecondValue > (long)INT_MAX)
    {
        return (FALSE);
    }
    else
    {
        *nResult = nFirstValue + nSecondValue;
    }
    return (TRUE);
}