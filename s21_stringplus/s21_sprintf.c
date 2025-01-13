#include "s21_string.h"

struct option {
  int width;  // ширина
  int prec;   // точность
  int space;  // ghj,tk
  int len;
  int ljust;
  int sign;
  int l;
  int h;
  int L;
  int u;
  int f;
  int base;  // система счисления 2 8 16
  int hash;
  int upper;  // большие буквы в 16 с\с
  int g;
  long long e;
  int zeroP;
};

#define noOption -1
#define widthOption 0
#define precOption 1
#define endOption 2

char *itoa(int value, char *result, int base, struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    if (options->f == 0) {
      options->prec--;
    }
  } while (value);

  if (options->prec > -1 && options->f == 0) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  if (tmp_value < 0) {
    *ptr++ = '-';
  } else if (tmp_value >= 0 && options->sign == 1) {
    *ptr++ = '+';
  } else if (options->space) {
    *ptr++ = ' ';
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

char *litoa(long long value, char *result, int base, struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    if (options->f == 0) {
      options->prec--;
    }
  } while (value);

  if (options->prec > -1 && (options->f == 0 || options->zeroP == 1)) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  if (tmp_value < 0) {
    *ptr++ = '-';
  } else if (tmp_value >= 0 && options->sign == 1) {
    *ptr++ = '+';
  } else if (options->space) {
    *ptr++ = ' ';
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

char *hitoa(short value, char *result, int base, struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    options->prec--;
  } while (value);

  if (options->prec > -1) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  if (tmp_value < 0) {
    *ptr++ = '-';
  } else if (tmp_value >= 0 && options->sign == 1) {
    *ptr++ = '+';
  } else if (options->space) {
    *ptr++ = ' ';
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

char *uitoa(unsigned int value, char *result, int base,
            struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    options->prec--;
  } while (value);

  if (options->prec > -1) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

char *ulitoa(unsigned long long value, char *result, int base,
             struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    options->prec--;
  } while (value);

  if (options->prec > -1) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

char *uhitoa(unsigned short value, char *result, int base,
             struct option *options) {
  if (base < 2 || base > 36) {
    *result = '\0';
    return result;
  }

  char *ptr = result, *ptr1 = result, tmp_char;
  long long tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
        "uvwxyz"[35 + (tmp_value - value * base)];
    options->prec--;
  } while (value);

  if (options->prec > -1) {
    while (options->prec) {
      *ptr++ = '0';
      options->prec--;
    }
  }

  *ptr-- = '\0';
  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

void resetOption(struct option *options) {
  options->width = -1;
  options->prec = -1;
  options->space = 0;
  options->len = 0;
  options->ljust = 0;
  options->sign = 0;
  options->l = 0;
  options->h = 0;
  options->L = 0;
  options->u = 0;
  options->f = 0;
  options->base = 0;
  options->hash = 0;
  options->upper = 0;
  options->e = -2281337;
  options->zeroP = 0;
  options->g = 0;
}

void formatDecimal(struct option *options, char *buff, long long num) {
  int i = 0;
  char *str = malloc(BUFF_SIZE);
  s21_strcpy(str, "");
  char currChar;
  int shift = 0;

  if (num == 0 && options->prec == 0) {
  } else if (options->l) {
    if (options->u) {
      ulitoa(num, str, options->base, options);
    } else {
      litoa(num, str, options->base, options);
    }

  } else if (options->h) {
    if (options->u) {
      uhitoa(num, str, options->base, options);
    } else {
      hitoa(num, str, options->base, options);
    }
  } else {
    if (options->u) {
      uitoa(num, str, options->base, options);
    } else {
      itoa(num, str, options->base, options);
    }
  }

  if (num != 0 && (options->hash != 0 || options->upper == 2)) {
    if (options->base == 8) {
      shift = 1;
    } else if (options->base == 16 && options->upper == 1) {
      shift = 2;
    } else if (options->base == 16 && options->upper == 2) {
      shift = 4;
    } else if (options->base == 16) {
      shift = 2;
    }
  } else if (num == 0 && options->upper == 2) {
    shift = 2;
  }

  if (options->upper == 1) {
    int i = 0;
    while (*(str + i)) {
      *(str + i) = toupper(*(str + i));
      i++;
    }
  }

  if (options->width != -1) {
    if (options->width <= (int)s21_strlen(str) + shift) {
    } else if (options->ljust == 0) {
      for (int i = 0; i < options->width - (int)s21_strlen(str) - shift; i++) {
        s21_strncat(buff, " ", 1);
      }
    }
  }

  if (num != 0 && (options->hash != 0 || options->upper == 2)) {
    if (options->base == 8) {
      s21_strncat(buff, "0", 1);
    } else if (options->base == 16 && options->upper == 1) {
      s21_strncat(buff, "0X", 2);
    } else if (options->base == 16 && options->upper == 2) {
      s21_strncat(buff, "0x10", 4);
    } else if (options->base == 16) {
      s21_strncat(buff, "0x", 2);
    }
  } else if (num == 0 && options->upper == 2) {
    s21_strncat(buff, "0x", 2);
  }

  while (*(str + i) != '\0') {
    currChar = *(str + i);
    s21_strncat(buff, &currChar, 1);
    i++;
  }
  if (options->ljust == 1 && options->width > (int)s21_strlen(str) + shift) {
    for (int i = 0; i < options->width - (int)s21_strlen(str) - shift; i++) {
      s21_strncat(buff, " ", 1);
    }
  }
  free(str);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);

  struct option options;
  resetOption(&options);

  char charArg;

  char *buff = malloc(BUFF_SIZE + 1);
  char *strArg = malloc(BUFF_SIZE + 1);
  s21_strcpy(buff, "");

  unsigned long intArg;
  long double doubleArg int i = 0;
  int argFlag = 0;
  int currFlag = noOption;
  char currChar = *format;

  while (format != s21_NULL && *(format + i) != '\0') {
    currChar = *(format + i);
    if (currChar == '%' && argFlag == 0) {
      argFlag = 1;
      currFlag = noOption;
    } else if (argFlag == 0) {
      s21_strncat(buff, &currChar, 1);
    } else if (argFlag == 1) {
      if (isdigit(currChar)) {
        if (currFlag == noOption) {
          if (currChar == '0') {
            options.zeroP = 1;
            currFlag = precOption;
            options.prec = 0;
          } else {
            currFlag = widthOption;
            options.width = currChar - '0';
          }
        } else if (currFlag == widthOption) {
          options.width = options.width * 10 + currChar - '0';
        } else if (currFlag == precOption) {
          options.prec = options.prec * 10 + currChar - '0';
        }
      } else if (currChar == '.') {
        if (currFlag != precOption) {
          currFlag = precOption;
          options.prec = 0;
        } else {
          options.width = 0;
          options.zeroP = 0;
          options.prec = 0;
        }
      } else if (currChar == '-') {
        options.ljust = 1;
        currFlag = noOption;
      } else if (currChar == '+') {
        options.sign = 1;
        currFlag = noOption;
      } else if (currChar == ' ') {
        options.space = 1;
        currFlag = noOption;
      } else if (currChar == 'h') {
        options.h = 1;
        currFlag = noOption;
      } else if (currChar == 'l') {
        options.l = 1;
        currFlag = noOption;
      } else if (currChar == 'L') {
        options.L = 1;
        currFlag = noOption;
      } else if (currChar == '#') {
        options.hash = 1;
        currFlag = noOption;
      } else if (currChar == '*') {
        if (currFlag == precOption) {
          options.prec = va_arg(va, int);
        } else {
          options.width = va_arg(va, int);
        }
        currFlag = noOption;
      } else {
        argFlag = 0;
        currFlag = endOption;
      }
    }
    if (currFlag == endOption) {
      if (currChar == 'c' || currChar == '%') {
        options.prec = -1;
        if (currChar == '%') {
          formatString(&options, buff, "%");
        } else {
          charArg = va_arg(va, int);
          s21_strcpy(strArg, &charArg);
          strArg[1] = 0;
          formatString(&options, buff, strArg);
        }

      } else if (currChar == 's') {
        s21_strcpy(strArg, va_arg(va, char *));
        formatString(&options, buff, strArg);

      } else if (currChar == 'p') {
        options.base = 16;
        options.upper = 2;
        intArg = (long)va_arg(va, void *);
        formatDecimal(&options, buff, intArg);

      } else if (currChar == 'd' || currChar == 'i') {
        options.base = 10;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'o') {
        options.base = 8;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'b') {
        options.base = 2;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'u') {
        options.base = 10;
        options.u = 1;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'x') {
        options.base = 16;
        options.u = 1;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'X') {
        options.base = 16;
        options.upper = 1;
        options.u = 1;
        intArg = va_arg(va, long);
        formatDecimal(&options, buff, intArg);
      } else if (currChar == 'f') {
        options.base = 10;
        options.f = 1;
        if (options.L) {
          doubleArg = va_arg(va, long double);
        } else {
          doubleArg = va_arg(va, double);
        }
        formatFloat(&options, buff, doubleArg);
      } else if (currChar == 'g' || currChar == 'G') {
        options.g = 1;
        options.base = 10;
        options.f = 1;
        if (options.L) {
          doubleArg = va_arg(va, long double);
        } else {
          doubleArg = va_arg(va, double);
        }
        long long inum = (long long)log10l(fabsl(doubleArg));
        if (options.prec == -1 && inum > 0) {
          options.prec = 5 - inum;
        } else if (options.prec == -1) {
          options.prec = 6;
        }
        if (options.prec == 0 && inum > -6) {
          options.prec = find_nonzero(doubleArg);
        } else if (inum <= -5 && doubleArg != 0) {
          options.e = inum - 1;
          if (currChar == 'G') {
            options.upper = 1;
          }
          doubleArg = (doubleArg / pow(10, options.e));
        }

        formatFloat(&options, buff, doubleArg);
      } else if (currChar == 'e' || currChar == 'E') {
        if (currChar == 'E') {
          options.upper = 1;
        }
        options.base = 10;
        options.f = 1;
        if (options.L) {
          doubleArg = va_arg(va, long double);
          options.e = (long long)log10l(fabsl(doubleArg));
          if (options.e < 0) {
            options.e--;
          }
          long double mantissa = (doubleArg / powl(10, options.e));
          doubleArg = mantissa;
        } else {
          doubleArg = va_arg(va, double);
          options.e = (long long)log10(fabsl(doubleArg));
          if (options.e > -1e10 && options.e < 0) {
            options.e--;
          }
          double mantissa = (doubleArg / pow(10, options.e));
          doubleArg = mantissa;
        }
        formatFloat(&options, buff, doubleArg);
      }
      currFlag = noOption;
      resetOption(&options);
    }
    i++;
  }

  s21_strcpy(str, buff);

  int answ = (int)s21_strlen(buff);
  free(buff);
  free(strArg);
  va_end(va);
  return answ;
}