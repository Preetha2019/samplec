#include <stdio.h>
int main()
{
    int a = 0;
    float Area, Circum;
    printf("Enter the value of a :", a);
    scanf("%d", &a);
    switch (a)
    {
    case 1:
    case 19:
        printf("Area:");
        Area = (float)(3.14) * a * a;
        printf("\n Area of circle is:%6.2f", Area);
        break;
    case 2:
        printf("Circum");
        Circum = (float)(3.14) * a * 2;
        printf("\n Circum of circle is:%6.2f", Circum);
        break;
    }
}