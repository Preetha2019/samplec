#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#define INCREMENT_AMOUNT 2
#define CUSTOMER_RECORD 1
#define SUPPLIER_RECORD 2
/* Define our structure for the customer database. */
typedef struct _CUSTNAME
{
    int nRecordType;    // 1 == Customer record
    char szName[61];    // 60 chars for name, 1 for null at end
    char szAddr1[61];   // 60 chars for address, 1 for null at end
    char szAddr2[61];   // 60 chars for address, 1 for null at end
    char szCity[26];    // 25 chars for city, 1 for null at end
    char szState[3];    // 2-char state abbreviation, plus null
    long lZip;          // Use integer, print as %5.5ld for leading 0
    int nRecordNumber;  // Which record number?
    double dSalesTotal; // How much customer has purchased
} CUSTNAME;
typedef CUSTNAME *NPCUSTNAME;
typedef CUSTNAME *PCUSTNAME;
void main()
{
    FILE *DataFile;
    PCUSTNAME Customer = NULL;
    PCUSTNAME TempCustomer = NULL;
    char szFileName[25];
    char szBuffer[257];
    int i;
    int nNumberRecords = 0;
    int nRecord = 0;
    int nResult = 0;
    double dSales = 0.0; // Forces loading of floating-point support
    Customer = (PCUSTNAME)calloc(sizeof(CUSTNAME),
                                 INCREMENT_AMOUNT);
    nNumberRecords += INCREMENT_AMOUNT;
    printf("Please enter customer database name: ");
    gets(szFileName);
    DataFile = fopen(szFileName, "wb");
    if (DataFile == NULL)
    {
        printf("ERROR: File '%s' couldn't be opened.\n", szFileName);
        exit(4);
    }
    printf("Demo of calloc() and realloc(). sizeof(CUSTNAME) = %d\n",
           sizeof(CUSTNAME));
    nRecord = 0;
    Customer[nRecord].szName[0] = 'f'; // To get past while() first time
    while (strlen(Customer[nRecord].szName) > 0)
    {
        memset(&Customer[nRecord], 0, sizeof(CUSTNAME));
        printf("Enter name %d: ", nRecord + 1);
        gets(szBuffer);
        szBuffer[sizeof(Customer[nRecord].szName) - 1] = '\0';
        strcpy(Customer[nRecord].szName, szBuffer);
        if (strlen(Customer[nRecord].szName) > 0)
        {
            Customer[nRecord].nRecordNumber = i;
            do
            {
                printf("Enter 1 for customer, 2 for supplier ");
                gets(szBuffer);
                sscanf(szBuffer, "%d", &Customer[nRecord].nRecordType);
            } while (Customer[nRecord].nRecordType != CUSTOMER_RECORD &&
                     Customer[nRecord].nRecordType != SUPPLIER_RECORD);
            printf("Enter address line 1: ");
            gets(szBuffer);
            szBuffer[sizeof(Customer[nRecord].szAddr1) - 1] = '\0';
            strcpy(Customer[nRecord].szAddr1, szBuffer);
            printf("Enter address line 2: ");
            gets(szBuffer);
            szBuffer[sizeof(Customer[nRecord].szAddr2) - 1] = '\0';
            strcpy(Customer[nRecord].szAddr2, szBuffer);
            printf("Enter City: ");
            gets(szBuffer);
            szBuffer[sizeof(Customer[nRecord].szCity) - 1] = '\0';
            strcpy(Customer[nRecord].szCity, szBuffer);
            printf("Enter state postal abbreviation: ");
            gets(szBuffer);
            szBuffer[sizeof(Customer[nRecord].szState) - 1] = '\0';
            strcpy(Customer[nRecord].szState, szBuffer);
            printf("Enter ZIP code: ");
            gets(szBuffer);
            sscanf(szBuffer, "%ld", &Customer[nRecord].lZip);
            printf("Enter total sales: ");
            gets(szBuffer);
            sscanf(szBuffer, "%f", &Customer[nRecord].dSalesTotal);
            ++nRecord;
            if (nRecord == nNumberRecords)
            {
                TempCustomer = (PCUSTNAME)realloc(Customer,
                                                  sizeof(CUSTNAME) * (nNumberRecords +
                                                                      INCREMENT_AMOUNT));
                if (TempCustomer)
                {
                    nNumberRecords += INCREMENT_AMOUNT;
                    printf("realloc() added records, now total is %d\n",
                           nNumberRecords);
                    Customer = TempCustomer;
                    Customer[nRecord].szName[0] = 'A'; // To get past
                }
                else
                {
                    printf("ERROR: Couldn't realloc the buffers\n\n");
                    --nRecord;
                    Customer[nRecord].szName[0] = '\0';
                }
            }
            else
            {
                Customer[nRecord].szName[0] = 'A'; // To get past while()
            }
        }
    }
    for (i = 0; i < nRecord; i++)
    {
        printf("Name '%10s' City '%10s' State '%2s' ZIP '%5.5ld'\n",
               Customer[i].szName,
               Customer[i].szCity,
               Customer[i].szState,
               Customer[i].lZip);
    }
    nResult = fwrite((char *)Customer,
                     sizeof(CUSTNAME),
                     nRecord,
                     DataFile);
    if (nResult != nRecord)
    {
        printf("ERROR: File '%s', write error, record %d.\n",
               szFileName,
               i);
        fclose(DataFile);
        exit(4);
    }
    fclose(DataFile);
}