#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i;
    n=6;
    int a[i]={-123,32,45,50,100,1000};
    for(i=0;i<n;i++)
    {
    printf(" \t The elements of an array are:\n");
    printf("%d", a[i]);
    Even_Sum(a[i]);
    }
    int Even_Sum(int a[i])
    {
        int Even_Sum=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            Even_Sum=Even_Sum+a[i];
        }
    }
    printf("\n The Sum of even numbers in an array=%d",Even_Sum);
    return(0);
}
