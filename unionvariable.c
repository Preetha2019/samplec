#include<stdio.h>
union variables
{
    char a;
    int b ;
    float c ;
};
int main()
{
    union variables var;
    printf("String address of var is%p\n",var);
    var.a='f';
    printf("String address of 1st member is%p\n",var.a);
    var.b=10;
    printf("String address of 2nd member is%p\n",var.b);
    var.c=11.5;
    printf("String address of 3rd member is%p\n",var.c);
    return(0);
}