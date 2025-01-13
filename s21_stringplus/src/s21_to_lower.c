#include "s21_string.h"

void* s21_to_lower(const char* str) {
  if (str == NULL) return NULL;
  int len = s21_strlen(str);
  char* lower_str = (char*)malloc(sizeof(char) * (len + 1));
  if (lower_str == NULL) return NULL;
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i]) && isupper(str[i]))
      lower_str[i] = tolower(str[i]);
    else
      lower_str[i] = str[i];
  }
  lower_str[len] = '\0';
  return (void*)lower_str;
}
