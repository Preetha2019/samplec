#include<stdio.h>
int main(void)
{
    int nCounter=0;
    {int nCountLoop=0;
    do
    {
        nCountLoop+=3;
        printf("nCountLoop is =%d?\n", nCountLoop);
    }
    while(++nCounter<=10);
    }
    printf("Ended, nCounter is=%d/\n", nCounter);
    return (0);
}