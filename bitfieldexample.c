#include <stdio.h> 
  
// Space optimized representation of the date 
struct date { 
    // d has value between 1 and 31, so 5 bits 
    // are sufficient 
    unsigned int d : 5; 
  
    // m has value between 1 and 12, so 4 bits 
    // are sufficient 
    unsigned int m : 4; 
  
    unsigned int y; 
}; 
  
int main() 
{ 
    printf("Size of date is %lu bytes\n", sizeof(struct date)); 
    struct date dt = { 31, 12, 2014 }; 
    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y); 
    return 0; 
}
