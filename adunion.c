#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#define CUSTOMER_RECORD 1
#define SUPPLIER_RECORD 2
// Define the structure for the customer database.
typedef struct _CUSTNAME {
int nRecordType;
char szName[61]; // 60 chars for name; 1 for null at end
char szAddr1[61]; // 60 chars for address; 1 for null at end
char szAddr2[61]; // 60 chars for address; 1 for null at end
char szCity[26]; // 25 characters for city; 1 for null at end
char szState[3]; // 2-character state abbreviation + null
int nZip; // Use integer; print as %5.5d for leading 0
int nRecordNumber; // Which record number?
double dSalesTotal; // Amount the customer has purchased
} CUSTNAME;
typedef CUSTNAME near *NPCUSTNAME;
typedef CUSTNAME *PCUSTNAME;
typedef struct _SUPPLIERNAME {
int nRecordType;
char szName[61]; // 60 chars for name; 1 for null at end
char szAddr1[61]; // 60 chars for address; 1 for null at end
char szAddr2[61]; // 60 chars for address; 1 for null at end
char szCity[26]; // 25 characters for city; 1 for null at end
char szState[3]; // 2-character state abbreviation + null
int nZip; // Use integer. Print as %5.5d for leading 0
int nRecordNumber; // Which record number?
double dSalesTotal; // Amount the customer has purchased
} SUPPLIERNAME;
typedef SUPPLIERNAME near *NPSUPPLIERNAME;
typedef SUPPLIERNAME *PSUPPLIERNAME;
typedef union _DBRECORD {
CUSTNAME Customer;
SUPPLIERNAME Supplier;
} DBRECORD;
/* Local prototypes (use the typedef’ed names,
* so must follow typedefs):
*/
SUPPLIERNAME ProcessSupplier(NPSUPPLIERNAME);
CUSTNAME ProcessCustomer(NPCUSTNAME);
// main() function, the called functions
void main()
{
DBRECORD dbRecord;
FILE *DataFile;
char szFileName[25];
char szBuffer[129];
int i;
int nResult[3];
double dSales = 0.0; // Forces loading of floating-point support
printf("Please enter customer database name: ");
gets(szFileName);
DataFile = fopen(szFileName, "rb");
if (DataFile == NULL)
{
printf("ERROR: File '%s' couldn't be opened.\n", szFileName);
exit(4);
}
nResult[0] = 1;
while (nResult[0] == 1)
{
nResult[0] = fread((char *)&dbRecord, sizeof(DBRECORD), 1,
DataFile);
if (nResult[0] != 1)
{
if (!feof(DataFile))
{
printf("ERROR: File '%s', read error.\n", szFileName);
fclose(DataFile);
exit(4);
}
else
{
printf("End of database file '%s'.\n", szFileName);
}
}
else
{
// You could test dbRecord.Supplier.nRecordType, or
switch(dbRecord.Customer.nRecordType)
{
case CUSTOMER_RECORD:
ProcessCustomer(&dbRecord.Customer);
break;
case SUPPLIER_RECORD:
ProcessSupplier(&dbRecord.Supplier);
break;
default:
printf("ERROR: Invalid record type read from \
database \n");
break;
}
}
}
fclose(DataFile);
}
SUPPLIERNAME ProcessSupplier(
NPSUPPLIERNAME npSupplier)
{
SUPPLIERNAME WorkSupplier;
WorkSupplier = *npSupplier;
printf("Supplier name: %s\n", npSupplier->szName);
// Do other processing for Supplier...
// .
// . 
// .
// Return WorkSupplier to caller.
return(WorkSupplier);
}
CUSTNAME ProcessCustomer(
NPCUSTNAME npCustomer)
{
CUSTNAME WorkCustomer;
WorkCustomer = *npCustomer;
printf("Customer name: %s\n", npCustomer->szName);
// Do other processing for customer...
// .
// .
// .
// Return WorkCustomer to caller.
return(WorkCustomer);
}