CFLAGS=-g -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage
LFLAGS=-lcheck -lpthread -lm
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -fPIC
CFILES=s21_matrix.c
CEXE=test
VALGRIND_FLAGS  = 	--log-file="valgrind.txt" --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full

.PHONY: dist clean

all:
	gcc -Wall -Werror -Wextra  build/tetris.c gui/cli/front.c brick_game/tetris/back.c -lncurses
	
test: 
	gcc ${CFLAGS} tests/*.c brick_game/tetris/back.c  gui/cli/front.c -o s21_test -lncurses $(LFLAGS)
	./s21_test

back.a:
	gcc ${CFLAGS} -c brick_game/tetris/back.c -lncurses
	ar rc back.a *.o
	ranlib back.a
	rm -f *.o

clean:
	rm -rf *.a *.o *.gcno *.gcda test *.info s21_test report valgrind.txt tetris dist
	rm -rf htmlmake doc

gcov_report:clean
	gcc -g -Werror -Wall -Wextra -std=c11 tests/*.c brick_game/tetris/back.c  gui/cli/front.c -o s21_test -lcheck -lpthread -lm -fprofile-arcs -ftest-coverage -lncurses
	./s21_test
	lcov --capture --directory . -o coverage.info 
	lcov --remove coverage.info '/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/*' --output-file coverage.info.cleaned
	genhtml coverage.info.cleaned -o coverage_html
	open coverage_html/index.html


install: 
	gcc -Wall -Werror -Wextra  build/tetris.c gui/cli/front.c brick_game/tetris/back.c -lncurses -o tetris

valgrind: clean test
	valgrind $(VALGRIND_FLAGS) ./s21_test
	grep -n "ERROR SUMMARY" valgrind.txt

uninstall: 
	rm -rf tetris

dvi: clean
	doxygen dvi_config.txt
	open doc/html/index.html

format:
	cp ../materials/linters/.clang-format .
	find . -type f \( -name '*.c' -o -name '*.h' \) -exec clang-format -i {} \; -exec clang-format -n {} \;


dist: install
	mkdir -p dist
	cp -r Makefile brick_game build gui tetris dist/
	tar -ckzvf dist/tetris$(shell date +%Y%m%d).tar.gz -C dist .
	cd dist && rm -rf Makefile 