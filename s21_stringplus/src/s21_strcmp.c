#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  // Сравнивает строку, на которую указывает str1, со строкой, на которую
  // указывает str2
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return *str1 - *str2;
}