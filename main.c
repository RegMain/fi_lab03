 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void make_linear(int32_t n, int32_t a[n][n]) {
  for (int32_t i = 0; 2 * i < n; i += 1) {
    for (int32_t j = n - 1 - i; j >= i; --j) {
      printf("%d ", a[i][j]);
    }
    for (int32_t j = i + 1; j < n - i; ++j) {
      printf("%d ", a[j][i]);
    }
    for (int32_t j = i + 1; j < n - i; ++j) {
      printf("%d ", a[n - i - 1][j]);
    }
    for (int32_t j = n - 2 - i; j > i; --j) {
      printf("%d ", a[j][n - i - 1]);
    }
  }
}

int32_t find_sum_with_max(int32_t n, int32_t a[n][n]) {
  if (n < 1) return 0;
  int32_t current_sum;
  int32_t mx = INT32_MIN;
  int32_t answer = 0;
  int flag;
  for (int32_t i = 0; i < n; ++i) {
    current_sum = 0;
    flag = 0;
    for (int32_t j = 0; j < n; ++j) {
      current_sum += a[i][j];
      if (a[i][j] > mx) {
        mx = a[i][j];
        flag = 1;
      }
    }
    if (flag) {
      answer = current_sum;
    }
  }
  return answer;
}

int main(void) {
  // 23
  int32_t n;
  scanf("%d", &n);
  int32_t (*a)[n] = (int32_t (*)[])malloc(sizeof(*a) * n);
  if (!a) {
    printf("Error");
    return 0;
  }
  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  printf("\n");
  make_linear(n, a);
  printf("\n");
  printf("%d\n", find_sum_with_max(n, a));
  free(a);
  return 0;
}
