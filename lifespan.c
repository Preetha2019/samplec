#include <stdio.h> // Make includes first part of file
#include <string.h>
int nLife = {2}; // Initialize to 5, default is 0.
int main(void);  // Define main() and the fact that this program doesn’t
// use any passed parameters.
void DisplayLife(void); // Define DisplayLife()
int main()
{
    int nCounter = 0;
    do
    {
        int nCountLoop = 0; /* This nCounter is unique to the loop */
        nCountLoop += 3;    /* Increments (and prints) the loop’s
nCounter */
        nLife += nCounter;
        printf("nCountLoop is = %d\n", nCountLoop);
    } while (++nCounter < 10); /* Increments the function’s nCounter */
    DisplayLife();
    printf("Ended, nCounter is = %d\n", nCounter);
    return (0);
}
void DisplayLife()
{
    printf("DisplayLife(), nLife = %d?\n", nLife);
}