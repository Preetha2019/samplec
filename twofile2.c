#include "twofile.h" // TWOFILE’s include has all other #includes.
void GiveHelp(
    int nLevel,
    char *psItem)
{
    printf("\n");
    switch (nLevel)
    {
    case NOINNAME:
    case NOOUTNAME: // Not enough parameters!
        printf(
            "FORMAT [-r|-l|-j] inputfile outputfile width\n"
            " where \n"
            " Options - -r (or /r) to right align \n"
            " -l (or /l) to left align \n"
            " -j (or /j) to justify\n"
            "\n"
            " inputfile - is the input file name \n"
            " outputfile - is the output file name \n"
            "\n"
            " width is the desired output width (20 to 128)\n"
            " (default is 80 characters).\n"
            "\n"
            " Note: lines are concatenated, paragraph breaks are\n"
            " signaled with a blank line\n\n");
        break;
    case BAD_WIDTH:
        printf(
            "The width parameter must be between 20 and 128!\n"
            "the width is ignored\n");
        break;
    case BAD_PARM:
        printf("Excessive parameters have been entered\n");
        /* Force a display of full help! */
        GiveHelp(NOINNAME, NULL);
        break;
    case BAD_OPTION:
        printf("'%c' is an invalid option! (Use only -l, -r or \
-j)\n",
               *psItem);
        break;
    case NAME_MISSING:
        printf("One or both of the required file names is \
missing!\n");
        /* Force a display of full help! */
        GiveHelp(NOINNAME, NULL);
        break;
    default:
        printf(
            "An unspecified error occured! FORMAT has ended!\n");
        exit(16);
        break;
    }
}