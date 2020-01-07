#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Addition of two numbers\n");
	printf("\tPlease Enter the First Number\t", &a);
	printf("\tPlease Enter the Second Number\t", &b);
	c = a + b;
	printf("Sum of two numbers = %d\n", c);
	return (0);
}
