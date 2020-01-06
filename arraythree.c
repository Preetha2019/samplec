#include <stdio.h>
#include <conio.h>
int main()
{
    int arr[10][10][10], d1, d2, d3, i, j, k;
    printf("Enter the size of Three dimensions:");
    scanf("%d\t,%d\t,%d\t ", d1, d2, d3);
    printf("Enter the elements of array:\n");
    for (i = 0; i < d1; i++)
        for (j = 0; j < d2; j++)
            for (k = 0; k < d3; k++)
            {
                printf("The values of an array:");
                scanf("%d\n", arr[i][j][k]);
            }
}