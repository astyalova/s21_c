#include "s21_string.h"

// memmove в отличии от memcpy обрабатывает исключение если один массив входит
// или частично состоит из 2го массива - для этого создается промежуточный
// массив - в который копируются данные из 2го, и результирующий копируется из
// него
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *res = (unsigned char *)dest;
  const unsigned char *source = (unsigned char *)src;
  unsigned char *tmp = (unsigned char *)malloc(sizeof(unsigned char) * n);
  if (NULL == tmp) {
    return NULL;
  } else {
    s21_size_t i = 0;
    for (i = 0; i < n; ++i) {
      *(tmp + i) = *(source + i);
    }
    for (i = 0; i < n; ++i) {
      *(res + i) = *(tmp + i);
    }
    free(tmp);
  }
  return dest;
}
