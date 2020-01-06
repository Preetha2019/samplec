#include <search.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>
int compare(const void *, const void *);
int main()
{
    int i;
    int *nArray = NULL;
    int nArraySize = 0;
    while (nArraySize < 10 || nArraySize > 30000)
    {
        printf("Enter the number of random integers to sort (10 to \
30,000): ");
        scanf("%d", &nArraySize);
        if (nArraySize < 10 || nArraySize > 30000)
        {
            printf("Error: must be between 10 and 30,000!\n");
        }
        nArray = (int *)calloc(sizeof(int), nArraySize);
        if (nArray == NULL)
        {
            printf("Error: couldn't allocate that much memory!\n");
            nArraySize = 0;
        }
    }
    srand((unsigned)time(NULL));
    for (i = 0; i < nArraySize; i++)
    {
        nArray[i] = rand();
    }
    qsort(nArray, nArraySize, sizeof(int), compare);
    for (i = 0; i < nArraySize; i += 10)
    {
        printf("%5d %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
               nArray[i],
               nArray[i + 1],
               nArray[i + 2],
               nArray[i + 3],
               nArray[i + 4],
               nArray[i + 5],
               nArray[i + 6],
               nArray[i + 6],
               nArray[i + 7],
               nArray[i + 8],
               nArray[i + 9]);
    }
    free(nArray);
    return (0);
}
int compare(
    const void *a,
    const void *b)
{
    return (*(int *)a - *(int *)b);
}