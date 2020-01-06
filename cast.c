#include <stdio.h> // Make includes first part of file
#include <string.h>
int main(void); // Define main() and the fact that this program doesn’t
// use any passed parameters.
int main()
{
    float fValue = 123.0F;
    double dValue = 987.0;
    long double ddValue = 123123123123.0L;
    int nInteger = 12345;
    int nIntegerAgain = 12345;
    long lLong = 987;
    unsigned long ulLong = 987;
    char cChar = 'A';
    printf("fValue %f \n dValue %lf \n ddValue %Lf \n "
           "nInteger %d \n lLong %ld \n ulLong %lu \n cChar %c\n",
           fValue,
           dValue,
           ddValue,
           nInteger,
           lLong,
           ulLong,
           cChar);
    /* These assignment statements generate a warning message
about type conversion. */
    nInteger = dValue;
    lLong = ddValue;
    ulLong = ddValue;
    cChar = nIntegerAgain;
    printf("\n fValue %f \n dValue %lf \n ddValue %Lf \n "
           "nInteger %d \n lLong %ld \n ulLong %lu \n cChar %c\n",
           fValue,
           dValue,
           ddValue,
           nInteger,
           lLong,
           ulLong,
           cChar);
    /* With a cast, there is no warning message;
however, the conversion is the same */
    nInteger = (int)dValue;
    lLong = (long)ddValue;
    ulLong = (unsigned long)ddValue;
    cChar = (char)nIntegerAgain;
    printf("\n fValue %f \n dValue %lf \n ddValue %Lf \n "
           "nInteger %d \n lLong %ld \n ulLong %lu \n cChar %c\n",
           fValue,
           dValue,
           ddValue,
           nInteger,
           lLong,
           ulLong,
           cChar);
    printf("\nNotice that 'lLong' and 'ulLong'"
           "both have the wrong value.\n");
    return (0);
}