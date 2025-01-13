#include "tests.h"

START_TEST(test_spin_1) {
  int x = 0;
  int y = 1;

  spin(&x, &y);

  ck_assert_int_eq(x, -1);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(test_spin_2) {
  GameInfo_t g;
  position f;
  f.figure = 2;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  coordinate_tetromino(2, &c);

  move_figure(&g, &f, &c, 'c');
  free_data(&g);

  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_3) {
  GameInfo_t g;
  position f;
  f.figure = 2;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  coordinate_tetromino(2, &c);

  move_figure(&g, &f, &c, 261);
  free_data(&g);
}
END_TEST

START_TEST(test_spin_4) {
  GameInfo_t g;
  position f;
  f.figure = 4;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  coordinate_tetromino(f.figure, &c);

  move_figure(&g, &f, &c, 'c');
  free_data(&g);
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_5) {
  GameInfo_t g;
  g.score = 0;
  g.high_score = 100;
  int speed = 100;
  g.level = 0;
  score_lvl_speed(1, &g, &speed);

  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_6) {
  GameInfo_t g;
  g.score = 0;
  g.high_score = 100;
  int speed = 100;
  g.level = 0;
  score_lvl_speed(4, &g, &speed);

  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_7) {
  GameInfo_t g;
  position f;
  f.figure = 2;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  coordinate_tetromino(2, &c);

  move_figure(&g, &f, &c, 258);
  free_data(&g);
}
END_TEST

START_TEST(test_spin_9) {
  GameInfo_t g;
  starting_p(&g);
  end_game(&g);
  free_data(&g);
}
END_TEST

START_TEST(test_spin_10) {
  GameInfo_t g;
  position f;
  f.figure = 2;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  g.field[5][6] = 1;

  coordinate_tetromino(f.figure, &c);

  move_figure(&g, &f, &c, 'c');
  free_data(&g);
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_11) {
  GameInfo_t g;
  position f;
  f.figure = 1;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  g.field[5][6] = 1;

  coordinate_tetromino(f.figure, &c);

  move_figure(&g, &f, &c, 'c');
  free_data(&g);
  ck_assert_int_eq(0, 0);
}

START_TEST(test_spin_12) {
  GameInfo_t g;
  position f;
  f.figure = 7;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  g.field[5][6] = 1;

  coordinate_tetromino(f.figure, &c);

  move_figure(&g, &f, &c, 'c');
  free_data(&g);
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_13) {
  GameInfo_t g;

  starting_p(&g);
  g.field[5][6] = 1;

  //  coordinate_tetromino(f.figure, &c);
  for (int i = 0; i < 10; i++) {
    spawn(&g);
  }
  free_data(&g);
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_14) {
  position d;
  put_figure(&d);
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_16) {
  GameInfo_t g;
  starting_p(&g);
  for (int i = 0; i < 10; i++) {
    g.field[15][i] = 1;
    g.field[16][i] = 1;
  }
  delete_line(&g);
  free_data(&g);
}
END_TEST

START_TEST(test_spin_17) {
  GameInfo_t g;
  position f;
  f.figure = 2;
  f.X = 5;
  f.Y = 5;
  coordinate_f c;

  starting_p(&g);
  coordinate_tetromino(2, &c);

  for (int i = 0; i < 10; i++) {
    g.field[6][i] = 1;
  }

  move_figure(&g, &f, &c, 258);
  free_data(&g);
}
END_TEST

START_TEST(test_spin_18) {
  GameInfo_t g;
  g.score = 0;
  g.high_score = 100;
  int speed = 100;
  g.level = 0;
  score_lvl_speed(2, &g, &speed);

  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_19) {
  GameInfo_t g;
  g.score = 0;
  g.high_score = 100;
  g.level = 0;
  int speed = 100;
  score_lvl_speed(3, &g, &speed);

  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_spin_20) {
  GameInfo_t g;
  g.score = 500;
  g.high_score = 100;
  g.level = 0;
  int speed = 100;
  score_lvl_speed(3, &g, &speed);

  ck_assert_int_eq(0, 0);
}
END_TEST

Suite *s21_test_spin(void) {
  Suite *s = suite_create("spin");
  TCase *tc = tcase_create("spin");

  tcase_add_test(tc, test_spin_1);
  tcase_add_test(tc, test_spin_2);
  tcase_add_test(tc, test_spin_3);
  tcase_add_test(tc, test_spin_4);
  tcase_add_test(tc, test_spin_5);
  tcase_add_test(tc, test_spin_6);
  tcase_add_test(tc, test_spin_7);
  tcase_add_test(tc, test_spin_9);
  tcase_add_test(tc, test_spin_10);
  tcase_add_test(tc, test_spin_11);
  tcase_add_test(tc, test_spin_12);
  tcase_add_test(tc, test_spin_13);
  tcase_add_test(tc, test_spin_14);
  tcase_add_test(tc, test_spin_16);
  tcase_add_test(tc, test_spin_17);
  tcase_add_test(tc, test_spin_18);
  tcase_add_test(tc, test_spin_19);
  tcase_add_test(tc, test_spin_20);

  suite_add_tcase(s, tc);

  return s;
}