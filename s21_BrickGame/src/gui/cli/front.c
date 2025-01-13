#include "../../build/tetris.h"
void start_scr(int number_pic) {  // вывод начального экрана
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);
  FILE* file;
  char ch;
  if (number_pic == 1) {
    file = fopen("build/start.txt", "r");
  } else if (number_pic == 2) {
    file = fopen("build/end.txt", "r");
  }
  if (file == NULL) {
    printf("Error, file doesn't open");
  } else {
    while ((ch = fgetc(file)) != EOF) {
      if (ch == '*') {
        attron(COLOR_PAIR(1));
        printw(" ");
        attroff(COLOR_PAIR(1));
      } else if (ch == 'p') {
        attron(COLOR_PAIR(3));
        printw(" ");
        attroff(COLOR_PAIR(3));
      } else if (ch == '-') {
        attron(COLOR_PAIR(2));
        printw(" ");
        attroff(COLOR_PAIR(2));
      } else {
        printw("%c", ch);
      }
    }
    fclose(file);
  }
}
// вывод тетриса
void output(GameInfo_t game) {
  start_color();  // Инициализация цветовой схемы
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(3, COLOR_WHITE, COLOR_WHITE);

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 22; j++) {
      if (j < 10 && i < 20) {
        if (game.pause == 0) {          // если не пауза
          if (game.field[i][j] == 1) {  // и есть фигурка
            attron(COLOR_PAIR(2));
            printw("  ");
            attroff(COLOR_PAIR(2));
          } else if (game.field[i][j] == 0) {
            attron(COLOR_PAIR(3));
            printw("  ");
            attroff(COLOR_PAIR(3));
          }
        } else if (game.pause == 1) {
          if (i == 10 && j == 0) {
            printw("       PAUSE        ");
          } else if (i != 10) {
            attron(COLOR_PAIR(3));
            printw("  ");
            attroff(COLOR_PAIR(3));
          }
        }
      } else {
        attron(COLOR_PAIR(1));
        if (i == 0 && j == 15) {
          printw("NEXT");
          break;
        }
        // проверка выхода за границы следующей фигурки
        if (i == 2 && j == 14) {
          if (game.next[1][4] != 1 && game.next[1][4] != 4) {
            printw(" ");
          }
          for (int k = 0; k < 4; k++) {
            if (game.next[0][k] == 1) {
              attron(COLOR_PAIR(2));
              printw("  ");
              attroff(COLOR_PAIR(2));
            } else {
              attron(COLOR_PAIR(1));
              printw("  ");
              attroff(COLOR_PAIR(1));
            }
          }
        }
        if (i == 3 && j == 14) {
          if (game.next[1][4] != 1 && game.next[1][4] != 4) {
            printw(" ");
          }
          for (int k = 0; k < 4; k++) {
            if (game.next[1][k] == 1) {
              attron(COLOR_PAIR(2));
              printw("  ");
            } else {
              attron(COLOR_PAIR(1));
              printw("  ");
              attroff(COLOR_PAIR(1));
            }
          }
        }
        if (i == 5 && j == 15) {
          printw("LEVEL");
          break;
        }
        if (i == 6 && j == 16) {
          printw("%d", game.level);
          break;
        }
        if (i == 9 && j == 15) {
          printw("SPEED");
          break;
        }
        if (i == 10 && j == 16) {
          printw("%d", game.speed);
          break;
        }
        if (i == 13 && j == 15) {
          printw("SCORE");
          break;
        }
        if (i == 14 && j == 16) {
          printw("%d", game.score);
          break;
        }
        if (i == 17 && j == 14) {
          printw("HIGH SCORE");
          break;
        }
        if (i == 18 && j == 16) {
          printw("%d", game.high_score);
          break;
        }

        else {
          printw("  ");
        }
        attroff(COLOR_PAIR(1));
      }
    }
    printw("\n");
  }
}
