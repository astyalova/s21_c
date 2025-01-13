#include "../../build/tetris.h"

void spin(int* x, int* y) {  // для поворота фигуры функция
  int a = (*x);
  if ((*x) == 0 || (*y) == 0) {
    if ((*y) != 0) {
      (*y) = (*y) * -1;
    }
    (*x) = (*y);
    (*y) = a;
  } else if ((*y) == 1 && (*x) == 1) {
    (*x) = (*x) * -1;
  } else if ((*y) == 1 && (*x) == -1) {
    (*y) = (*y) * -1;
  } else if ((*y) == -1 && (*x) == -1) {
    (*x) = (*x) * -1;
  } else if ((*y) == -1 && (*x) == 1) {
    (*y) = (*y) * -1;
  }
}

// координаты фигуры в зависимости от того, какая она
void coordinate_tetromino(int number_f, coordinate_f* p) {
  if (number_f == 1) {
    p->X1 = -1, p->Y1 = 0, p->X2 = 1, p->Y2 = 0, p->X3 = 2, p->Y3 = 0;
  } else if (number_f == 2) {
    p->X1 = 1, p->Y1 = 0, p->X2 = -1, p->Y2 = 0, p->X3 = -1, p->Y3 = -1;
  } else if (number_f == 3) {
    p->X1 = -1, p->Y1 = 0, p->X2 = 1, p->Y2 = 0, p->X3 = 1, p->Y3 = -1;
  } else if (number_f == 4) {
    p->X1 = 0, p->Y1 = -1, p->X2 = 1, p->Y2 = 0, p->X3 = 1, p->Y3 = -1;
  } else if (number_f == 5) {
    p->X1 = -1, p->Y1 = 0, p->X2 = 0, p->Y2 = -1, p->X3 = 1, p->Y3 = -1;
  } else if (number_f == 6) {
    p->X1 = -1, p->Y1 = 0, p->X2 = 0, p->Y2 = -1, p->X3 = 1, p->Y3 = 0;
  } else if (number_f == 7) {
    p->X1 = -1, p->Y1 = -1, p->X2 = 0, p->Y2 = -1, p->X3 = 1, p->Y3 = 0;
  }
}

// стартовая позиция
void starting_p(GameInfo_t* game) {
  game->pause = 0;

  game->field = calloc(20, sizeof(int*));
  for (int i = 0; i < 20; ++i) {
    game->field[i] = calloc(10, sizeof(int));
  }

  game->next = calloc(2, sizeof(int*));
  for (int i = 0; i < 2; ++i) {
    game->next[i] = calloc(5, sizeof(int));
  }

  game->speed = 100;

  game->level = 1;
  game->speed = 1;
  game->score = 0;
  game->high_score = 0;

  FILE* file = fopen("build/higt_score.txt", "r");

  char buffer[15] = {};
  fgets(buffer, sizeof(buffer), file);
  int a = 1;
  for (int i = 15; i > -1; i--) {
    if (buffer[i] < 58 && buffer[i] > 47) {
      game->high_score = game->high_score + (buffer[i] - 48) * a;
      a = a * 10;
    }
  }
  fclose(file);
}

// если по счету больше, то надо перезаписать
int end_game(GameInfo_t* game) {
  int error = 0;
  for (int i = 0; i < 10; i++) {
    if (game->field[0][i] == 1) {
      FILE* file =
          fopen("build/higt_score.txt", "w");  // Записываем данные в файл
      fprintf(file, "%d", game->score);
      fclose(file);  // Закрываем файл
      error = 1;
    }
  }
  return error;
}

// спавн новой фигур
int spawn(GameInfo_t* tetris) {
  int random_number = 1 + rand() % (7);
  coordinate_f for_next;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      tetris->next[i][j] = 0;
    }
  }
  coordinate_tetromino(random_number, &for_next);

  tetris->next[1][1] = 1;
  tetris->next[1 + for_next.Y1][1 + for_next.X1] = 1;
  tetris->next[1 + for_next.Y2][1 + for_next.X2] = 1;
  tetris->next[1 + for_next.Y3][1 + for_next.X3] = 1;
  tetris->next[1][4] = random_number;

  return random_number;
}

void put_figure(position* figure) {
  figure->Y = -1;
  figure->X = 4;
}
// смена координат фигуры при повороте
void spin_f(position* figure, coordinate_f* c) {
  if (figure->figure != 4) {
    spin(&c->X1, &c->Y1);
    spin(&c->X2, &c->Y2);
    spin(&c->X3, &c->Y3);
  }
}

// проверка координат, если все хорошо, пишем 1
void check_and_write_1(GameInfo_t* game, int y, int x) {
  if (y > -1 && x > -1) {
    game->field[y][x] = 1;
  }
}

// проверка координат, если все хорошо, пишем 0
void check_and_write_0(GameInfo_t* game, int y, int x) {
  if (y > -1 && x > -1) {
    game->field[y][x] = 0;
  }
}

int delete_line(GameInfo_t* game) {
  int l = 0;
  int amt = 0;
  int forI = -1;
  for (int i = 19; i > forI; i--) {
    for (int j = 0; j < 10; j++) {
      if (game->field[i][j] == 1) {
        l++;
      }
    }
    if (l == 10) {
      amt++;
    } else if (l < 10 &&
               i != 19) {  // если  строка меньше ее надо сдвинуть  && i != 19
      for (int j = 0; j < 10; j++) {
        game->field[i + amt][j] = game->field[i][j];
      }
    }
    l = 0;
  }
  return amt;
}

int check_coord(GameInfo_t* game, int y, int x) {
  int err = 0;
  if (y == 20 || (y > -1 && game->field[y][x] == 1) || x == -1 || x == 10) {
    err = 1;
  }
  return err;
}

void free_data(GameInfo_t* game) {
  for (int i = 0; i < 20; ++i) {
    free(game->field[i]);
  }
  free(game->field);

  for (int i = 0; i < 2; ++i) {
    free(game->next[i]);
  }
  free(game->next);
}

void score_lvl_speed(int line_amt, GameInfo_t* game, int* speed) {
  if (line_amt == 1) {
    game->score = game->score + 100;
  } else if (line_amt == 2) {
    game->score = game->score + 300;
  } else if (line_amt == 3) {
    game->score = game->score + 700;
  } else if (line_amt == 4) {
    game->score = game->score + 1500;
  }
  if (game->score > game->high_score) {
    game->high_score = game->score;
  }

  if (((game->score / 600) + 1 > game->level) && game->level != 10) {
    game->level = game->level + 1;
    (*speed) = (*speed) - 9000;
    game->speed = game->speed + 100;
  }
}

int move_figure(GameInfo_t* game, position* f, coordinate_f* c, int ch) {
  int a = 0, err = 0, y = 0, x = 0;
  coordinate_f test = (*c);
  // проверка на выход за поля
  check_and_write_0(game, f->Y, f->X);
  check_and_write_0(game, f->Y + c->Y1, f->X + c->X1);
  check_and_write_0(game, f->Y + c->Y2, f->X + c->X2);
  check_and_write_0(game, f->Y + c->Y3, f->X + c->X3);
  if (ch == 261) {  // справа
    x = 1;
  } else if (ch == 260) {  // слева
    x = -1;
  } else if (ch == 258) {  //  снизу
    y = 1;
  } else if (ch == 'c') {  //  сверху
    spin_f(f, c);
  }

  a = a + check_coord(game, f->Y + y, f->X + x);
  a = a + check_coord(game, f->Y + c->Y1 + y, f->X + c->X1 + x);
  a = a + check_coord(game, f->Y + c->Y2 + y, f->X + c->X2 + x);
  a = a + check_coord(game, f->Y + c->Y3 + y, f->X + c->X3 + x);
  // Если ошибки нет, рисуем на новом месте, прибавляя к основной координате 1
  if (a == 0) {
    f->Y = f->Y + y;
    f->X = f->X + x;
    check_and_write_1(game, f->Y, f->X);
    check_and_write_1(game, f->Y + c->Y1, f->X + c->X1);
    check_and_write_1(game, f->Y + c->Y2, f->X + c->X2);
    check_and_write_1(game, f->Y + c->Y3, f->X + c->X3);
  } else {  // Если есть ошибка рисуем на старом месте и выдаем ошибки
    (*c) = test;
    check_and_write_1(game, f->Y, f->X);
    check_and_write_1(game, f->Y + c->Y1, f->X + c->X1);
    check_and_write_1(game, f->Y + c->Y2, f->X + c->X2);
    check_and_write_1(game, f->Y + c->Y3, f->X + c->X3);
    err = 1;
  }
  return err;
}

int input_usr(GameInfo_t* game, position* f, coordinate_f* c, int* speed) {
  int err = 0, a = 0;
  for (int i = 0; i < 10; i++) {
    // Ожидание нажатия любой клавиши для выхода
    int ch = getch();

    move_figure(game, f, c, ch);
    if (ch == 'x') {
      game->pause = 1;
      // останавливаем инкерсес
      nodelay(stdscr, FALSE);
      while (a != 'x') {
        clear();
        output((*game));
        a = getch();
      }
      nodelay(stdscr, TRUE);  // возобновляем
      game->pause = 0;
    } else if (ch == 258) {
      int b = 0;
      while (b == 0) {
        b = move_figure(game, f, c, 258);
      }
    } else if (ch == 27) {
      err = 1;
      i = 10;
    }
    clear();
    output((*game));
    usleep((*speed));
  }
  return err;
}
