#include <stdio.h>
#include <math.h>

int main()
{
    int a[] = {19, 11, 15, 4, 22, 26, 14};
    int i,j;

    i = 0;
    while (i<7)
    {

        //finding the smallest number in the subarray
        int index_of_smallest = i;
        for(j=i; j<7; j++)
        {
            if (a[j]<a[index_of_smallest])
                index_of_smallest = j;
        }

        //swapping
        int temp = a[i];
        a[i] = a[index_of_smallest];
        a[index_of_smallest] = temp;

        i++;
    }

    for(i=0;i<7;i++)
        printf("%d\n",a[i]);

    return 0;
}