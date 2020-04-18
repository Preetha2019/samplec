#include <stdio.h>
#define max 10
int a[11] = { 19, 11, 14, 04, 1996, 20, 21, 22, 15, 07, 26 };
int b[10];
void merge(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merge(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("Given elements are:\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\n sorted elements are:\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}