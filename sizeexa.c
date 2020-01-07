#include <stdio.h>
// structure C
typedef struct structc_tag
{

   double f;
   double g;
   double a;
   double c;
   double h;
   double e;
   double w;
   double z;
   double i;
   double j;
   double n;
   double m;
   double p;
   double k;
   double u;
   int s;
   int d;

} structc_t;
int main()
{
   printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
}