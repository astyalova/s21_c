#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  // str – указатель на строку.
  const char *p = str;
  while (*p != '\0') {
    p++;
  }
  return (p - str);
}