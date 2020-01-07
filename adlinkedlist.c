#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE (!TRUE)
#define INCREMENT_AMOUNT 1 /* Add one record at a time */
#define CUSTOMER_RECORD 1
#define SUPPLIER_RECORD 2
/* Define the structure for the customer database. */
struct _CUSTNAME;
typedef struct _CUSTNAME
{
    int nRecordType;                // 1 == Customer record.
    struct _CUSTNAME *NextCustomer; // Link to next, or NULL if none
    struct _CUSTNAME *PrevCustomer; // Link to previous, or NULL if none
    char szName[61];                // 60 chars for name; 1 for null at end
    char szAddr1[61];               // 60 chars for address; 1 for null at end
    char szAddr2[61];               // 60 chars for address; 1 for null at end
    char szCity[26];                // 25 chars for city; 1 for null at end
    char szState[3];                // 2-character state abbrev. plus null
    int lZip;                       // Print as %5.5ld for leading 0
    int nRecordNumber;              // Which record number?
    double dSalesTotal;             // Amount the customer has purchased
} CUSTNAME;
typedef CUSTNAME *NPCUSTNAME;
typedef CUSTNAME *PCUSTNAME;
void GiveHelp(void);
void main()
{
    FILE *DataFile;
    PCUSTNAME FirstCustomer = NULL;
    PCUSTNAME LastCustomer = NULL;
    PCUSTNAME Customer = NULL;
    PCUSTNAME TempCustomer = NULL;
    char szFileName[257];
    char szBuffer[257];
    int nNotDone = TRUE;
    int nRecord = 0;
    int nDebug = FALSE;
    int nNeedSaving = FALSE;
    double dSales = 0.0; /* Forces loading of floating-point support */
    printf("Please enter customer save file name: ");
    gets(szFileName);
    DataFile = fopen(szFileName, "wt");
    if (DataFile == NULL)
    { /* Test for file open. If the file can’t be opened, exit with
message. */
        printf("ERROR: File '%s' couldn't be opened.\n", szFileName);
        exit(4);
    }
    fclose(DataFile);
    printf("Demo of a linked list concepts\n"
           "\n"
           " Commands are:\n"
           " A - Add a customer/supplier record.\n"
           " D - Display current list.\n"
           " X - Exit from program.\n"
           " Z - Toggle debug mode.\n"
           " ? - Display the command list."
           " H - Display the command list."
           " S - Save the list.\n"
           "\n");
    nRecord = 0;
    while (nNotDone)
    {
        printf("Enter command (A, D+, D-, S)?");
        gets(szBuffer);
        switch (szBuffer[0])
        {
        case 'H': /* Give some help */
        case 'h':
        case '?':
            GiveHelp();
            break;
        case 'A': /* Add a record */
        case 'a':
            Customer = (PCUSTNAME)calloc(sizeof(CUSTNAME),
                                         INCREMENT_AMOUNT);
            printf("Enter name %d: ", ++nRecord);
            gets(szBuffer);
            szBuffer[sizeof(Customer->szName) - 1] = '\0';
            strcpy(Customer->szName, szBuffer);
            if (strlen(Customer->szName) > 0)
            { /* Insert this record in the list, sorted by name. */
                nNeedSaving = TRUE;
                if (FirstCustomer == NULL)
                {
                    printf("It is first record \n");
                    Customer->NextCustomer = NULL;
                    Customer->PrevCustomer = NULL;
                    FirstCustomer = Customer;
                    LastCustomer = Customer;
                    TempCustomer = NULL;
                }
                else
                {
                    TempCustomer = FirstCustomer;
                }
                while (TempCustomer)
                {
                    if (nDebug)
                    {
                        printf("TESTING FOR ADD: '%s' '%s'\n",
                               Customer->szName,
                               TempCustomer->szName);
                    }
                    if (strcmp(Customer->szName,
                               TempCustomer->szName) < 0 ||
                        TempCustomer == LastCustomer)
                    {
                        if (strcmp(Customer->szName,
                                   TempCustomer->szName) < 0 &&
                            TempCustomer == FirstCustomer)
                        {
                            if (nDebug)
                            {
                                printf("Assigning as first\n");
                            }
                            Customer->NextCustomer = FirstCustomer;
                            FirstCustomer = Customer;
                            Customer->PrevCustomer = NULL;
                            TempCustomer = Customer->NextCustomer;
                            TempCustomer->PrevCustomer = Customer;
                        }
                        else
                        {
                            if (strcmp(Customer->szName,
                                       TempCustomer->szName) > 0 &&
                                TempCustomer == LastCustomer)
                            {
                                if (nDebug)
                                {
                                    printf("Assigning as last\n");
                                }
                                Customer->PrevCustomer =
                                    LastCustomer;
                                LastCustomer = Customer;
                                Customer->NextCustomer = NULL;
                                TempCustomer = Customer->PrevCustomer;
                                TempCustomer->NextCustomer =
                                    Customer;
                            }
                            else
                            {
                                if (nDebug)
                                {
                                    printf("Assigning inside \
list\n");
                                }
                                Customer->PrevCustomer =
                                    TempCustomer->PrevCustomer;
                                Customer->NextCustomer =
                                    TempCustomer;
                                TempCustomer->PrevCustomer =
                                    Customer;
                                TempCustomer = Customer->PrevCustomer;
                                TempCustomer->NextCustomer =
                                    Customer;
                            }
                        }
                        TempCustomer = NULL;
                    }
                    else
                    {
                        TempCustomer = TempCustomer->NextCustomer;
                    }
                }
                Customer->nRecordNumber = nRecord;
                if (!nDebug)
                {
                    do
                    {
                        printf("Enter 1 for customer, 2 for supplier \
");
                        gets(szBuffer);
                        sscanf(szBuffer, "%d", &Customer->nRecordType);
                    } while (Customer->nRecordType != CUSTOMER_RECORD &&
                             Customer->nRecordType != SUPPLIER_RECORD);
                    printf("Enter address line 1: ");
                    gets(szBuffer);
                    szBuffer[sizeof(Customer->szAddr1) - 1] = '\0';
                    strcpy(Customer->szAddr1, szBuffer);
                    printf("Enter address line 2: ");
                    gets(szBuffer);
                    szBuffer[sizeof(Customer->szAddr2) - 1] = '\0';
                    strcpy(Customer->szAddr2, szBuffer);
                    printf("Enter City: ");
                    gets(szBuffer);
                    szBuffer[sizeof(Customer->szCity) - 1] = '\0';
                    strcpy(Customer->szCity, szBuffer);
                    printf("Enter state postal abbreviation: ");
                    gets(szBuffer);
                    szBuffer[sizeof(Customer->szState) - 1] = '\0';
                    strcpy(Customer->szState, szBuffer);
                    printf("Enter ZIP code: ");
                    gets(szBuffer);
                    sscanf(szBuffer, "%ld", &Customer->lZip);
                    printf("Enter total sales: ");
                    gets(szBuffer);
                    sscanf(szBuffer, "%f", &Customer->dSalesTotal);
                }
            }
            else
            {
                printf("\aSorry, name must not be blank!\n");
            }
            break;
        case 'Z': /* Debug mode toggle */
        case 'z':
            nDebug = !nDebug;
            break;
        case 'D': /* Display all records */
        case 'd':
            TempCustomer = FirstCustomer;
            printf("Display customers\n");
            while (TempCustomer)
            {
                if (nDebug)
                {
                    printf(
                        "Name '%1's' Me %lp Next %lp Prev %lp\n",
                        TempCustomer->szName,
                        TempCustomer,
                        TempCustomer->NextCustomer,
                        TempCustomer->PrevCustomer);
                }
                else
                {
                    printf(
                        "Name '%1's' City '%1's' State '%2' "
                        "ZIP '%5'5ld'\n",
                        TempCustomer->szName,
                        TempCustomer->szCity,
                        TempCustomer->szState,
                        TempCustomer->lZip);
                }
                TempCustomer = TempCustomer->NextCustomer;
            }
            break;
        case 'X': /* Exit; prompt for save if needed */
        case 'x':
            nNotDone = FALSE;
            szBuffer[0] = '\0';
            while (nNeedSaving &&
                   szBuffer[0] == '\0')
            {
                printf("\nSave the data? (y|n)");
                gets(szBuffer);
                if (szBuffer[0] == 'n' ||
                    szBuffer[0] == 'N')
                {
                    nNeedSaving = FALSE;
                }
                else
                {
                    if (szBuffer[0] != 'y' &&
                        szBuffer[0] != 'Y')
                    {
                        printf("\nWrong answer, "
                               "please respond with 'y' or 'n'");
                        szBuffer[0] = '\0';
                    }
                }
            }
            if (!nNeedSaving)
            { /* Do not need to save, so just exit */
                break;
            }
        /* Else fall through to save routines */
        case 'S': /* Save all records */
        case 's':
            printf("Saving customers\n");
            DataFile = fopen(szFileName, "wt");
            if (DataFile == NULL)
            { /* Test for file re-open; if file can’t be opened, exit
with message */
                printf("ERROR: File '%s' couldn't be opened.\n",
                       szFileName);
                exit(4);
            }
            TempCustomer = FirstCustomer;
            while (TempCustomer)
            {
                if (nDebug)
                {
                    fprintf(DataFile,
                            "Name '%1's' Me %lp Next %lp Prev %lp\n",
                            TempCustomer->szName,
                            TempCustomer,
                            TempCustomer->NextCustomer,
                            TempCustomer->PrevCustomer);
                }
                else
                {
                    fprintf(DataFile,
                            "Name '%1's' City '%1's' State '%2'' "
                            "ZIP '%5'5ld'\n",
                            TempCustomer->szName,
                            TempCustomer->szCity,
                            TempCustomer->szState,
                            TempCustomer->lZip);
                }
                TempCustomer = TempCustomer->NextCustomer;
            }
            nNeedSaving = FALSE;
            fclose(DataFile);
            break;
        }
    }
}
void GiveHelp()
{
    printf(
        "\n"
        "This program shows how a double linked list is created and\n"
        "used. It enables you to add records, display the list of\n"
        "records (which are always sorted by name), and save the\n"
        "list of records to the disk file.\n"
        "\n"
        "LINKLIST supports the following commands:\n");
    printf(
        "\n"
        " A - Add a customer/supplier record.\n"
        " Adds a record. Each added record is placed\n"
        " in the list in the correct order. Added\n"
        " records are sorted by name.\n");
    printf(
        "\n"
        " D - Display current list.\n"
        " Prints the current list of records in sorted\n"
        " order. This list contains name and address\n"
        " information or, in the debug mode, name and\n"
        " pointer information.\n");
    printf(
        "\n"
        " X - Exit from program.\n"
        " Ends the program. If records have been added\n"
        " and not saved, prompts for save. All saves\n"
        " are made to the file specified when the\n"
        " program was started.\n");
    printf(
        "\n"
        " Z - Toggle debug mode.\n"
        " Changes the information displayed for the\n"
        " user. When on, debug mode shows where the newly\n"
        " entered name is being placed in the list, and \
the\n"
        " list pointers are displayed when a display command \
is\n"
        " entered.\n");
    printf(
        "\n"
        " ? - Display the command list.\n"
        " H - Display the command list.\n"
        " Displays this help information.\n");
    printf(
        "\n"
        " S - Save the list.\n"
        " Saves (to the specified save file) the current \
list\n"
        " of records in sorted order. This list contains \
name\n"
        " and address information or, in the debug mode,\n"
        " name and pointer information.\n"
        "\n");
    printf(
        "Additional feature: This program includes a\n"
        "prompt to save when the exit command is given.\n"
        "This prompt is given only if the records have\n"
        "not been saved since the last added record.\n");
    printf(
        "Additional feature: This program has a debug mode so that\n"
        "the user can see how the program works. The debug mode \
enables\n"
        "the user to print the linked list and its pointers.\n");
}