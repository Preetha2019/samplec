#include<stdio.h> 
#include<conio.h> 
#include <factorial.h>
int main() 
{ 
int number,f,i; 
printf("\nEnter an Integer:"); 
scanf("%d", &number); 
if(number<0)
   {
         printf("Error! Enter the valid number");
    }
    else
    {
f= Fa#ctorial(number); 
printf("Factorial of %d is:%d", number, f); 
return(0); 
    }
}