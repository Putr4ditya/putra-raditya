#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int minimum_swaps(int cards[], int n) {
  int swaps = 0;
  int swapped = 1; 

  while (swapped) {
    swapped = 0;
    for (int i = 0; i < n - 1; i++) {
      if (cards[i] > cards[i + 1]) {
        swap(&cards[i], &cards[i + 1]);
        swaps++;
        swapped = 1; 
      }
    }
  }
  return swaps;
}

int main() {
  int n;
  printf("Masukkan Jumlah Kartu: ");
  scanf("%d", &n);

  int cards[n];
  printf("Masukkan Nilai Kartu: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &cards[i]);
  }

  int min_swaps = minimum_swaps(cards, n);
  printf("Minimum pengacakan: %d\n", min_swaps);

  for (int i = 0; i < n; i++) {
    printf("Setelah Pengacakan %d: ", i + 1);
    for (int j = 0; j < n; j++) {
      printf("%d ", cards[j]);
    }
    printf("\n");
  }

  return 0;
}
