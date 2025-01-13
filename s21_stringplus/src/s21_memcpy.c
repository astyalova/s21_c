#include "s21_string.h"

// - если N больше, то определение не определено - то есть копирует по n без
// вспом ограничений - цикл до < n, не обрабатывает /0 в конце строки, то есть
// не нужно такое ограничение в имплементации
// - зачем мы переуказываем указатели в новые
// переменные не понятно - но это используется в реализациях в инете
// - меняет сам dest и возвращает его
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *res = (unsigned char *)dest;
  const unsigned char *source = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    res[i] = source[i];
  }
  return dest;
}
