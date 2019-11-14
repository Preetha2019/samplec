#include <stdio.h> // Make includes first part of file
int main(void); // Declare main() and the fact that this program doesn’t
 // use any passed parameters
int main()
{ // First opening brace for each function is at the left margin
int i; // Used as a for loop index
int nCount = 0; // Always initialize your auto variables
char szString[] = "We want to impress you %d\n";
 for (i = 0; i < 5; i++) // Spaces around operators
 { // Brace on its own line
 nCount += printf(szString, i + 1);
 } /* for (i...) */
 return (nCount); // Brackets around all return values
} 