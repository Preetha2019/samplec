#include <stdio.h>   // Make includes first part of file
#include <string.h>  // For string functions
#include <stdlib.h>  // Standard include items
#include <process.h> // For exit(), etc.
#include <time.h>    // To seed random numbers
int inp();
int outp();
#define MAKELONG(low, high) ((long)(((unsigned short int)(low)) | (((unsigned long int)((unsigned short int)(high))) << 16)))
#define MAKELP(sel, off) ((void *)MAKELONG((off), (sel)))
/* Comm port definitions */
#define BIOS_DATA_PAGE 0x0040
#define COM1 0x0000
/* Receive a character port (read only) */
#define RBR_PORT (nPort)
/* Send (transmit) a character port (write only) */
#define THR_PORT (nPort)
/* Interrupt enable register */
#define IER_PORT (nPort + 1)
#define RECEIVED_DATA_AVAILABLE 0x01
#define TRANSMIT_HOLD_EMPTY 0x02
#define RECIEVER_LINE_STATUS 0x04
#define MODEM_STATUS 0x08
/* Other bits undefined */
/* Interrupt identify register (read only) */
#define IIR_PORT (nPort + 2)
#define INTERUPT_PENDING_0 0x01
#define INTERUPT_ID_BIT_1 0x02
#define INTERUPT_ID_BIT_2 0x04
/* Other bits undefined */
/* Line control register */
#define LCR_PORT (nPort + 3)
#define WORD_LENGTH_SELECT_1 0x01 /* 00 = 5 bits, 01 = 6 bits */
#define WORD_LENGTH_SELECT_2 0x02 /* 10 = 7 bits, 11 = 8 bits */
#define NUMBER_STOP_BITS 0x04     /* 0 = 1 stop, 1 = 2 stop */
#define PARITY_ENABLE 0x08
#define EVEN_PARITY_SELECT 0x10
#define STICK_PARITY 0x20
#define SET_BREAK 0x40
#define DIVISOR_LATCH_BIT 0x80 /* For DLL and DLH access */
/* Other bits undefined */
/* Modem control register */
#define MCR_PORT (nPort + 4)
#define DTR 0x01
#define RTS 0x02
#define OUT_1 0x04
#define OUT_2 0x08
#define LOOP 0x10
/* Other bits undefined */
/* Line status register */
#define LSR_PORT (nPort + 5)
#define DATA_READY 0x01
#define OVERRUN_ERROR 0x02
#define PARITY_ERROR 0x04
#define FRAMING_ERROR 0x08
#define BREAK_INTERUPT 0x10
#define TRANS_HOLDING_REGISTER 0x20
#define TRANS_SHIFT_REGISTER 0x40
/* Other bits undefined */
/* Modem status register */
#define MSR_PORT (nPort + 6)
#define DCTS 0x01
#define DDSR 0x02
#define TERI 0x04
#define DDCD 0x08
#define CTS 0x10
#define DSR 0x20
#define RI 0x40
#define DCD 0x80
/* Divisor latch least significant (sets speed) */
#define DLL_PORT (nPort + 0)
/* Bits 0 - 7 */
/* Divisor latch most significant (sets speed) */
#define DLM_PORT (nPort + 1)
/* Bits 8 - 15 */
#define BAUD_50 0x0900
#define BAUD_75 0x0600
#define BAUD_110 0x0417
#define BAUD_134 0x0359
#define BAUD_150 0x0300
#define BAUD_300 0x0180
#define BAUD_600 0x00C0
#define BAUD_1200 0x0060
#define BAUD_1800 0x0040
#define BAUD_2000 0x003A
#define BAUD_2400 0x0030
#define BAUD_3600 0x0020
#define BAUD_4800 0x0018
#define BAUD_7200 0x0010
#define BAUD_9600 0x000C
#define BAUD_14400 0x0008
#define BAUD_19200 0x0006
#define BAUD_38400 0x0003
#define BAUD_56000 0x0002
#define BAUD_112000 0x0001
/* End serial port definitions */
int main(     // Define main() and the fact that this
    int argc, // program uses the passed parameters
    char *argv[],
    char *envp[]);
int SerialCharacter(char chChar);
int SerialStatus(void);
int main(
    int argc,
    char *argv[],
    char *envp[])
{
    char szNowIsTheTime[] = {
        "Now is the time for all good men to come to the aid...\n\r"};
    int nStatus;
    int i;
    if (!SerialStatus())
    {
        printf("There was a serial error!\n");
        exit(4);
    }
    for (i = 0; i < strlen(szNowIsTheTime); i++)
    {
        if (SerialCharacter(szNowIsTheTime[i]) == 0)
        {
            printf("\nCouldn't send from character '%s'\n",
                   &szNowIsTheTime[i]);
            break;
        }
    }
    return (0);
}
int SerialCharacter(
    char chChar)
{
    int *pSerialPort;
    int nPort;
    int nStatus;
    /* The PC’s serial port is at address 0040:0000
* (for COM1:). If a zero is stored at that address,
* a serial port is not installed.
*/
    pSerialPort = MAKELP(BIOS_DATA_PAGE, COM1);
    nPort = *pSerialPort;
    if (nPort == 0)
    { /* No serial port is installed! */
        printf("No serial installed... WHY?\n");
        return (0);
    }
    /* Write the data byte to the serial port’s data lines.
* The program must wait until the last character
* has been sent because the simple hardware does not
* have a queue.
*/
    nStatus = inp(LSR_PORT);
    while (!(nStatus & TRANS_HOLDING_REGISTER))
    { /* Simply get the status again, which wastes time */
        nStatus = inp(LSR_PORT);
    }
    outp(THR_PORT, chChar);
    return (1);
}
int SerialStatus()
{
    int *pSerialPort;
    int nPort;
    int nStatus;
    /* The PC’s serial port is at address 0040:0000
* (for COM1:). If a zero is stored at that address,
* a serial port is not installed.
*/
    pSerialPort = MAKELP(BIOS_DATA_PAGE, COM1);
    nPort = *pSerialPort;
    if (nPort == 0)
    { /* No serial port is installed! */
        printf("No serial board installed... Why?\n");
        return (0);
    }
    printf("Serial vector = %lp Serial port %4.4X\n",
           pSerialPort,
           nPort);
    nStatus = inp(MCR_PORT);
    printf("MCR_PORT returned %2.2X\n", nStatus);
    if (nStatus & DTR)
    {
        printf("DTR is high. \n");
    }
    else
    {
        printf("DTR is low. \n");
    }
    if (nStatus & RTS)
    {
        printf("RTS is high. \n");
    }
    else
    {
        printf("RTS is low. \n");
    }
    nStatus = inp(IER_PORT);
    printf("IER_PORT returned %2.2X\n", nStatus);
    nStatus = inp(IIR_PORT);
    printf("IIR_PORT returned %2.2X\n", nStatus);
    nStatus = inp(LCR_PORT);
    printf("LCR_PORT returned %2.2X\n", nStatus);
    nStatus = inp(MCR_PORT);
    printf("MCR_PORT returned %2.2X\n", nStatus);
    nStatus = inp(LSR_PORT);
    printf("LSR_PORT returned %2.2X\n", nStatus);
    nStatus = inp(MSR_PORT);
    printf("MSR_PORT returned %2.2X\n", nStatus);
    return (1);
}