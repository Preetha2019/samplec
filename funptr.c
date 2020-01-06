#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions.
#include <stdlib.h>  // Standard include items.
#include <process.h> // For exit() etc.
int main(            // Define main() and the fact that this program uses
    int argc,        // the passed parameters.
    char *argv[],
    char *envp[]);
void NonPrint(const char chChar);
void Letter(const char chChar);
void Number(const char chChar);
void Space(const char chChar);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    void (*function[256])(const char);
    char *pszTemp;
    char szBuffer[512]; // Your input buffer.
    int i;
    /* First initialize your array of function pointers. Notice that,
* because you have specified what the function pointed to by this
* pointer requires for a parameter, all the functions assigned to
* this array require the same number and types of parameters.
* The parameters could have been omitted, but then you don't
* benefit from type checking on parameters. */
    for (i = 0; i < 256; i++)
    {
        if ((unsigned char)i < ' ')
        {
            function[i] = NonPrint;
        }
        else
        {
            if ((unsigned char)i >= '0' &&
                (unsigned char)i <= '9')
            {
                function[i] = Number;
            }
            else
            {
                if ((unsigned char)i == ' ')
                {
                    function[i] = Space;
                }
                else
                {
                    function[i] = Letter;
                }
            }
        }
    }
    while (gets(szBuffer))
    {
        for (i = 0; szBuffer[i]; i++)
        {
            /* Now, this is nice syntax: */
            function[(int)szBuffer[i]](szBuffer[i]);
        }
    }
    return (0);
}
void NonPrint(
    const char chChar)
{
    /* Make it printable by adding a '@' to it.*/
    printf("CTRL - '%c'\n", chChar + '@');
}
void Space(
    const char chChar)
{
    printf("Space '%c'\n", chChar);
}
void Letter(
    const char chChar)
{
    printf("Letter '%c'\n", chChar);
}
void Number(
    const char chChar)
{
    printf("Number '%c'\n", chChar);
}