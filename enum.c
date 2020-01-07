#include <stdio.h>
void main()
{
  int i;
  enum month
  {
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    DEC
  };
  for (i = JAN; i <= DEC; i++)
    printf("\n%d", i);
}