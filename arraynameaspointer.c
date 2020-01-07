#include <stdio.h>  // Make includes first part of file
#include <malloc.h> // For memory allocation.
#define MAX_COMPANIES 3
#define MAX_CARS 5
#define MAX_MODELS 10
int main(void); // Define main() and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int(*nPointer)[MAX_MODELS];
    int i;
    int j;
    int k;
    nPointer = (int(*)[MAX_MODELS])
        malloc(MAX_CARS * sizeof(*nPointer));
    for (i = 0; i < MAX_CARS; i++)
    {
        for (j = 0; j < MAX_MODELS; j++)
        {
            nPointer[i][j] = (i * 100) + j;
        }
    }
    for (i = 0; i < MAX_CARS; i++)
    {
        for (j = 0; j < MAX_MODELS; j++)
        {
            printf("nPointer[%d][%d] = %4d\n",
                   i,
                   j,
                   nPointer[i][j]);
        }
    }
    free(nPointer);
    return (0);
}