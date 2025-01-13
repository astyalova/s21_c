#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  // dest – указатель на строку, в которую будут скопированы данные.
  // srс – указатель на строку источник копируемых данных.
  int n = s21_strlen(src);
  for (int i = 0; i <= n + 1; i++) {
    dest[i] = src[i];
  }
  return dest;
}
