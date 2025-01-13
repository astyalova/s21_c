#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  // haystack – указатель на строку, в которой ведется поиск.
  // needle – указатель на искомую строку.
  const char *a;
  const char *b;
  b = needle;
  if (*b == 0) {
    return (char *)haystack;
  }
  for (; *haystack != 0; haystack += 1) {
    if (*haystack != *b) {
      continue;
    }
    a = haystack;
    while (1) {
      if (*b == 0) {
        return (char *)haystack;
      }
      if (*a++ != *b++) {
        break;
      }
    }
    b = needle;
  }
  return 0;
}