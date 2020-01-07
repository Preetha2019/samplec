#include <stdio.h>
#include <string.h>
int main(void);
int main()
{
    char szMyName[] = “John Q.Public”;
    char szYourName[50];
    szYourName[0] = ‘\0’;
    strcpy(szYourName, szMyName);
    printf(“MyName ‘% s’ YourName ‘% s’ \n”,
           szMyName,
           szYourName);
    strcpy(szMyName, “My New Name”);
    printf(“MyName ‘% s’ YourName ‘% s’ \n”,
           szMyName,
           szYourName);
    printf(“Before
           : MyName ‘% s’ Constant ‘% s’ \n”,
             szMyName,
 “My New Name”);
    strcpy(“My New Name”,
           szYourName);
    printf(“After
           : MyName ‘% s’ Constant ‘% s’ \n”,
             szMyName,
 “My New Name”);
    return (0);
}