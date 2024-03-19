#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
  // Mengecek semua gerakan kuda yang mungkin dilakukan
  for (int di = -2; di <= 2; di++) {
    for (int dj = -2; dj <= 2; dj++) {
      // Abaikan gerakan yang tidak valid (keluar papan atau posisi awal)
      if (abs(di) == abs(dj) || i + di < 0 || i + di >= size || j + dj < 0 || j + dj >= size) {
        continue;
      }

      // Tandai posisi yang bisa dicapai kuda dengan nilai 1
      chessBoard[(i + di) * size + j + dj] = 1;
    }
  }
}

int main() {
  int size = 8; // Ukuran papan catur
  int chessBoard[size * size];

  // Inisialisasi papan catur dengan nilai 0 (kosong)
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      chessBoard[i * size + j] = 0;
    }
  }

  // Ambil input posisi awal kuda
  int i, j;
  printf("Masukkan posisi awal kuda (baris kolom): ");
  scanf("%d %d", &i, &j);

  // Panggil fungsi untuk menghitung gerakan kuda yang mungkin
  koboImaginaryChess(i, j, size, chessBoard);

  // Print hasil simulasi papan catur
  printf("Simulasi papan catur:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d", chessBoard[i * size + j]);
    }
    printf("\n");
  }

  return 0;
}