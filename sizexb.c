#include <stdio.h>
// structure C
typedef struct structc_tag
{
    char a;
    double b;
    int c;
} structc_t;
int main()
{
    printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
}