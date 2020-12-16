#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy(char *dest, char *src) {
  if (dest == NULL || src == NULL) {
    return NULL;
  }
  int size = strlen(src), i;
  char *tmp = (char *)malloc(size + 1);
  for (i = 0; i < size; i++) {
    tmp[i] = src[i];
  }
  tmp[size] = '\0';

  for (i = 0; i < size; i++) {
    dest[i] = tmp[i];
  }
  dest[size] = '\0';
  free(tmp);
  return dest;
}

int main() {
  char src[81];
  char dest[81];
  scanf("%s", src);
  mystrcpy(src, src + 4);
  printf("%s\n", src);
  scanf("%s", src);
  mystrcpy(src + 4, src);
  printf("%s\n", src);
  return 0;
}
