#include "tetris.h"

int main() {
  GameInfo_t tetris;  // сделать free
  position figure;
  coordinate_f coordinate;
  int end = 0;
  int speed = 90000;
  int endgame = 0;
  starting_p(&tetris);  // постановка в стартовое положение
  initscr();            // Инициализация ncurses
  keypad(stdscr, TRUE);  // Включение обработки специальных клавиш
  start_scr(1);  // заставка
  getch();
  clear();
  nodelay(stdscr, TRUE);  // включаем необязательный ввод
  srand(time(NULL));
  figure.figure = 1 + rand() % (7);  // узнали 1 фигурку
  while (end == 0) {
    int a = 0;
    int next = spawn(&tetris);  // узнали некст фигурку
    put_figure(&figure);  // положить главну точку фигуры
    coordinate_tetromino(
        figure.figure,
        &coordinate);  // пишем координаты по фигуре в структуру
    while (a == 0) {
      output(tetris);
      endgame = input_usr(&tetris, &figure, &coordinate, &speed);
      if (endgame == 1) {
        break;
        break;
      }
      a = move_figure(&tetris, &figure, &coordinate, 258);
      clear();
    }
    score_lvl_speed(delete_line(&tetris), &tetris, &speed);
    end = end_game(&tetris);
    if (endgame == 1) {
      break;
    }
    figure.figure = next;
  }
  nodelay(stdscr, FALSE);  // стопаем инкерсес
  clear();
  start_scr(2);  // заставка
  getch();
  clear();
  endwin();  // Завершение работы с ncurses
  free_data(&tetris);
  return 0;
}
// gcc ${CFLAGS} tests/*.c brick_game/tetris/back.c  gui/cli/front.c -o s21_test
// -lncurses $(LFLAGS) ${GCOV_FLAGS}
//./s21_test
// lcov -t "gcov_test" -o gcov_test.info -c -d .
// genhtml -o report gcov_test.info
// open report/index.html
// rm -rf *.gcda *.gcno *.info