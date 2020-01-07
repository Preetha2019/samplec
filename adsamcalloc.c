#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
#include <malloc.h> // For memory allocation functions
int main(void);     // Define main() and establish that this
// program does not use any passed parameters
int main()
{
    int i = 0;
    int j = 0;
    int *nPointer[100] = {NULL};
    int nSize = 32767;
    long lTotalBytes = 0;
    while (nSize > 0 && // Make nSize valid
           nSize <= 32767 &&
           lTotalBytes < 2000000) // No more than 2M will be allocated
    {
        nPointer[i] = (int *)calloc(nSize, sizeof(int));
        printf("npointer is:%d, *nPointer[10]");
    }
    return 0;
}