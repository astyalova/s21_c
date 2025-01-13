#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  unsigned char *res = (unsigned char *)str;
  unsigned char *symbol = NULL;
  while (n--) {
    if (*res != (unsigned char)c) {
      res++;  // крч говоря принцип работы в том, что *p указывает просто в
              // начале на первый символ строки
              //  и мы прибавляем ++ если в данный момент указывает на не нужный
              //  символ
              // с
    } else {
      symbol = res;
      break;
    }
  }
  return symbol;
}