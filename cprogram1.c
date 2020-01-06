#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Addition of two numbers\n");
	printf("\t Enter the First Number :");
	scanf("%d", &a);
	printf("\t Enter the Second Number:");
	scanf("%d", &b);
	c = a + b;
	printf("Sum of two numbers = %d\n", c);
	return (0);
}
