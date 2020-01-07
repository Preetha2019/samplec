#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
int main(int argc, char *argv[])
{
    char szDrive[_MAX_DRIVE] = {0};
    char szDir[_MAX_DIR] = {0};
    char szFileName[_MAX_FNAME] = {0};
    char szExt[_MAX_EXT] = {0};
    char *pszFname = NULL;
    char *pszPname = NULL;

    _splitpath(argv[0], szDrive, szDir, szFileName, szExt);

    printf("\nszDrive is %s\t", szDrive);
    printf("\nszDir is %s\t", szDir);
    printf("\nszFname is %s\t", szFileName);
    printf("\nszExt is %s\t", szExt);
    return 0;
}