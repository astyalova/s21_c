#include "s21_string.h"

#define noOption -1
#define widthOption 0
#define precOption 1
#define endOption 2

void resetOption(struct option *formatOptions) {//функция берет указатель на структуру// устанвливает значения
  formatOptions->width = -1;
  formatOptions->prec = -1;
  formatOptions->space = 0;
  formatOptions->len = 0;
  formatOptions->ljust = 0;
  formatOptions->sign = 0;
  formatOptions->l = 0;
  formatOptions->h = 0;
  formatOptions->L = 0;
  formatOptions->u = 0;
  formatOptions->f = 0;
  formatOptions->numberBase = 0; //система счисления
  formatOptions->hash = 0;
  formatOptions->upper = 0;
  formatOptions->e = -2281337;
  formatOptions->zeroP = 0;
  formatOptions->g = 0;
}

int s21_sprintf(char *outputString, const char *formatString, ...) {
  va_list variableArguments;
  va_start(variableArguments, formatString);

  struct option formatOptions;
  resetOption(&formatOptions);

  char charArgument;

  char *buff = malloc(BUFF_SIZE + 1);
  char *strArg = malloc(BUFF_SIZE + 1);
  s21_strcpy(buff, "");

  unsigned long integerArgument;
  long double doubleArgument;
  int stringIterator = 0;
  int isArgument = 0;
  int currentOption = noOption;
  char currentCharacter = *formatString;

  while (formatString != s21_NULL && *(formatString + stringIterator) != '\0') {
    currentCharacter = *(formatString + stringIterator);
    if (currentCharacter == '%' && isArgument == 0) {
      isArgument = 1;
      currentOption = noOption;
    } else if (isArgument == 0) {
      s21_strncat(buff, &currentCharacter, 1);
    } else if (isArgument == 1) {
      if (isdigit(currentCharacter)) {
        if (currentOption == noOption) {
          if (currentCharacter == '0') {
            formatOptions.zeroP = 1;
            currentOption = precOption;
            formatOptions.prec = 0;
          } else {
            currentOption = widthOption;
            formatOptions.width = currentCharacter - '0';
          }
        } else if (currentOption == widthOption) {
          formatOptions.width =
              formatOptions.width * 10 + currentCharacter - '0';
        } else if (currentOption == precOption) {
          formatOptions.prec = formatOptions.prec * 10 + currentCharacter - '0';
        }
      } else if (currentCharacter == '.') {
        if (currentOption != precOption) {
          currentOption = precOption;
          formatOptions.prec = 0;
        } else {
          formatOptions.width = 0;
          formatOptions.zeroP = 0;
          formatOptions.prec = 0;
        }
      } else if (currentCharacter == '-') {
        formatOptions.ljust = 1;
        currentOption = noOption;
      } else if (currentCharacter == '+') {
        formatOptions.sign = 1;
        currentOption = noOption;
      } else if (currentCharacter == ' ') {
        formatOptions.space = 1;
        currentOption = noOption;
      } else if (currentCharacter == 'h') {
        formatOptions.h = 1;
        currentOption = noOption;
      } else if (currentCharacter == 'l') {
        formatOptions.l = 1;
        currentOption = noOption;
      } else if (currentCharacter == 'L') {
        formatOptions.L = 1;
        currentOption = noOption;
      } else if (currentCharacter == '#') {
        formatOptions.hash = 1;
        currentOption = noOption;
      } else if (currentCharacter == '*') {
        if (currentOption == precOption) {
          formatOptions.prec = va_arg(variableArguments, int);
        } else {
          formatOptions.width = va_arg(variableArguments, int);
        }
        currentOption = noOption;
      } else {
        isArgument = 0;
        currentOption = endOption;
      }
    }
    if (currentOption == endOption) {
      if (currentCharacter == 'c' || currentCharacter == '%') {
        formatOptions.prec = -1;
        if (currentCharacter == '%') {
          processString(&formatOptions, buff, "%");
        } else {
          charArgument = va_arg(variableArguments, int);
          s21_strcpy(strArg, &charArgument);
          strArg[1] = 0;
          processString(&formatOptions, buff, strArg);
        }

      } else if (currentCharacter == 's') {
        s21_strcpy(strArg, va_arg(variableArguments, char *));
        processString(&formatOptions, buff, strArg);

      } else if (currentCharacter == 'p') {
        formatOptions.numberBase = 16;
        formatOptions.upper = 2;
        integerArgument = (long)va_arg(variableArguments, void *);
        processDecimal(&formatOptions, buff, integerArgument);

      } else if (currentCharacter == 'd' || currentCharacter == 'i') {
        formatOptions.numberBase = 10;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'o') {
        formatOptions.numberBase = 8;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'b') {
        formatOptions.numberBase = 2;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'u') {
        formatOptions.numberBase = 10;
        formatOptions.u = 1;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'x') {
        formatOptions.numberBase = 16;
        formatOptions.u = 1;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'X') {
        formatOptions.numberBase = 16;
        formatOptions.upper = 1;
        formatOptions.u = 1;
        integerArgument = va_arg(variableArguments, long);
        processDecimal(&formatOptions, buff, integerArgument);
      } else if (currentCharacter == 'f') {
        formatOptions.numberBase = 10;
        formatOptions.f = 1;
        if (formatOptions.L) {
          doubleArgument = va_arg(variableArguments, long double);
        } else {
          doubleArgument = va_arg(variableArguments, double);
        }
        ProcessFloat(&formatOptions, buff, doubleArgument);
      } else if (currentCharacter == 'g' || currentCharacter == 'G') {
        formatOptions.g = 1;
        formatOptions.numberBase = 10;
        formatOptions.f = 1;
        if (formatOptions.L) {
          doubleArgument = va_arg(variableArguments, long double);
        } else {
          doubleArgument = va_arg(variableArguments, double);
        }
        long long inum = (long long)log10l(fabsl(doubleArgument));
        if (formatOptions.prec == -1 && inum > 0) {
          formatOptions.prec = 5 - inum;
        } else if (formatOptions.prec == -1) {
          formatOptions.prec = 6;
        }
        if (formatOptions.prec == 0 && inum > -6) {
          formatOptions.prec = find_nonzero(doubleArgument);
        } else if (inum <= -5 && doubleArgument != 0) {
          formatOptions.e = inum - 1;
          if (currentCharacter == 'G') {
            formatOptions.upper = 1;
          }
          doubleArgument = (doubleArgument / pow(10, formatOptions.e));
        }

        ProcessFloat(&formatOptions, buff, doubleArgument);
      } else if (currentCharacter == 'e' || currentCharacter == 'E') {
        if (currentCharacter == 'E') {
          formatOptions.upper = 1;
        }
        formatOptions.numberBase = 10;
        formatOptions.f = 1;
        if (formatOptions.L) {
          doubleArgument = va_arg(variableArguments, long double);
          formatOptions.e = (long long)log10l(fabsl(doubleArgument));
          if (formatOptions.e < 0) {
            formatOptions.e--;
          }
          long double mantissa = (doubleArgument / powl(10, formatOptions.e));
          doubleArgument = mantissa;
        } else {
          doubleArgument = va_arg(variableArguments, double);
          formatOptions.e = (long long)log10(fabsl(doubleArgument));
          if (formatOptions.e > -1e10 && formatOptions.e < 0) {
            formatOptions.e--;
          }
          double mantissa = (doubleArgument / pow(10, formatOptions.e));
          doubleArgument = mantissa;
        }
        ProcessFloat(&formatOptions, buff, doubleArgument);
      }
      currentOption = noOption;
      resetOption(&formatOptions);
    }
    stringIterator++;
  }
  s21_strcpy(outputString, buff);

  int answ = (int)s21_strlen(buff);
  free(buff);
  free(strArg);
  va_end(variableArguments);
  return answ;
}

char *itoa(int numberValue, char *convertedString, int numberBase,
           struct option *formatOptions) { //функция преобразует число в строку с указанной системой счисления
  if (numberBase < 2 || numberBase > 36) {//проверка сс 2(двоичная)36(16)
    *convertedString = '\0'; //если не входит в диапозон делает строку пустой
    return convertedString;
  }

  char *stringPointer = convertedString, //указатель на начало строки
       *reverseStringPointer = convertedString, tempChar;
  long long tempValue; // переменная для хранения значения числа в процессе преобр

  do {
    tempValue = numberValue; //сохраняем текущее значения числа
    numberValue /= numberBase; //деление числа на указанное основание
    int index = 35 + (tempValue - numberValue * numberBase); //вычиляем индекс соотвествующего символа из строк
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; //записывает символ в строку и увеличивает указатель

    if (formatOptions->f == 0) { //если нет спец f
      formatOptions->prec--; //уменьшаем точность
    }
  } while (numberValue); //пока число не равно 0

  if (formatOptions->prec > -1 && formatOptions->f == 0) { //если точность больше -1 и нет спец f
    while (formatOptions->prec) { 
      *stringPointer++ = '0'; //то добавляются нули в строку до указанной точности
      formatOptions->prec--;
    }
  }
//определение знака числа
  if (tempValue < 0) { //если число меньше 0
    *stringPointer++ = '-'; //то давбляется символ минуса
  } else if (tempValue >= 0 && formatOptions->sign == 1) { //если больше то плюс
    *stringPointer++ = '+';
  } else if (formatOptions->space) { //если флаг пробел то пробел
    *stringPointer++ = ' ';
  }

  *stringPointer-- = '\0'; //добавляем символ завершения строки
  while (reverseStringPointer < stringPointer) { //пока указатель начала строки меньше конца строки
    tempChar = *stringPointer; // сохраняем символ  конца строки
    *stringPointer-- = *reverseStringPointer; ///в начало строки записываем символ с конца строки
    *reverseStringPointer++ = tempChar; //в конце строки записываем сохраненный символ
  }
  return convertedString; ////возвращ указатель на строку, содерж преобр число
}
//преобр. целочисленного занч тип лонг лонг в строку
char *litoa(long long numberValue, char *convertedString, int numberBase,
            struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) {
    *convertedString = '\0'; //если не входит в диапозон делает строку пустой
    return convertedString;
  }

  char *stringPointer = convertedString, //указатель на начало строки 
       *reverseStringPointer = convertedString, tempChar;
  long long tempValue; // переменная для хранения числа в процессе преобр

  do {
    tempValue = numberValue; // сохраняем текущее значение числа
    numberValue /= numberBase; //делим на основание
    int index = 35 + (tempValue - numberValue * numberBase);//вычиляем индекс соотвествующего символа из строк
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; //записывает символ в строку и увеличивает указатель

    if (formatOptions->f == 0) { // если нет спецификатор ф
      formatOptions->prec--; // увеличиваем точность
    }
  } while (numberValue);

  if (formatOptions->prec > -1 && // если точность больше -1 и есть спец ф
      (formatOptions->f == 0 || formatOptions->zeroP == 1)) { 
    while (formatOptions->prec) {
      *stringPointer++ = '0'; //то добавляются нули в строку до достижения указанной точности
      formatOptions->prec--;
    }
  }
//определение знака числа
  if (tempValue < 0) {  //меньше нуля
    *stringPointer++ = '-'; //значит отрицательное
  } else if (tempValue >= 0 && formatOptions->sign == 1) { //если больше нуля и есть флаг знак
    *stringPointer++ = '+'; // то положительное
  } else if (formatOptions->space) { //если есть флаг пробел
    *stringPointer++ = ' '; // то добавляется пробел
  }

  *stringPointer-- = '\0'; // установка конца строки
  while (reverseStringPointer < stringPointer) { //происх обмен символов в строке для корректн порядка
    tempChar = *stringPointer;
    *stringPointer-- = *reverseStringPointer;
    *reverseStringPointer++ = tempChar;
  }
  return convertedString; //возвращ указатель на строку, содерж преобр число
}
//для преобр целочисленного значения тип шорт
char *hitoa(short numberValue, char *convertedString, int numberBase,
            struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) {//функция преобразует число в строку с указанной системой счисления
    *convertedString = '\0'; //проверка сс 2(двоичная)36(16)
    return convertedString; //возвращ указатель на строку, содерж преобр число
  }

  char *stringPointer = convertedString, //указатель на строку
       *reverseStringPointer = convertedString, tempChar; 
  long long tempValue;// переменная для хранения значения числа в процессе преобр

  do {
    tempValue = numberValue; //сохраняем текущее значение числа
    numberValue /= numberBase; // делим на основание
    int index = 35 + (tempValue - numberValue * numberBase); //вычисляем индекс символа
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; ////записывает символ в строку и увеличивает указатель

    formatOptions->prec--;
  } while (numberValue); //пока число не равно 0

  if (formatOptions->prec > -1) { //если точность больше -1
    while (formatOptions->prec) { //пока точность больше 0
      *stringPointer++ = '0'; //записываем 0 в строку
      formatOptions->prec--;
    }
  }

  if (tempValue < 0) { //если число отрицательное
    *stringPointer++ = '-'; //знак минус
  } else if (tempValue >= 0 && formatOptions->sign == 1) { //если число положительное и флаг для положительных чисел есть
    *stringPointer++ = '+'; //то плюс
  } else if (formatOptions->space) { // если пробел
    *stringPointer++ = ' '; // тоставим пробелы
  }

  *stringPointer-- = '\0'; //записываем в конец строки символ конца строки
  while (reverseStringPointer < stringPointer) { //пока указатель начала строки меньше конца строки
    tempChar = *stringPointer; 
    *stringPointer-- = *reverseStringPointer;//меняем местами символы
    *reverseStringPointer++ = tempChar
  }
  return convertedString; //возвращ указатель на строку, содерж преобр число
}

char *uitoa(unsigned int numberValue, char *convertedString, int numberBase,
            struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) { //функция преобразует число в строку с указанной системой счисления
    *convertedString = '\0'; //записываем в строку символ конца строки
    return convertedString; //возвращ указатель на строку
  }

  char *stringPointer = convertedString, //указатель на начало строки
       *reverseStringPointer = convertedString, tempChar; //
  long long tempValue; //переменная для хранения числа в процессе преобр

  do {
    tempValue = numberValue; ////сохраняем текущее значение числа
    numberValue /= numberBase; //делим на основание
    int index = 35 + (tempValue - numberValue * numberBase);
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; ////записывает символ в строку и увеличивает указатель

    formatOptions->prec--;
  } while (numberValue); //пока число не равно нулю

  if (formatOptions->prec > -1) { //если точность больше -1
    while (formatOptions->prec) { //пока точность больше нуля
      *stringPointer++ = '0'; //записываем в строку 0
      formatOptions->prec--;
    }
  }

  *stringPointer-- = '\0'; //записываем в строку символ конца строки
  while (reverseStringPointer < stringPointer) { //пока указатель на начало строки меньше указателя на конец строки
    tempChar = *stringPointer; //сохраняем символ
    *stringPointer-- = *reverseStringPointer; //в начало строки записываем символ с конца строки
    *reverseStringPointer++ = tempChar;//в конец строки записываем сохраненный символ
  }
  return convertedString; //возвращаем строку
}

char *ulitoa(unsigned long long numberValue, char *convertedString,
             int numberBase, struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) { //функция преобразует число в строку с указанной системой счисления
    *convertedString = '\0'; //записываем в строку символ конца строки
    return convertedString; //возвращем указатель на строку
  }

  char *stringPointer = convertedString, //указатель на начало строки
       *reverseStringPointer = convertedString, tempChar; //указатель на конец строки
  long long tempValue; //переменная для хранения значения временного в процессе преобр

  do {
    tempValue = numberValue; //сохраняем текущее значение числа
    numberValue /= numberBase; //делим на основание системы счисления
    int index = 35 + (tempValue - numberValue * numberBase); //вычисляем индекс символа
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; //записываем символ в строку и увеличиваем основание

    formatOptions->prec--;
  } while (numberValue); //пока число не равно 0

  if (formatOptions->prec > -1) { //если точность больше -1
    while (formatOptions->prec) { //пока точность больше 0
      *stringPointer++ = '0'; //записываем 0 в строку
      formatOptions->prec--;
    }
  }

  *stringPointer-- = '\0'; //записываем в конец строки символ конца строки
  while (reverseStringPointer < stringPointer) { //пока указатель на начало строки меньше указателя на конец строки
    tempChar = *stringPointer; //сохраняем текущий символ
    *stringPointer-- = *reverseStringPointer; //в начало строки записываем символ с конца строки
    *reverseStringPointer++ = tempChar; // в конец строки записываем сохраненный символ
  }
  return convertedString; // возвращем указатель
}

char *uhitoa(unsigned short numberValue, char *convertedString, int numberBase,
             struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) { //функция преобразует число в строку с указанной системой счисления
    *convertedString = '\0'; // //записываем в строку символ конца строки
    return convertedString; //возвращем указатель на строку
  }

  char *stringPointer = convertedString, //указатель на начало строки
       *reverseStringPointer = convertedString, tempChar; //указатель на конец строки
  long long tempValue; //пременная для хранения чисел временных в процессе преобр

  do {
    tempValue = numberValue; // сохраняем текущее число в переменную
    numberValue /= numberBase; // делим на основание
    int index = 35 + (tempValue - numberValue * numberBase); //вычисляем индекк
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; // записываем в строку символ и увеличиваем основание

    formatOptions->prec--;
  } while (numberValue);  // пока число не равно 0

  if (formatOptions->prec > -1) { //если точно больше минус 1
    while (formatOptions->prec) { 
      *stringPointer++ = '0'; //добавляем нули в строку до достижения указанной точности
      formatOptions->prec--;
    }
  }

  *stringPointer-- = '\0'; //записываем в конец строки символ конца строки
  while (reverseStringPointer < stringPointer) { ////пока указатель на начало строки меньше указателя на конец строки
    tempChar = *stringPointer; // сохраняем текущий символ
    *stringPointer-- = *reverseStringPointer;//в начало строки записываем символ с конца строки
    *reverseStringPointer++ = tempChar; // в конец строки записываем сохраненный символ
  }
  return convertedString;//возвращем указатель на строку
}
//функция предназначена для преобразования чисел типа лонг дабл, включая округление последней цифры 
void ftoa(long double n, char *res, int afterpoint,
          struct option *formatOptions) {
  long long ipart = (long long)n; //ipart присваюваевается целая часть числа н приведенная к типу лонг лонг
  char currNum;
  long double fpart = n - (long double)ipart; //вычисление дробной части числа н
  char ibuff[BUFF_SIZE]; //массив символов для хранения целой части числа в виде тсроки

  litoa(ipart, ibuff, 10, formatOptions); //целая часть чтсла преобр в строку с помощью функции и сохр в массив баффер
  s21_strcpy(res, ibuff); // скопировання строка с целой частью числа добавляется в итогую строку рес

  if (afterpoint != 0) { //проверка наличия дробной части
    s21_strcat(res, ".");//если автерпоинт не равно 0 то добавляется точка в итоговую строку
  }
  //обработка дробной части
  if (fpart < 0) { //если дробная часть отрицательна
    fpart = -1 * fpart; // она преобр в положительное значение
  }

  while (afterpoint > 0) { //в цикле обрабатывается каждая цифра после запятой//пока количество знаков после запятой больше 0
    afterpoint--;
    if (afterpoint == 0) { // если текущая цифра последняя то 
    //Если разница между умножением  fpart  на 10 и его округлением до целого числа умноженным на 10 больше или равна 5,
    // то цифра округляется вверх. 
      if (((fpart * 10) - (long long)((fpart + 1e-9) * 10)) * 10 >= 5) {
        currNum = '0' + (long long)((fpart + 1e-9) * 10) + 1; // в этом случае к curnum добавляется 1
      } else {
        currNum = '0' + (long long)((fpart + 1e-9) * 10);
      } // Если текущая цифра не округляется вверх, то просто умножаем дробную часть
      //  fpart  на 10 и преобразуем в символ. 
    } else {
      currNum = '0' + (long long)((fpart + 1e-9) * 10);
    }
//Добавление текущей цифры (как символа) в итоговую строку  res  с помощью функции  s21_strncat ,
// которая добавляет указанное количество символов к строке. 
    s21_strncat(res, &currNum, 1);
    //Обновление значения дробной части  fpart  для следующей итерации цикла: 
   //Умножение текущей дробной части на 10 для перехода к следующей цифре. 
   //Вычитание целой части (округленной до ближайшего целого) умноженной на 10 для получения оставшейся дробной части.
    fpart = (fpart * 10) - (long long)((fpart + 1e-9) * 10);
  }
}
// функцию  elitoa , которая предназначена для преобразования целочисленного значения типа  long long
char *elitoa(long long numberValue, char *convertedString, int numberBase,
             struct option *formatOptions) {
  if (numberBase < 2 || numberBase > 36) { // cc меньше 2 и больше 36
    *convertedString = '\0';////записываем в строку символ конца строки
    return convertedString; //возвращаем указатель на строку
  }

  char *stringPointer = convertedString, //указатель на начало строки
       *reverseStringPointer = convertedString, tempChar;
  long long tempValue;//перемення для хранения временного значения числа в процессе преобр

  do {
    tempValue = numberValue;// сохраняем текущее число в переменную
    numberValue /= numberBase;//деление на основание
    int index = 35 + (tempValue - numberValue * numberBase);//вычисляем индекс
    *stringPointer++ =
        "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxy"
        "z"[index]; //записываем символ в строку и увеличиваем указатель на 1

    if (formatOptions->f == 0) { //если фиксировання точность = 0
      formatOptions->prec--; //уменьшаем точность
    }
  } while (numberValue); ////пока число не равно 0

  if (formatOptions->prec > -1 &&
      (formatOptions->f == 0 || formatOptions->zeroP == 1)) { //если точность больше -1 и фиксировання точность = 0 или 0 перед числом
    while (formatOptions->prec - 4 - (8)) {
      *stringPointer++ = '0'; //то добавляются нули в строчку до достижения указанной точности
      formatOptions->prec--;
    }
  }

  if (tempValue < 0) { //если число отрицательное
    *stringPointer++ = '-'; //то ставится минус
  } else if (tempValue >= 0 && formatOptions->sign == 1) { //если чило положительное 
    *stringPointer++ = '+';//то плюс
  } else if (formatOptions->space) { //если пробел
    *stringPointer++ = ' '; // то пробел
  }

  *stringPointer-- = '\0'; //записываем в конец строки символ конца строки
  while (reverseStringPointer < stringPointer) { ////пока указатель начала строки меньше конца строки
    tempChar = *stringPointer;  // Происходит обмен символов в строке для корректного порядка. 
    *stringPointer-- = *reverseStringPointer;
    *reverseStringPointer++ = tempChar;
  }
  return convertedString; //возвращает указатель на строку
}
//функцию  eftoal , которая предназначена для преобразования числа типа  long double  в строку с учетом указанного количества знаков после запятой и параметров форматирования
void eftoal(long double n, char *res, int afterpoint,
            struct option *formatOptions) {
  long long ipart = (long long)n; //сохраняет целую часть числа  n  в переменной  ipart
  char currNum;
  long double fpart = n - (long double)ipart; //вычисляет дробную часть числа  n
  //обработка особых случаев
  //Если дробная часть увеличивает целую часть на 1 при округлении и точность равна 0, то целая часть увеличивается на 1. 
  if (fpart * 10 >= 5 && formatOptions->prec == 0) {
    ipart++;
  }
  //Если число  n  не равно самому себе//целая часть устанавливается в 0.
  if (n != n) {
    ipart = 0;
  }
  //массив символов  ibuff  для хранения целой части числа в виде строки. 
  char ibuff[BUFF_SIZE];
  //Целая часть числа преобразуется в строку с помощью функции  elitoa
  elitoa(ipart, ibuff, 10, formatOptions);
  //Скопированная строка с целой частью числа добавляется в итоговую строку  res
  s21_strcpy(res, ibuff);
  //Если  afterpoint  не равно 0, добавляется точка в итоговую строку. 
  if (afterpoint != 0) {
    s21_strcat(res, ".");
  }
  //обработка дробной части
  if (fpart < 0) {
    // Если дробная часть  fpart  отрицательна, она преобразуется в положительное значение. 
    fpart = -1 * fpart;
  }
//В цикле обрабатывается каждая цифра после запятой
  while (afterpoint > 0) {
    afterpoint--;
    if (afterpoint == 0) {// если текущая цифра последняя то 
    //Если разница между умножением  fpart  на 10 и его округлением до целого числа умноженным на 10 больше или равна 5,
    // то цифра округляется вверх. 
      if (((fpart * 10) - (long long)((fpart)*10)) * 10 >= 5 &&
          ((long long)((fpart)*10)) != 9) {
        currNum = '0' + (long long)((fpart)*10) + 1;// в этом случае к curnum добавляется 1
      } else {
        currNum = '0' + (long long)((fpart)*10);
      }// Если текущая цифра не округляется вверх, то просто умножаем дробную часть
      //  fpart  на 10 и преобразуем в символ. 
    } else {
      currNum = '0' + (long long)((fpart)*10);
    }
//Добавление текущей цифры (как символа) в итоговую строку  res  с помощью функции  s21_strncat ,
    s21_strncat(res, &currNum, 1);
    //Обновление значения дробной части  fpart  для следующей итерации цикла: 
   //Умножение текущей дробной части на 10 для перехода к следующей цифре. 
   //Вычитание целой части (округленной до ближайшего целого) умноженной на 10 для получения оставшейся дробной части.
    fpart = (fpart * 10) - (long long)((fpart)*10);
  }
}
//функция предназначеня для преобразования числа типа дабл в строку  с учетом указанного количества знаков после запятой и параметров форматирования: 
void eftoa(double n, char *res, int afterpoint, struct option *formatOptions) {
  long long ipart = (long long)n; //сохраняет целую часть числа н
  char currNum;
  double fpart = n - (double)ipart; //вычисляем дробную часть
  if (fpart * 10 >= 5 && formatOptions->prec == 0) {
    //Если дробная часть увеличивает целую часть на 1 при округлении и точность равна 0
    ipart++;
    //то целая часть увеличивается на 1
  }
  if (n != n) {
    //Если число  n  не равно самому себе 
    ipart = 0;
    //целая часть устанавливается в 0.
  }
  char ibuff[BUFF_SIZE]; //Объявляется массив символов  ibuff  для хранения целой части числа в виде строки
  elitoa(ipart, ibuff, 10, formatOptions);//Целая часть числа преобразуется в строку с помощью функции  elitoa
  s21_strcpy(res, ibuff);//Скопированная строка с целой частью числа добавляется в итоговую строку  res
  //добавление точки после целой части
  if (afterpoint != 0) { //Если  afterpoint  не равно 0, добавляется точка в итоговую строку. 
    s21_strcat(res, ".");
  }
  //Если дробная часть  fpart  отрицательна, она преобразуется в положительное значение. 
  if (fpart < 0) {
    fpart = -1 * fpart;
  }

  while (afterpoint > 0) { //В цикле обрабатывается каждая цифра после запятой
    afterpoint--;
    if (afterpoint == 0) {// если текущая цифра последняя то 
    //Если разница между умножением  fpart  на 10 и его округлением до целого числа умноженным на 10 больше или равна 5,
    // то цифра округляется вверх.
      if (((fpart * 10) - (long long)((fpart)*10)) * 10 >= 5 &&
          ((long long)((fpart)*10)) != 9) {
        currNum = '0' + (long long)((fpart)*10) + 1;
      } else { //// в этом случае к curnum добавляется 1
        currNum = '0' + (long long)((fpart)*10);
      }
    } else { // Если текущая цифра не округляется вверх, то просто умножаем дробную часть
      //  fpart  на 10 и преобразуем в символ. 
      currNum = '0' + (long long)((fpart)*10);
    }
//Добавление текущей цифры (как символа) в итоговую строку  res  с помощью функции  s21_strncat ,
    s21_strncat(res, &currNum, 1);
//Обновление значения дробной части  fpart  для следующей итерации цикла: 
//Умножение текущей дробной части на 10 для перехода к следующей цифре. 
//Вычитание целой части (округленной до ближайшего целого) умноженной на 10 для получения оставшейся дробной части.
    fpart = (fpart * 10) - (long long)((fpart)*10);
  }
}
//функция обрабатывает строку в соотвествии с заданымми параметрами
void processString(struct option *formatOptions, char *buff,
                   char *outputString) {
  int stringIterator = 0; //переменная для итерации по символам в строке
  char currentCharacter = *outputString;//текущий символ исходной строки
  int formatW; //переменная для хранения ширины форматирования

  if (formatOptions->prec == -1 || //если точность равна -1 или больше длины исходной строки
      formatOptions->prec > (int)s21_strlen(outputString)) {
    formatW = (int)s21_strlen(outputString); // то ширина текущей строки равна длине исходной строки
  } else {
    formatW = formatOptions->prec; //иначе равна точности
  }
  if (formatOptions->width != -1) { //если ширина не равна -1 
    if (formatOptions->width <= formatW) { //если ширина меньше или равна ширине форматирования
    //то ничего не делается
    } else if (formatOptions->ljust == 0) { // иначе если ширина больше ширины форм и нет выравнивания по левому кра/
      for (int stringIterator = 0;
           stringIterator < formatOptions->width - formatW; stringIterator++) {
        s21_strncat(buff, " ", 1); // добавляются пробелы до достижения заданной ширины
      }
    }
  }
//обработка и копирование символов из исходной строки в буффер
  while (*(outputString + stringIterator) != '\0' &&
         (formatOptions->prec <= -1 || formatOptions->prec > 0)) {
    currentCharacter = *(outputString + stringIterator);
    s21_strncat(buff, &currentCharacter, 1);
    stringIterator++;
    formatOptions->prec--;
    //Пока не достигнут конец строки и пока количество символов для вывода не исчерпано, 
    //символы копируются из исходной строки в буфер. 
  }
  //Обработка выравнивания по левому краю: 
   //Если активировано выравнивание по левому краю и ширина вывода больше  formatW ,
  //добавляются пробелы до достижения заданной ширины. 
  if (formatOptions->ljust == 1 && formatOptions->width > formatW) {
    for (int stringIterator = 0;
         stringIterator < formatOptions->width - formatW; stringIterator++) {
      s21_strncat(buff, " ", 1);
    }
  }
}
//функция обрабатывает целочисленное число и форматирует его в соотв с параметрами
void processDecimal(struct option *formatOptions, char *buff, long long num) {
  int stringIterator = 0; ////переменная для итерации по символам в строке
  char *outputString = malloc(BUFF_SIZE);//выделение памяти для временной строки для хранения преобразованного числа. 
  s21_strcpy(outputString, ""); //обнуляю строку
  char currentCharacter;//переменная для хранения текущего символа
  int shift = 0; //переменная для учета дополнительного сдвига при форматировании. 

  if (num == 0 && formatOptions->prec == 0) {//если число = 0 и точность, то ничего не делается
  } else if (formatOptions->l) { //если есть флаг длина
    if (formatOptions->u) { //если есть флаг ю(беззнаковое десятичное целое число)
      ulitoa(num, outputString, formatOptions->numberBase, formatOptions);
      //вызывается функция  ulitoa  для преобразования числа в строку. 
    } else {
      litoa(num, outputString, formatOptions->numberBase, formatOptions);
      //вызывается функция  litoa  для преобразования числа в строку. 
    }

  } else if (formatOptions->h) { //если есть флаг длина как короткое int 
    if (formatOptions->u) { // и флаг ю(беззнаковое десятичное целое число)
      uhitoa(num, outputString, formatOptions->numberBase, formatOptions);
      //вызывается функция uhitoa
    } else {
      hitoa(num, outputString, formatOptions->numberBase, formatOptions);
      //вызывается функция hitoa
    }
  } else { //если нет флага длины для длинного инта и длины для короткого инта
    if (formatOptions->u) { //и флаг ю беззнаковое десятичное число
      uitoa(num, outputString, formatOptions->numberBase, formatOptions);
      //то вызывается функция uitoa
    } else {
      itoa(num, outputString, formatOptions->numberBase, formatOptions);
      // если u нет то вызывается функция itoa
    }
  }
//расчет сдвига для 16 сс и 8 сс
//если число не равно 0 и установлен флаг хэша или аппер ==2 (влияет на обработку символов)
//upper == 0 символы выводятся в нижнем регистре, 1 в верхнем, 2 особый режим влияет на обработку символов при выводе
  if (num != 0 && (formatOptions->hash != 0 || formatOptions->upper == 2)) {
    //если сс 8 то сдвиг 1
    if (formatOptions->numberBase == 8) {
      shift = 1;
      //если сс 16 и символы выводятся в верхнем регистре то сдвиг 2
    } else if (formatOptions->numberBase == 16 && formatOptions->upper == 1) {
      shift = 2;
    } else if (formatOptions->numberBase == 16 && formatOptions->upper == 2) {
      shift = 4;
    } else if (formatOptions->numberBase == 16) {
      shift = 2;
    }
  } else if (num == 0 && formatOptions->upper == 2) {
    shift = 2;
  }

  if (formatOptions->upper == 1) { //если флаг равен 1 то символы должны преобр в верхний регистр
    int stringIterator = 0; //счетчик
    while (*(outputString + stringIterator)) { //цикл до конца строки
      *(outputString + stringIterator) =
          toupper(*(outputString + stringIterator));
      stringIterator++;
    } //внутри цикла каждый символ преобр в символ верхнего регистра пока не дойдет до конца строки
  }
//обработка ширины вывода
  if (formatOptions->width != -1) { //если есть ширина вывода
  //и она больше длины строки плюс сдвиг
    if (formatOptions->width <= (int)s21_strlen(outputString) + shift) {
    } else if (formatOptions->ljust == 0) {
      for (int stringIterator = 0;
           stringIterator <
           formatOptions->width - (int)s21_strlen(outputString) - shift;
           stringIterator++) {
        s21_strncat(buff, " ", 1); // то добавляются пробелы для выравнивания
      }
    }
  }
//добавление префикса в зависимости о сс
//если число не равно 0 и есть флаг хэш или аппер 2
  if (num != 0 && (formatOptions->hash != 0 || formatOptions->upper == 2)) {
    //то это 8сс и добавляется 0
    if (formatOptions->numberBase == 8) {
      s21_strncat(buff, "0", 1);
      //если 16сс и символы выводятся в верхнем регистре то добавляется 0x
    } else if (formatOptions->numberBase == 16 && formatOptions->upper == 1) {
      s21_strncat(buff, "0X", 2);
    } else if (formatOptions->numberBase == 16 && formatOptions->upper == 2) {
      s21_strncat(buff, "0x10", 4);
    } else if (formatOptions->numberBase == 16) {
      s21_strncat(buff, "0x", 2);
    }
  } else if (num == 0 && formatOptions->upper == 2) {
    s21_strncat(buff, "0x", 2);
  }
//копирование символов из временной строки в буфер
  while (*(outputString + stringIterator) != '\0') {
    currentCharacter = *(outputString + stringIterator);
    s21_strncat(buff, &currentCharacter, 1);
    stringIterator++;
  } // обработка выравнивания по левому краю
  //Если установлено выравнивание по левому краю и ширина вывода больше длины строки плюс сдвиг,
  // добавляются пробелы для выравнивания
  if (formatOptions->ljust == 1 &&
      formatOptions->width > (int)s21_strlen(outputString) + shift) {
    for (int stringIterator = 0;
         stringIterator <
         formatOptions->width - (int)s21_strlen(outputString) - shift;
         stringIterator++) {
      s21_strncat(buff, " ", 1);
    }
  }
  free(outputString); // очищаем память
}
//функция для удаления нулей в конце числа строки
void remove_trailing_zeroes(char *buff) {
  int len = s21_strlen(buff); //длина строк
  char *dot = s21_strchr(buff, '.'); //ищет точку в строке
  if (dot) { // если точка есть
  //цикл с конца строки до начала
    for (int stringIterator = len - 1; buff[stringIterator] != s21_dot;
         stringIterator--) {
      if (buff[stringIterator] == '0') //если текущий символ = 0, то он
        buff[stringIterator] = '\0'; //заменяется на символ конца строки
      else //если текущий символ не равен 0
        break; // то цикл прерывается
    }
    if (dot[1] == '\0') dot[0] = '\0'; //если после символа точки нет символа, то символ точки заменяется на окончание строки
  }
}
//функция обрабатывает числа с плавающей точкой
void ProcessFloat(struct option *formatOptions, char *buff, long double num) {
  int stringIterator = 0;//счетчик
  char *outputString = malloc(BUFF_SIZE); //выделение памяти для временной строки для хранения преобр
  char currentCharacter; //текущий символ для обработк
  int afterpoint = formatOptions->prec;//количество знаков после запятой

  if (formatOptions->zeroP == 1) { //если есть флаг 0
    afterpoint = 6; // то количество знаков после запятой устанавливается равным 6
  }

  if (formatOptions->e == -2281337) { //если нужно записать число в научной нотации
    if (formatOptions->prec != -1) {//если есть точность
      ftoa(num, outputString, afterpoint, formatOptions);
      //вызывается функция ftoa
    } else {
      ftoa(num, outputString, 6, formatOptions);
      //иначе ftoa c установленным количеством знаком после запятой
    }
  } else { //если не в научной нотации
    if (formatOptions->prec != -1) { //если есть точность
      if (formatOptions->L != -1) { //и длина для длинного дабла
        eftoal(num, outputString, afterpoint, formatOptions);
        //вызывается функция eftoal
      } else {
        eftoa(num, outputString, afterpoint, formatOptions);
        //иначе eftoa
      }
    } else { //если точности нет
      if (formatOptions->L != -1) { //и есть длинна для длинного дабл
        eftoal(num, outputString, 6, formatOptions);
        //вызывается  функция eftoal
      } else {// если нет длинны
        eftoa(num, outputString, 6, formatOptions);
      } // то вызывается функция eftoa
    }
  }
//обработка удаления нулен после десятичной точки
  if (formatOptions->g == 1) { //если флаг Десятичного числа с плавающей точкой или научной нотации (мантисса/экспонента)
    remove_trailing_zeroes(outputString);
  }
  //Этот участок кода отвечает за добавление экспоненциальной части к строке //представление числа меньшим количеством чисел
//если не нужно записывать число в научной нотации и нужно выводить в верхнем регистре
  if (formatOptions->e != -2281337 && formatOptions->upper == 1) {
    char exp[6]; //Объявление массива символов для хранения экспоненциальной части. 
    s21_sprintf(exp, "E%+02d", formatOptions->e); //Запись экспоненциальной части в массив е+двузначное число
    s21_strncat(outputString, exp, 5); //Добавление сформированной строки экспоненциальной части к итоговой строке  
  } else if (formatOptions->e != -2281337) { //тоже самое но с нижним регистром
    char exp[6];
    s21_sprintf(exp, "e%+02d", formatOptions->e);
    s21_strncat(outputString, exp, 5);
  }

//- Если установлена ширина вывода и она больше длины строки, добавляются пробелы для выравнивания. 
  if (formatOptions->width != -1) {
    if (formatOptions->width <= (int)s21_strlen(outputString)) {
    } else if (formatOptions->ljust == 0) {
      for (int stringIterator = 0;
           stringIterator <
           formatOptions->width - (int)s21_strlen(outputString);
           stringIterator++) {
        s21_strncat(buff, " ", 1);
      }
    }
  }
//Копирование символов из  outputString  в буфер  buff : 
// Копирование символов из временной строки  outputString  в буфер  buff . 
 
  while (*(outputString + stringIterator) != '\0') {
    currentCharacter = *(outputString + stringIterator);
    s21_strncat(buff, &currentCharacter, 1);
    stringIterator++;
  }
  //Обработка выравнивания по левому краю: 
  //Если установлено выравнивание по левому краю и ширина вывода больше длины строки 
  //добавляются пробелы для выравнивания. 
  if (formatOptions->ljust == 1 &&
      formatOptions->width > (int)s21_strlen(outputString)) {
    for (int stringIterator = 0;
         stringIterator < formatOptions->width - (int)s21_strlen(outputString);
         stringIterator++) {
      s21_strncat(buff, " ", 1);
    }
  }
  free(outputString); // освобождение памяти
}
// возвращает количество нулей, которые находятся перед первой ненулевой цифрой в числе.
int find_nonzero(double num) {
  int pow = 0;
  while (num < 1) {
    num = num * 10; // позволяет перемещать запятую в числе на одну позицию вправо
    // и считать количество нулей перед первой ненулевой цифрой
    pow++;
  }
//После выхода из цикла мы возвращаем значение переменной pow,
//которое и является количеством нулей перед первой ненулевой цифрой в числе.
  return pow;
}
