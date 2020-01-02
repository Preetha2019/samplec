#include <stdlib.h> // For standard functions
#include <stdio.h> // Make includes first part of file
#include <string.h> // For string functions
#include <process.h> // For exit(), etc.
#include <malloc.h> // For malloc(), calloc(), realloc(), free()
#include <search.h> // For qsort()
#include <time.h> // To initialize the random-number functions
/* B-tree search and add, find, and delete
* Adapted from
* ALGORITHMS+DATA STRUCTURES=PROGRAMS by N. Wirth
*
* Implemented for BDS C by H. Katayose (JUG-CP/M No.179)
* Implemented for ANSI C by P. Hipson (CUG)
*/
/* PAGE_SIZE is better at 8 (less memory fragmentation) */
#define PAGE_SIZE 2
#define HALF_PAGE_SIZE (PAGE_SIZE / 2)
#define PAGE struct _page
#define ITEM struct _item
#define ROOT 0
#define RIGHT 1
#define LEFT 2
#define TRUE (1)
#define FALSE (0)
/* Storage allocation structures used by malloc() */
struct _header
{
struct _header *_ptr;
unsigned _size;
};
struct _header _base; /* Declare this external data to */
struct _header *_allocp; /* be used by malloc() */
/* B-tree structures */
struct _item
{
int nKeyValue;
PAGE *RightReference;
int nCount;
};
struct _page
{
int nItemCount;
PAGE *LeftReference;
ITEM Item[PAGE_SIZE];
};
/* Function prototypes */
int Search(int nKeyValue, int * nLevelCount, PAGE *a, ITEM *v);
int SearchAndAdd(int nKeyValue, PAGE *a, ITEM *v);
int Insert(PAGE *a, int i, ITEM *u, ITEM *v);
int CopyItem(ITEM *DestinationItem, ITEM *SourceItem);
int NewItem(PAGE **Page);
int TreePrint(PAGE *p, int l, int nRightLeft, int nPosition);
int DeleteItem(int nKeyValue, PAGE *a);
int UnderFlow(PAGE *c, PAGE *a, int s);
int Delete(PAGE *p, PAGE *a, int k);
void PrintHelp(void);
/* The main program */
int main()
{
int i;
int j;
int nKeyValue;
int h;
int nLevelCount = 0;
char chOperation;
char szCommand[132];
PAGE *q;
PAGE *root;
ITEM u;
printf("\n\nBTREE: Demo program for B-trees\n"
"\n"
"Command are:\n"
" A # - Adds key # (integer 0 - 32767).\n"
" D # - Deletes key # (integer 0 - 32767).\n"
" S # - Searches for key # (integer 0 - 32767).\n"
" R # - Adds # random keys (integer 0 - 2000).\n"
" H - Prints a help screen.\n"
" T - Prints the current B-tree structure.\n"
" X - Exits, after a confirming prompt.\n\n");
root = NULL;
while (TRUE)
{
printf("\n\nCommand ?");
gets(szCommand);
sscanf(szCommand, "%c %d", &chOperation, &nKeyValue);
switch(chOperation)
{
case 'h':
case 'H':
PrintHelp();
break;
case 'r':
case 'R':
printf("ADDING %d NODES\n", nKeyValue);
srand((unsigned)time(NULL));
if (nKeyValue > 2000)
{
nKeyValue = 2000;
}
for (i = 0; i < nKeyValue; i++)
{
j = rand();
if (SearchAndAdd(j, root, &u))
{
q = root;
NewItem(&root);
root->nItemCount = 1;
root->LeftReference = q;
CopyItem(&root->Item[0], &u);
}
}
TreePrint(root, 0, ROOT, 0);
break;
case 's':
case 'S':
nLevelCount = 0;
if ((Search(nKeyValue, &nLevelCount, root, &u)))
{
printf("SEARCH KEY %d found by searching %d \
levels\n",
nKeyValue,
nLevelCount);
}
else
{
printf("SEARCH KEY %d NOT FOUND searching %d \
levels\n",
nKeyValue,
nLevelCount);
}
break;
case 'a':
case 'A':
printf("ADD KEY %d\n", nKeyValue);
if (SearchAndAdd(nKeyValue, root, &u))
{
q = root;
NewItem(&root);
root->nItemCount = 1;
root->LeftReference = q;
CopyItem(&root->Item[0], &u);
}
TreePrint(root, 0, ROOT, 0);
break;
case 't':
case 'T':
printf("PRINT TREE\n");
TreePrint(root, 0, ROOT, 0);
break;
case 'd':
case 'D':
printf("DELETE KEY %d\n", nKeyValue);
if (DeleteItem(nKeyValue, root))
{
if (root->nItemCount == 0)
{
q = root;
root = q->LeftReference;
}
}
TreePrint(root, 0, ROOT, 0);
break;
case 'x':
case 'X':
printf("Confirm exit, y|n:");
scanf("%c", &chOperation);
if (chOperation == 'y' ||
chOperation == 'Y')
{
exit(0);
}
break;
default:
printf("\aUnknown operation '%c'\n",
chOperation);
break;
}
}
return(0);
}
int Search(
int nKeyValue,
int *nLevelCount,
PAGE *a,
ITEM *v)
{
int i;
ITEM u;
// printf(“Search()...\n”);
if (a == NULL)
{
return(FALSE);
}
for (i = 0; i < a->nItemCount && nKeyValue > a->Item[i].nKeyValue;
i++)
{
;
}
if (nKeyValue == a->Item[i].nKeyValue && i < a->nItemCount)
{
return(TRUE);
}
else
{
++(*nLevelCount);
return(Search(nKeyValue, nLevelCount,
i ? a->Item[i - 1].RightReference : a->LeftReference, &u));
}
}
int SearchAndAdd(
int nKeyValue,
PAGE *a,
ITEM *v)
{
int i;
ITEM u;
// printf(“SearchAndAdd()...\n”);
if (a == NULL)
{
v->nKeyValue = nKeyValue;
v->nCount = 1;
v->RightReference = NULL;
return TRUE;
}
for (i = 0; i < a->nItemCount && nKeyValue > a->Item[i].nKeyValue;
i++)
{
;
}
if (nKeyValue == a->Item[i].nKeyValue && i < a->nItemCount)
{
a->Item[i].nCount++;
}
else
{
if (SearchAndAdd(nKeyValue,
i ? a->Item[i - 1].RightReference : a->LeftReference, &u))
{
return (Insert(a, i, &u, v));
}
}
return FALSE;
}
int Insert(
PAGE *a,
int i,
ITEM *u,
ITEM *v)
{
PAGE *b;
int j;
int h;
// printf(“Insert()...\n”);
if (a->nItemCount < PAGE_SIZE)
{
for (j = a->nItemCount; j >= i + 1; j—)
{
CopyItem(&a->Item[j], &a->Item[j - 1]);
}
++a->nItemCount;
CopyItem(&a->Item[i], u);
return(FALSE);
}
else
{/* Page a is full. Split it and assign the emerging item to v. */
NewItem(&b);
if (i <= HALF_PAGE_SIZE)
{
if (i == HALF_PAGE_SIZE)
{
CopyItem(v, u);
}
else
{
CopyItem(v, &a->Item[HALF_PAGE_SIZE - 1]);
for (j = HALF_PAGE_SIZE - 1; j >= i + 1; j--)
{
CopyItem(&a->Item[j], &a->Item[j - 1]);
}
CopyItem(&a->Item[i], u);
}
for (j = 0; j <= HALF_PAGE_SIZE - 1; j++)
{
CopyItem(&b->Item[j], &a->Item[j + HALF_PAGE_SIZE]);
}
}
else
{
i -= HALF_PAGE_SIZE;
CopyItem(v, &a->Item[HALF_PAGE_SIZE]);
for (j = 0; j <= i - 2; j++)
{
CopyItem(&b->Item[j], &a->Item[j + HALF_PAGE_SIZE + 1]);
}
CopyItem(&b->Item[i - 1], u);
for (j = i; j <= HALF_PAGE_SIZE - 1; j++)
{
CopyItem(&b->Item[j], &a->Item[j + HALF_PAGE_SIZE]);
}
}
if (HALF_PAGE_SIZE == 0)
{
a->nItemCount = 1;
b->nItemCount = 1;
}
else
{
a->nItemCount = HALF_PAGE_SIZE;
b->nItemCount = HALF_PAGE_SIZE;
}
b->LeftReference = v->RightReference;
v->RightReference = b;
}
return(TRUE);
}
int CopyItem(
ITEM *DestinationItem,
ITEM *SourceItem)
{
// printf(“CopyItem()...\n”);
DestinationItem->nKeyValue = SourceItem->nKeyValue;
DestinationItem->RightReference = SourceItem->RightReference;
DestinationItem->nCount = SourceItem->nCount;
return(0);
}
int NewItem(
PAGE **Page)
{
// printf(“NewItem()...\n”);
if ((*Page = (PAGE *)malloc(sizeof(**Page))) == NULL)
{
fprintf(stderr, "Couldn't allocate memory!\n");
exit(16);
}
/* malloc() doesn’t initialize storage, so we do. */
memset(*Page, 0, sizeof(**Page));
return(0);
}
int TreePrint(
PAGE *Page,
int nLevel,
int nRightLeft,
int nPosition)
{
int i;
int j;
if (Page != NULL)
{
for (i = 0; i < Page->nItemCount; i++)
{
switch(nRightLeft)
{
case ROOT: /* Should have only one root */
printf("\n");
printf("(ROOT %2d) ", nLevel);
break;
case LEFT: /* Happens all the time */
printf("(L %2d %2d) ", nLevel, nPosition);
break;
case RIGHT:/* Happens all the time */
printf("(R %2d %2d) ", nLevel, nPosition);
break;
default: /* Should never happen */
printf("ERROR ");
break;
}
for (j = 0; j < nLevel; j++)
{/* Adjust the starting column for the variable */
printf(".....");
}
printf("%5d \n", Page->Item[i].nKeyValue);
if (Page->Item[i].RightReference != NULL)
{
TreePrint(Page->Item[i].RightReference,
nLevel + 1, RIGHT, i + 1);
}
}
if (Page->LeftReference != NULL)
{
TreePrint(Page->LeftReference, nLevel + 1, LEFT, 0);
}
}
return(0);
}
int DeleteItem(
int nKeyValue,
PAGE *a)
{
int i;
int k;
int l;
int r;
PAGE *q;
// printf(“DeleteItem()...\n”);
if (a == NULL)
{
printf("Key is not in tree! Cannot delete this key.\n");
return FALSE;
}
else
{/* Binary array search */
for (l = 0, r = a->nItemCount - 1; l <= r; )
{
k = (l + r) / 2;
if (nKeyValue <= a->Item[k].nKeyValue)
{
r = k - 1;
}
if (nKeyValue >= a->Item[k].nKeyValue)
{
l = k + 1;
}
}
q = (r == -1) ? a->LeftReference : a->Item[r].RightReference;
if (l - r > 1)
{/* Found; now delete Item[k] */
if (q == NULL)
{/* a is a terminal page */
—(a->nItemCount);
for (i = k; i < a->nItemCount; i++)
{
CopyItem(&a->Item[i], &a->Item[i + 1]);
}
return (a->nItemCount < HALF_PAGE_SIZE);
}
else
{
if (Delete(q, a, k))
{
return(UnderFlow(a, q, r));
}
}
}
else
{
if (DeleteItem(nKeyValue, q))
{
return UnderFlow(a, q, r);
}
}
}
}
int UnderFlow(
PAGE *c,
PAGE *a,
int s)
{
PAGE *b;
int i;
int k;
int mb;
int mc;
// printf(“UnderFlow()...\n”);
mc = c->nItemCount;
if (s < mc - 1)
{
++s;
b = c->Item[s].RightReference;
mb = b->nItemCount;
k = (mb - HALF_PAGE_SIZE + 1) / 2;
CopyItem(&a->Item[HALF_PAGE_SIZE - 1], &c->Item[s]);
a->Item[HALF_PAGE_SIZE - 1].RightReference = b->LeftReference;
if (k > 0)
{
for(i = 0; i < k - 1; i++)
{
CopyItem(&a->Item[i + HALF_PAGE_SIZE], &b->Item[i]);
}
CopyItem(&c->Item[s], &b->Item[k - 1]);
c->Item[s].RightReference = b;
b->LeftReference = b->Item[k - 1].RightReference;
mb -= k;
for (i = 0; i < mb; i++)
{
CopyItem(&b->Item[i], &b->Item[i + k]);
}
b->nItemCount = mb;
a->nItemCount = HALF_PAGE_SIZE - 1 + k;
return(FALSE);
}
else
{
for (i = 0; i < HALF_PAGE_SIZE; i++)
{
CopyItem(&a->Item[i + HALF_PAGE_SIZE], &b->Item[i]);
}
for (i = s; i < mc; i++)
{
CopyItem(&c->Item[i], &c->Item[i + 1]);
}
a->nItemCount = PAGE_SIZE;
c->nItemCount = mc - 1;
}
}
else
{
b = (s == 0) ? c->LeftReference : c->Item[s - 1].RightReference;
mb = b->nItemCount + 1;
k = (mb - HALF_PAGE_SIZE) / 2;
if (k > 0)
{
for(i = HALF_PAGE_SIZE - 2; i >= 0; i--)
{
CopyItem(&a->Item[i + k], &a->Item[i]);
}
CopyItem(&a->Item[k - 1], &c->Item[s]);
a->Item[k - 1].RightReference = a->LeftReference;
mb -= k;
for (i = k - 2; i >= 0; i--)
{
CopyItem(&a->Item[i], &b->Item[i + mb]);
}
a->LeftReference = b->Item[mb].RightReference;
CopyItem(&c->Item[s], &b->Item[mb - 1]);
c->Item[s].RightReference = a;
b->nItemCount = mb - 1;
a->nItemCount = HALF_PAGE_SIZE - 1 + k;
return(FALSE);
}
else
{
CopyItem(&b->Item[mb], &c->Item[s]);
b->Item[mb].RightReference = a->LeftReference;
for (i = 0; i < HALF_PAGE_SIZE - 1; i++)
{
CopyItem(&b->Item[i + mb], &a->Item[i]);
}
b->nItemCount = PAGE_SIZE;
c->nItemCount = mc - 1;
}
}
return(TRUE);
}
int Delete(
PAGE *p,
PAGE *a,
int k)
{
PAGE *q;
// printf(“Delete()...\n”);
if ((q = p->Item[p->nItemCount - 1].RightReference)!= NULL)
{
if (Delete(q, a, k))
{
return(UnderFlow(p, q, p->nItemCount - 1));
}
}
else
{
p->Item[p->nItemCount - 1].RightReference = a
->Item[k].RightReference;
CopyItem(&a->Item[k], &p->Item[p->nItemCount - 1]);
—(p->nItemCount);
return(p->nItemCount < HALF_PAGE_SIZE);
}
}
void PrintHelp()
{
printf(
"\n\nBTREE: Demo program for B-trees\n"
"\n"
"Command are:\n"
" A # - Adds key # (integer 0 - 32767).\n"
" D # - Deletes key # (integer 0 - 32767).\n"
" S # - Searches for key # (integer 0 - 32767).\n"
" R # - Adds # random keys (integer 0 - 2000).\n"
" H - Prints a help screen.\n"
" T - Prints the current B-tree structure.\n"
" X - Exits, after a confirming prompt.\n\n");
printf("\n"
"All keys (the items that are placed in the tree) are \
integers,\n"
"ranging from 0 to 32767. Each item is added to the tree when \
the\n"
"Add command is issued.\n");
printf("\n"
"A new key is added with the Add command. Enter an A and an\n"
"integer value.\n");
printf("\n"
"An existing key can be deleted by using the Delete command.\n"
"Enter a D followed by an integer key value. If the value \
entered\n"
"is not a valid key, the program will tell you so.\n");
printf("\n"
"When you search for a key, the tree is traversed. If the key\n"
"is found, the level where it was found is provided. If the \
key\n"
"is not found, a message is printed.\n");
printf("\n"
"The Repeat command is used to build a table of random keys. \
The\n"
"rand() function is called the specified number of times. No\n"
"test for duplicates is made, but duplicates for random-number\n"
"counts of less than several hundred are infrequent.\n");
printf("\n"
"To print the entire tree structure, use the Tree command. \
This\n"
"command is entered as a T. There are no parameters for "
"this command.\n");
printf("\n"
"To end the program, use the Exit command. Enter an X, with no\n"
"parameters. You will be prompted to confirm that you want to\n"
"exit.\n");
printf("\n"
"If you don't enter the key (or count for Repeat), the \
previous\n"
"value for the count is used.\n");
}