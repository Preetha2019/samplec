long int lSum; 
long int lSub;// Using ‘int’ is optional.
long int lCount;
void SumInt(int nItem)
{
lSum += (long)nItem;
++lCount;
}
void SubInt(
int nItem)
{
lSum -= (long)nItem;
--lCount;
}
int Average()
{
int nReturn = 0;
nReturn = (int)(lSum / lCount);
return (nReturn);
}