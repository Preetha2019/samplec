#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 5

int main() {
  int arr_sort[MAX_SIZE], i, j, k, a, t;

  printf("Simple Shell Sort Example - Functions and Array\n");
  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &arr_sort[i]);

  printf("\nYour Data   :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

  for (i = MAX_SIZE / 2; i > 0; i = i / 2) {
    for (j = i; j < MAX_SIZE; j++) {
      for (k = j - i; k >= 0; k = k - i) {
        if (arr_sort[k + i] >= arr_sort[k])
          break;
        else {
          //Swapping Values 
          t = arr_sort[k];
          arr_sort[k] = arr_sort[k + i];
          arr_sort[k + i] = t;
        }
      }

      printf("\nShell Sort Iteration [%d:%d] ", i, j);
      for (a = 0; a < MAX_SIZE; a++) {
        printf("\t%d", arr_sort[a]);
      }
    }

  }

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }
  getch();
}