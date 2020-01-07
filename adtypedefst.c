#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#define CUSTOMER_RECORD 1
#define SUPPLIER_RECORD 2
/* Define the structure for the customer database */
typedef struct _CUSTNAME
{
    int nRecordType;    // 1 == Customer record
    char szName[61];    // 60 chars for name; 1 for null at end
    char szAddr1[61];   // 60 chars for address; 1 for null at end
    char szAddr2[61];   // 60 chars for address; 1 for null at end
    char szCity[26];    // 25 characters for city; 1 for null at end
    char szState[3];    // 2-character state abbrev. plus null
    int nZip;           // Use integer. Print as %5.5d for leading 0
    int nRecordNumber;  // Which record number?
    double dSalesTotal; // Amount customer has purchased
} CUSTNAME;
typedef CUSTNAME *PCUSTNAME;
void main()
{
    FILE *DataFile;
    CUSTNAME Customer;
    char szFileName[25];
    char szBuffer[129];
    int i;
    int nResult;
    double dSales = 0.0; // Forces loading of floating-point support
    printf("Please enter customer database name: ");
    gets(szFileName);
    DataFile = fopen(szFileName, "wb");
    if (DataFile == NULL)
    {
        printf("ERROR: File '%s' couldn’t be opened.\n", szFileName);
        exit(4);
    }
    Customer.szName[0] = 'A'; // To get past while() the first time
    i = 0;
    Customer.nRecordNumber = 0;
    while (strlen(Customer.szName) > 0)
    {
        memset(&Customer, 0, sizeof(CUSTNAME));
        printf("Enter the Customer's name: ");
        gets(Customer.szName);
        if (strlen(Customer.szName) > 0)
        {
            Customer.nRecordNumber = i;
            do
            {
                printf("Enter 1 for customer, 2 for supplier ");
                gets(szBuffer);
                sscanf(szBuffer, "%d", &Customer.nRecordType);
            } while (Customer.nRecordType != CUSTOMER_RECORD &&
                     Customer.nRecordType != SUPPLIER_RECORD);
            printf("Enter address line 1: ");
            gets(Customer.szAddr1);
            printf("Enter address line 2: ");
            gets(Customer.szAddr2);
            printf("Enter City: ");
            gets(Customer.szCity);
            printf("Enter state postal abbreviation: ");
            gets(Customer.szState);
            printf("Enter ZIP code: ");
            gets(szBuffer);
            sscanf(szBuffer, "%d", &Customer.nZip);
            printf("Enter total sales: ");
            gets(szBuffer);
            sscanf(szBuffer, "%f", &Customer.dSalesTotal);
            nResult = fwrite((char *)&Customer, sizeof(CUSTNAME), 1,
                             DataFile);
            if (nResult != 1)
            {
                printf("ERROR: File '%s', write error.\n",
                       szFileName);
                fclose(DataFile);
                exit(4);
            }
            ++i;
        }
    }
    fclose(DataFile);
}