#include "s21_string.h"

void* s21_to_upper(const char* str) {
  if (str == NULL) return NULL;
  int len = s21_strlen(str);
  char* upper_str = (char*)malloc(sizeof(char) * (len + 1));
  if (upper_str == NULL) return NULL;
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i]) && islower(str[i]))
      upper_str[i] = toupper(str[i]);
    else
      upper_str[i] = str[i];
  }
  upper_str[len] = '\0';
  return (void*)upper_str;
}
