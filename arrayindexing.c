#include <stdio.h> // Make includes first part of file
#define MAX_COMPANIES 3
#define MAX_CARS 5
#define MAX_MODELS 10
// This is a 10-element array.
int nArray1[MAX_CARS];
// This is a 10-by-5 array.
int nArray2[MAX_CARS][MAX_MODELS];
// This is a 10-by-5-by-3 array.
int nArray3[MAX_CARS][MAX_MODELS][MAX_COMPANIES];
int main(void); // Define main() and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    int i;
    int j;
    int k;
    for (i = 0; i < MAX_CARS; i++)
    {
        nArray1[i] = i;
        for (j = 0; j < MAX_MODELS; j++)
        {
            nArray2[i][j] = (j * 10) + i;
            for (k = 0; k < MAX_COMPANIES; k++)
            {
                nArray3[i][j][k] = (i * 100) + (j * 10) + k;
            }
        }
    }
    for (i = 0; i < MAX_CARS; i++)
    {
        printf("%3.3d ", *(nArray1 + i));
    }
    printf("\n");
    for (i = 0; i < (MAX_CARS * MAX_MODELS); i++)
    {
        if ((i % MAX_MODELS) == 0)
        {
            printf("\n");
        }
        printf("%3.3d ", *(*(nArray2) + i));
    }
    printf("\n");
    for (i = 0; i < (MAX_COMPANIES * MAX_CARS * MAX_MODELS); i++)
    {
        if ((i % MAX_COMPANIES) == 0)
        {
            printf("\n");
        }
        printf("%3.3d ", *(*(*(nArray3)) + i));
    }
    printf("\n");
    // Notice that string concatenation makes the printf() format
    // string more readable. Also note the blank line between the
    // format string and the other arguments to printf().
    printf(
        "&nArray3 %4.4X \n"
        "&nArray3[0][0][0] %4.4X \n"
        "nArray3 %4.4X \n"
        "*(nArray3) %4.4X \n"
        "*(*(nArray3)) %4.4X \n"
        "*(*(*(nArray3))) %d \n",
        &nArray3,
        &nArray3[0][0][0],
        nArray3,
        *(nArray3),
        *(*(nArray3)),
        *(*(*(nArray3))));
    printf("\n");
    printf(
        "&nArray3 %4.4X \n"
        "&nArray3[0][0][0] %4.4X \n"
        "nArray3 + 1 %4.4X \n"
        "*(nArray3 + 1) %4.4X \n"
        "*(*(nArray3 + 1) + 1) %4.4X \n"
        "*(*(*(nArray3 + 1) + 1) + 1) %d \n"
        "*(*(*(nArray3)) + ((1 * (10 * 3)) + (1 * 3) + (1))) %d \n"
        "nArray3[1][1][1] %d\n",
        &nArray3,
        &nArray3[0][0][0],
        nArray3 + 1,
        *(nArray3 + 1),
        *(*(nArray3 + 1) + 1),
        *(*(*(nArray3 + 1) + 1) + 1),
        *(*(*(nArray3)) + ((1 * (10 * 3)) + (1 * 3) + (1))),
        nArray3[1][1][1]);
    printf("\n");
    return (0);
}