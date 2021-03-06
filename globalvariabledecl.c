/* SUMINT.C routines to sum integers and increment a counter. */
/* Declare the variables that will be shared between these functions. */
long int lSum; // Using ‘int’ is optional.
long int lCount;
void SumInt(
    int nItem)
{
    lSum += (long)nItem;
    ++lCount;
}
/* Declare the variables that will be shared between these functions. */
extern long int lSum; // Using ‘int’ is optional.
extern long int lCount;
/* SUBINT.C routines to de-sum integers and decrement a counter. */
void SubInt(
    int nItem)
{
    lSum -= (long)nItem;
    --lCount;
}
/* AVERAGE.C routines to return the average. */
/* Declare the variables that will be shared between these functions. */
extern long int lSum; // Using ‘int’ is optional.
extern long int lCount;
int Average()
{
    int nReturn = 0;
    nReturn = (int)(lSum / lCount);
    return (nReturn);
}
