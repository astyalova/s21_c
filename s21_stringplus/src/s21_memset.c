#include "s21_string.h"

// копирует символ в str - до n
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *res = str;
  while (n) {
    *res = (unsigned char)c;
    res++;
    n--;
  }
  return str;
}
