#include <search.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE (!TRUE)
#define INCREMENT_AMOUNT 1 /* Add one record at a time */
#define INDEX_SIZE 400 /* Maximum number of records */
#define CUSTOMER_RECORD 1
#define SUPPLIER_RECORD 2
/* Define the structure for the customer database. */
struct _CUSTNAME;
typedef struct _CUSTNAME {
int nRecordType; // 1 == Customer record
struct _CUSTNAME *NextCustomer; // Link to next, or NULL if none
struct _CUSTNAME *PrevCustomer; // Link to previous, or NULL if none
char szName[61]; // 60 chars for name; 1 for null at end
// In some cases, you would not need to
// duplicate this field in both the index and
// the record.
char szAddr1[61]; // 60 chars for address; 1 for null at end
char szAddr2[61]; // 60 chars for address; 1 for null at end
char szCity[26]; // 25 chars for city; 1 for null at end
char szState[3]; // 2-char state abbreviation plus null
long lZip; // Use integer. Print as %5.5d for leading 0
int nRecordNumber; // Which record number?
double dSalesTotal; // Amount the customer has purchased
} CUSTNAME;
typedef CUSTNAME far *FPCUSTNAME;
typedef CUSTNAME near *NPCUSTNAME;
typedef CUSTNAME *PCUSTNAME;
typedef struct _INDEXREC {
char szName[61]; // 60 chars for name; 1 for null at end
long Customer; // Pointer to customer record in file
} CUSTINDEX;
typedef CUSTINDEX far *FPCUSTINDEX;
typedef CUSTINDEX near *NPCUSTINDEX;
typedef CUSTINDEX *PCUSTINDEX;
void GiveHelp(void);
int compare(const void *, const void *);
void main()
{
FILE *DataFile;
FILE *IndexFile;
PCUSTNAME FirstCustomer = NULL;
PCUSTNAME LastCustomer = NULL;
PCUSTNAME Customer = NULL;
PCUSTNAME TempCustomer = NULL;
PCUSTINDEX CustIndex = NULL;
PCUSTINDEX pTempCustIndex = NULL;
CUSTINDEX TempCustIndex;
char szIndexFile[257];
char szDataFile[257];
char szBuffer[257];
/* Strings for _splitpath(), which parses a file name */
char szDrive[_MAX_DRIVE];
char szDir[_MAX_DIR];
char szFname[_MAX_FNAME];
char szExt[_MAX_EXT];
int i;
int nDesiredRecord;
int nNotDone = TRUE;
int nRecord = 0;
int nDebug = FALSE;
int nNeedSaving = FALSE;
long lFilePosition;
double dSales = 0.0; /* Forces the loading of floating-point support
*/
CustIndex = (PCUSTINDEX)calloc(sizeof(CUSTINDEX), INDEX_SIZE);
if (CustIndex == NULL)
{
fprintf(stderr, "Couldn't allocate necessary index memory!\n");
exit(16);
}
memset(CustIndex, 0, sizeof(CUSTINDEX));
Customer = (PCUSTNAME)calloc(sizeof(CUSTNAME), INCREMENT_AMOUNT);
if (Customer == NULL)
{
fprintf(stderr, "Couldn't allocate necessary record memory!\n");
exit(16);
}
printf(
"Please enter customer save file name-\n"
"Extensions of .DAT and .IND will be used: ");
gets(szBuffer);
_splitpath(szBuffer,
szDrive,
szDir,
szFname,
szExt);
strcpy(szIndexFile, szDrive);
strcat(szIndexFile, szDir);
strcat(szIndexFile, szFname);
strcat(szIndexFile, ".IND");
strcpy(szDataFile, szDrive);
strcat(szDataFile, szDir);
strcat(szDataFile, szFname);
strcat(szDataFile, ".DAT");
DataFile = fopen(szDataFile, "wb");
if (DataFile == NULL)
{/* Test for file open. If file can’t be opened, exit with message.
*/
printf("ERROR: Data file '%s' couldn't be opened.\n",
szDataFile);
exit(4);
}
fclose(DataFile);
IndexFile = fopen(szIndexFile, "wb");
if (IndexFile == NULL)
{/* Test for file open. If file can't be opened, exit with message.
*/
printf("ERROR: Index file '%s' couldn't be opened.\n",
szIndexFile);
exit(4);
}
fclose(IndexFile);
printf("Demo of an indexed file/array.\n"
"\n"
" Commands are:\n"
" A - Add a customer/supplier record.\n"
" D - Display current list (from file).\n"
" X - Exit from program.\n"
" Z - Toggle debug mode.\n"
" ? - Display the command list.\n"
" H - Display the command list.\n"
"\n"
";
nRecord = -1;
while (nNotDone)
{
printf("Enter command?");
gets(szBuffer);
switch(szBuffer[0])
{
case 'H': /* Give some help */
case 'h':
case '?':
GiveHelp();
break;
case 'A': /* Add a record */
case 'a':
memset(Customer, 0, sizeof(CUSTNAME));
printf("Enter name %d: ", ++"Record);
gets(szBuffer);
szBuffer[sizeof(Customer->szName) - 1] = '\0';
strcpy(Customer->szName, szBuffer);
if (strlen(Customer->szName) > 0)
{/* Insert this record in the list, sorted by name. */
nNeedSaving = TRUE;
// Add to file and index:
Customer->nRecordNumber = nRecord;
if (!nDebug)
{
do
{
printf("Enter 1 for customer, 2 for supplier \
");
gets(szBuffer);
sscanf(szBuffer, "%d",&Customer->nRecordType);
}
while (Customer->nRecordType != CUSTOMER_RECORD
&&
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
sscanf(szBuffer, "%d",&Customer->nZip);
printf("Enter total sales: ");
g"ts(szBuffer);
sscanf(szBuffer, "%f",&Customer->dSalesTotal);
}
DataFile = fopen(szDataFile, "ab");
if (DataFile == NULL)
{
printf(
"ERROR: Data file '%s' couldn't be "
"opened for update.\n",
szDataFile);
exit(4);
}
fseek(DataFile, 0, SEEK_END);
CustIndex[nRecord].Customer = ftell(DataFile);
strcpy(CustIndex[nRecord].szName, Customer->szName);
printf("Index %d '%s' is at '%ld'\n",
nRecord,
CustIndex[nRecord].szName,
CustIndex[nRecord].Customer);
fwrite(Customer, sizeof(CUSTNAME), 1, DataFile);
fclose(DataFile);
}
else
{
printf("\nSorry, name must not be blank!\n");
}
break;
case 'Z': /* Debug mode toggle */
case 'z':
nDebug = !nDebug;
break;
case 'D': /* Display a record */
case 'd':
printf("Display customer (total %d).\n", nRecord + 1);
qsort(CustIndex,
nRecord + 1,
sizeof(CUSTINDEX),
compare);
for (i = 0; nDebug && i <= nRecord; i++)
{/* In debug mode, display the sorted index list. */
printf("Record %2d szName '%s'\n",
i,
CustIndex[i].szName);
}
memset(Customer, 0, sizeof(CUSTNAME));
memset(&TempCustIndex, 0, sizeof(CUSTINDEX));
printf("Enter name");
gets(TempCustIndex.szName);
printf("Searching with a linear search\n");
nDesiredRecord = -1;
for (i = 0; i <= nRecord; i++)
{/* Linear search; could be bsearch() */
if (stricmp(TempCustIndex.szName,
CustIndex[i].szName) == 0)
{
nDesiredRecord = i;
break;
}
}
if (nDesiredRecord >= 0)
{
DataFile = fopen(szDataFile, "rb");
if (DataFile == NULL)
{
printf(
"ERROR: Data file '%s' couldn't be \
opened.\n",
szDataFile);
exit(4);
}
fseek(DataFile,
CustIndex[nDesiredRecord].Customer, SEEK_SET);
fread(Customer, sizeof(CUSTNAME), 1, DataFile);
printf(
"Name '%10s' City '%10s' State '%2s' "
"ZI '%5.5d'\n",
Customer->szName,
Customer->szCity,
Customer->szState,
Customer->nZip);
fclose(DataFile);
}
else
{
printf("LINEAR SEARCH: Sorry, the name '%s' couldn't \
be found\n",
TempCustIndex.szName);
}
printf("Searching with a binary search\n");
if ((pTempCustIndex = (PCUSTINDEX)bsearch(&TempCustIndex,
CustIndex,
nRecord + 1,
sizeof(CUSTINDEX),
compare)) != NULL)
{
DataFile = fopen(szDataFile, "rb");
if (DataFile == NULL)
{
printf(
"ERROR: Data file '%s' couldn't be \
opened.\n",
szDataFile);
exit(4);
}
fseek(DataFile,
pTempCustIndex->Customer, SEEK_SET);
fread(Customer, sizeof(CUSTNAME), 1, DataFile);
printf(
"Name '%10s' City '%10s' State '%2s' "
"ZI '%5.5d'\n",
Customer->szName,
Customer->szCity,
Customer->szState,
Customer->nZip);
fclose(DataFile);
}
else
{
printf("BSEARCH: Sorry, the name '%s' couldn't be \
found\n",
TempCustIndex.szName);
}
break;
case 'X': /* Exit; prompt for save if needed. */
case 'x':
nNotDone = FALSE;
szBuffer[0] = '\0';
while (nNeedSaving &&
szBuffer[0] == '\0')
{
printf("\nSale the data? (y|n)");
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
{/* Don’t need to save, so just exit */
break;
}
/* Else fall through to the save routines */
case 'S': /* Save all records */
case 's':
printf("Saving customer index file.\n");
IndexFile = fopen(szIndexFile, "wb");
if (IndexFile == NULL)
{/* Test for file open. If file can’t be opened, exit
with message. */
printf("ERROR: Index file '%s' couldn't be \
opened.\n",
szIndexFile);
}
else
{
fwrite(CustIndex,
sizeof(CUSTINDEX) * (nRecord + 1),
1,
IndexFile);
fclose(IndexFile);
nNeedSaving = FALSE;
}
break;
default:
printf("\aUnknown operation '%c'\n",
szBuffer[0]);
break;
}
}
}
int compare(
PCUSTINDEX CustIndex1,
PCUSTINDEX CustIndex2)
{
// Uncomment the following printf() to see how qsort and qsearch work.
//
// printf("Comparing %s and %s\n",
// CustIndex1->szName,
// CustIndex2->szName);
return(stricmp(
((PCustIndex) CustIndex1)->szName,
((PCustIndex) CustIndex2)->szName));
}
void GiveHelp()
{
printf(
"\n"
"This program shows how an indexed file list is created and\n"
"used. It enables you to add records, display a specified\n"
"record, and save the list of records to the disk file.\n"
"\n"
"INDEX supports the following commands:\n");
printf(
"\n"
" A - Add a customer/supplier record.\n"
" Add a record. Each added record is placed\n"
" in the list in the correct order.\n");
printf(
"\n"
" D - Display current list.\n"
" Prints the user-specified record. This\n"
" command lists the name and address\n"
" information, assuming the name has been found.\n");
printf(
"\n"
" X - Exit from program.\n"
" End the program. If records or the index have\n"
" not been saved, will prompt for save. All saves \
are\n"
" mad  to the file specified when the program was \
started.\n");
printf(
"\n"
" Z - Toggle debug mode.\n"
" Changes the information displayed for the\n"
" use. When on, debug mode shows the sorted\n"
" index list.\n");
printf(
"\n"
" ? - Display the command list.\n"
" H - Display the command list.\n"
" Displays this help information.\n");
printf(
"\n"
" S - Save the list.\n"
" If records and the index have not been saved, this \
option\n"
" saves the records the user has entered. All saves \
are made\n"
" to the file specified when the program was \
started.\n");
printf(
"Additional feature: In this program includes a prompt\n"
"to save when the exit command is given. (This prompt\n"
"is given only when the records have not been saved since\n"
"the last added record).\n");
printf(
"Additional feature: This program has a debug mode so that\n"
"the user can see how the program works. This debug mode \
allows\n"
"the user to print the linked list and its pointers.\n");
}