#include <stdio.h>
#include <string.h>
// Most of the C compilers support a third parameter to main which
// store all envorinment variables
int main(int argc, char *argv[], char *envp[])
{
    int i;
    for (i = 0; envp[i] != NULL; i++)
        printf("\n%50s", envp[i]);
    return 0;
}