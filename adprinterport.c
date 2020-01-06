#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions
#include <stdlib.h>  // Standard include items
#include <process.h> // For exit(), etc.
#include <time.h>    // To seed random numbers
#define MAKELONG(low, high) ((long)(((unsigned short int)(low)) | (((unsigned long int)((unsigned short int)(high))) << 16)))
#define MAKELP(sel, off) ((void *)MAKELONG((off), (sel)))
/* Printer port definitions */
#define BIOS_DATA_PAGE 0x0040
#define LPT1 0x0008
#define DATA_PORT (nPort)
#define STATUS_PORT (nPort + 1)
#define CONTROL_PORT (nPort + 2)
#define STATUS_NORESP 0x01
#define STATUS_UNUSED1 0x02
#define STATUS_UNUSED2 0x04
#define STATUS_ERROR 0x08
#define STATUS_SELECTED 0x10
#define STATUS_NOPAPER 0x20
#define STATUS_ACK 0x40
#define STATUS_NOTBUSY 0x80
#define CONTROL_STROBE 0x01
#define CONTROL_AUTOFEED 0x02
#define CONTROL_INIT 0x04
#define CONTROL_SELECT 0x08
#define CONTROL_IRQ7 0x10
#define CONTROL_UNUSED1 0x20
#define CONTROL_UNUSED2 0x40
#define CONTROL_UNUSED3 0x80
/* End printer port definitions. */
int main(     // Define main() and the fact that this
    int argc, // program uses the passed parameters
    char *argv[],
    char *envp[]);
int PrintCharacter(char chChar);
int PrinterStatus(void);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    char szNowIsTheTime[] = {
        "Now is the time for all good men to come to the aid...\f"};
    int nStatus;
    int i;
    if (!PrinterStatus())
    {
        printf("There was a printer error!\n");
        exit(4);
    }
    for (i = 0; i < strlen(szNowIsTheTime); i++)
    {
        if (PrintCharacter(szNowIsTheTime[i]) == 0)
        {
            printf("\nCouldn't print from '%s'\n",
                   &szNowIsTheTime[i]);
            break;
        }
    }
    return (0);
}
int PrintCharacter(
    char chChar)
{
    int *pPrintPort;
    int nPort;
    int nStatus;
    /* The PC’s printer port is at address 0040:0008
* (for LPT1:). If 0 is stored at that address,
* a printer port is not installed.
*/
    pPrintPort = MAKELP(BIOS_DATA_PAGE, LPT1);
    nPort = *pPrintPort;
    if (nPort == 0)
    { /* No printer is installed! */
        printf("No printer installed... WHY?\n");
        return (0);
    }
    /* Write the data byte to the printer’s data lines */
    outp(DATA_PORT, chChar);
    /* Next, check to see if the printer is busy. */
    nStatus = inp(STATUS_PORT);
    if (!(nStatus & STATUS_NOTBUSY))
    { /* The printer is busy. You should wait and try again */
        printf("The printer is busy?\n");
        return (0);
    }
    /* Set the strobe line */
    outp(CONTROL_PORT, CONTROL_STROBE | CONTROL_INIT | CONTROL_SELECT);
    /* Clear the strobe line */
    outp(CONTROL_PORT, CONTROL_INIT | CONTROL_SELECT);
}
int PrinterStatus()
{
    int *pPrintPort;
    int nPort;
    int nStatus;
    /* The PC’s printer port is at address 0040:0008
* (for LPT1:). If 0 is stored at that address,
* a printer port is not installed.
*/
    pPrintPort = MAKELP(BIOS_DATA_PAGE, LPT1);
    nPort = *pPrintPort;
    if (nPort == 0)
    { /* No printer is installed! */
        printf("No printer installed... WHY?\n");
        return (0);
    }
    printf("Printer vector = %lp Printer port %4.4X\n",
           pPrintPort,
           nPort);
    nStatus = inp(DATA_PORT);
    printf("DATA port's contents %2.2X (last character that was printed)\n", nStatus);
    nStatus = inp(STATUS_PORT);
    if (!(nStatus & STATUS_NORESP))
    {
        printf("The printer did not respond. \n");
    }
    else
    {
        printf("The printer is responding. \n");
    }
    if (!(nStatus & STATUS_ERROR))
    {
        printf("The printer is signaling an error. \n");
    }
    else
    {
        printf("The printer is signaling no errors. \n");
    }
    if (nStatus & STATUS_SELECTED)
    {
        printf("The printer is currently selected. \n");
    }
    else
    {
        printf("The printer is not selected. \n");
    }
    if (nStatus & STATUS_NOPAPER)
    {
        printf("The printer is out of paper.\n");
    }
    else
    {
        printf("The printer has paper. \n");
    }
    if (nStatus & STATUS_ACK)
    {
        printf("The printer ACK line is set.\n");
    }
    else
    {
        printf("The printer ACK line is cleared.\n");
    }
    if (nStatus & STATUS_NOTBUSY)
    {
        printf("The printer is not busy.\n");
    }
    else
    {
        printf("The printer is currently busy. \n");
    }
    return (0);
}