#include<stdio.h>
int Even_Sum(int a[6]);
int main()
{
    int i, Result;
    int b[]={-123, 32, 45, 50, 100, 1000};
    printf(" \t The elements of an array are:");
    for(i=0;i<6;i++)
    {
    printf("%d\t", b[i]);
    }
    Result= Even_Sum(b);
    printf("\n The sum of even numbers in an array=%d", *(Result+1));
    return(0);
}
int Even_Sum(int a[6])
{
    int Even_Sum=0, i;
    for(i=0;i<6;i++)
    {
        if(a[i]%2==0)
        {
            Even_Sum +=a[i];
        }
    }
    return Even_Sum;
}
