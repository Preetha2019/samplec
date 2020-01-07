#include <stdio.h>  // Make includes first part of file
#include <string.h> // For string functions
int main(void);     // Define main() and the fact that this
// program doesn’t use any passed parameters
int main()
{
    int i;
    struct
    {
        char szSaying[126];
        short int nLength;
    } MySaying =
        {"Firestone's Law of Forecasting:",
         strlen(MySaying.szSaying)};
    printf("sizeof(MYSaying) = %d\n", sizeof(MySaying));
    printf("MySaying %p %3d '%s'\n",
           &MySaying.szSaying,
           MySaying.nLength,
           MySaying.szSaying);
    printf("\n\n");
    return (0);
}