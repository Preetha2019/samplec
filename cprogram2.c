#include<stdio.h>
int main()
{
	int n;
	printf("Enter any integer\n");
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("\n The given number %d is even",n);
	}
	else
	{
		printf("\n The given number %d is odd",n);
	}
}

