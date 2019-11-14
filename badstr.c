/* BADSTR, written 12 May 1992 by Peter D. Hipson */
/* An example of changing a string constant. */
#include <stdio.h> // Make includes first part of file
#include <string.h>
int main(void); // Declare main() and the fact that this program doesn’t
 // use any passed parameters.
int main()
{
char szMyName[] = “John Q. Public”;
char szYourName[50];
 szYourName[0] = ‘\0’;
 strcpy(szYourName, szMyName); // szYourName is now the same as
 // szMyName.
 printf(“MyName ‘%s’ YourName ‘%s’ \n”,
 szMyName,
 szYourName);
 strcpy(szMyName, “My New Name”); // strcpy() actually receives the
 // address of the constant
 // “My New Name”
 printf(“MyName ‘%s’ YourName ‘%s’ \n”,
 szMyName,
 szYourName);
 printf(“Before: MyName ‘%s’ Constant ‘%s’ \n”,
 szMyName,
 “My New Name”);
 strcpy(“My New Name”, // strcpy() actually receives the address
 szYourName); // of the constant “My New Name”
 // This will fail and destroy the constant!
 printf(“After: MyName ‘%s’ Constant ‘%s’ \n”,
 szMyName,
 “My New Name”); // The result can be seen because QuickC
 // for Windows keeps identical strings
 // constants with only a single copy in
 // memory, and they are not read-only.
 return (0);
}
