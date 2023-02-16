CC = gcc -Wall -Werror -Wextra
GCOV=-fprofile-arcs -ftest-coverage
C_FILES = project/s21_stack.c project/s21_calculation.c
C_TESTS = tests/calc_tests.c tests/test_runner.c
OS=$(shell uname)
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
  OPEN=xdg-open
else
  LIBS=-lcheck
  OPEN=open
endif

all: install run

install:
	cd project && qmake
	cd project && $(MAKE) install
	rm -rf project/SmartCalc project/SmartCalc.app

run: 
	open SmartCalc/SmartCalc*

uninstall: clean
	cd project && $(MAKE) clean
	cd project && $(MAKE) uninstall
	rm -rf project/Makefile
	rm -rf project/.qmake.stash
	rm -rf project/.qtc_clangd

clean:
	rm -f tests/*.out
	rm -rf report
	rm -f project/*.o
	rm -f *.gcda	
	rm -f *.gcno
	rm -f *.html
	rm -f *.out
	rm -f *.css
	rm -f *.info
	rm -f .DS_Store

tests: clean
	$(CC) $(C_TESTS) project/s21_stack.c project/s21_calculation.c  $(LIBS) -o tests/calc_tests.out
	tests/./calc_tests.out

style: clean
	clang-format -i project/*.c
	clang-format -n project/*.c

gcov_report:
	$(CC) $(GCOV) $(C_TESTS) project/s21_stack.c project/s21_calculation.c $(LIBS) -o gcov_calc_tests.out
	./gcov_calc_tests.out
	tests/lcov/bin/./lcov -t "GCOV_CALC_CHECK_REPORT" -o gcov_calc_tests.info -c -d . 
	tests/lcov/bin/./genhtml -o report gcov_calc_tests.info

dvi:
	open dvi.pdf


.PHONY: all install run uninstall clean gcov_report
