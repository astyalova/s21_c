#include "s21_string.h"

// сравнивает все символы именно по n, даже если n больше массивов, возвращает
// int разницу между первыми различн символами
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *res = (const unsigned char *)str1;
  const unsigned char *source = (const unsigned char *)str2;
  int compare = 0;
  while (n) {
    if (*res != *source) {
      compare = (int)*res - (int)*source;
      break;
    }
    n--;
    res++;
    source++;
  }
  return compare;
}
