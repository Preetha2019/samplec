#include <stdio.h>   // Make includes first part of file
#include <conio.h>   // Console I/O functions
#include <string.h>  // For string functions
#include <stdlib.h>  // Standard include items
#include <process.h> // For exit(), etc.
#include <time.h>    // To seed random numbers
/* ANSI.SYS screen control #defines follow: */
#define BOLD "\x1B[1m"
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define BLACK "\x1B[30m"
#define GREEN "\x1B[32m"
#define CLEAR_SCREEN "\x1B[2J"
#define CLEAR_EOL "\x1B[K"
#define MOVE_CURSOR "\x1B[%d;%df"
#define UP '\x48'
#define DOWN '\x50'
#define LEFT '\x4B'
#define RIGHT '\x4D'
#define MAX_HEIGHT 25
#define MAX_WIDTH 80
#define HALF_SECOND (CLOCKS_PER_SEC / 2)
int main(     // Define main() and the fact that this
    int argc, // program uses the passed parameters
    char *argv[],
    char *envp[]);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    char chChar;
    clock_t ClockTime;
    clock_t OldClockTime;
    int i;
    int nHorizontal = 0;       /* Randomize for real game */
    int nVertical = 0;         /* Randomize for real game */
    int nMoneyHorizontal = 10; /* Randomize for real game */
    int nMoneyVertical = 10;   /* Randomize for real game */
    int nPosition;
    OldClockTime = clock() / HALF_SECOND;
    srand((unsigned)time(NULL));
    printf(CLEAR_SCREEN);
    printf(MOVE_CURSOR, nMoneyVertical, nMoneyHorizontal);
    printf("$");
    printf(MOVE_CURSOR, nVertical, nHorizontal);
    printf("?");
    while (1)
    {
        if (kbhit())
        { /* A key has been pressed, so process it as necessary */
            chChar = getch();
            if (chChar == '\0')
            {
                chChar = getch();
                printf(MOVE_CURSOR, nVertical, nHorizontal);
                printf(" ");
                switch (chChar)
                {
                case DOWN:
                    if (++nVertical > MAX_HEIGHT)
                    {
                        --nVertical;
                    }
                    break;
                case UP:
                    if (--nVertical < 1)
                    {
                        ++nVertical;
                    }
                    break;
                case RIGHT:
                    if (++nHorizontal > MAX_WIDTH)
                    {
                        --nHorizontal;
                    }
                    break;
                case LEFT:
                    if (--nHorizontal < 1)
                    {
                        ++nHorizontal;
                    }
                    break;
                default:
                    break;
                }
                printf(MOVE_CURSOR, nVertical, nHorizontal);
                if (nMoneyHorizontal == nHorizontal &&
                    nMoneyVertical == nVertical)
                {
                    printf("\a");
                }
                printf("?");
            }
            else
            {
                if (chChar == '\x1b')
                { /* Exit on Esc keypress */
                    printf(CLEAR_SCREEN);
                    exit(4);
                }
            }
        }
        else
        { /* No key has been pressed. Move the money. */
            ClockTime = clock() / HALF_SECOND;
            if (ClockTime != OldClockTime)
            {
                OldClockTime = ClockTime;
                printf(MOVE_CURSOR, nMoneyVertical, nMoneyHorizontal);
                printf(" "); /* Erase the money */
                i = rand();
                switch (i % 4) /* Allow four states */
                {
                case 0:
                    if (++nMoneyVertical > MAX_HEIGHT)
                    {
                        --nMoneyVertical;
                    }
                    break;
                case 1:
                    if (--nMoneyVertical < 1)
                    {
                        ++nMoneyVertical;
                    }
                    break;
                case 2:
                    if (++nMoneyHorizontal > MAX_WIDTH)
                    {
                        --nMoneyHorizontal;
                    }
                    break;
                case 3:
                    if (--nMoneyHorizontal < 1)
                    {
                        ++nMoneyHorizontal;
                    }
                    break;
                default:
                    break;
                }
                if (nMoneyHorizontal == nHorizontal &&
                    nMoneyVertical == nVertical)
                {
                    --nMoneyHorizontal;
                    --nMoneyVertical;
                }
                printf(MOVE_CURSOR, nMoneyVertical, nMoneyHorizontal);
                printf("$"); /* Display the money */
                printf(MOVE_CURSOR, nVertical, nHorizontal);
            }
        }
    }
    return (0);
}