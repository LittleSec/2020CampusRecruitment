#include <stdio.h>
#include <stdlib.h>

void display(int **j, int N) {
  printf("when N = %d, zigzag is follow\n", N);
  int p, q;
  for (p = 0; p < N; p++) {
    for (q = 0; q < N; q++) {
      printf("%3d ", j[p][q]);
    }
    printf("\n");
  }
}

int main() {
  int N, i, j;
  printf("input N(size of zigzag): ");
  scanf("%d", &N);
  int **jpg = (int**)malloc(N * sizeof(int*));
  for (i = 0; i < N; i++) {
    jpg[i] = (int*)malloc(N * sizeof(int));
  }
  int cur = 0;
  char dir = 'x';
  i = 0, j = 0;
  jpg[0][0] = cur++;
  while (i <= N - 1 && j <= N - 1) {
    if (i == 0 || j == N - 1) {
      if (j != N - 1) {
        jpg[i][++j] = cur++;
      } else {
        jpg[++i][j] = cur++;
      }
      dir = 'x';
    }
    if (j == 0 || i == N - 1) {
      if (i != N - 1) {
        jpg[++i][j] = cur++;
      } else {
        jpg[i][++j] = cur++;
      }
      dir = 's';
    }
    if (dir == 'x') {
      jpg[++i][--j] = cur++;
    } else {
      jpg[--i][++j] = cur++;
    }
  }

  display(jpg, N);

  return 0;
}