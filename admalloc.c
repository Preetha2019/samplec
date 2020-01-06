#include <stdio.h>  // Make includes first in program
#include <string.h> // For string functions
#include <malloc.h> // For memory allocation functions
int main(void);     // Define main() and the fact that this
// program doesn’t use any passed parameters
int main()
{
    int i = 0;
    int j = 0;
    int *nPointer[100] = {NULL};
    int nSize = 32767;
    long lTotalBytes = 0;
    while (nSize > 0 && // Make nSize valid
           nSize <= 32767 &&
           lTotalBytes < 2000000) // Not more than 2M will be allocated
    {
        nPointer[i] = (int *)malloc(nSize);
        if (nPointer[i] != NULL)
        {
            ++i;
            lTotalBytes += (nSize * sizeof(int));
            printf("Allocated %5u bytes, total %10ld\n",
                   nSize,
                   lTotalBytes);
        }
        else
        {
            printf("Couldn't allocate %5u bytes, total %10ld\n",
                   nSize,
                   lTotalBytes);
            nSize /= 2;
        }
    }
    for (j = 0; j < i; j++)
    {
        free(nPointer[j]);
        nPointer[j] = NULL;
    }
    return (0);
}