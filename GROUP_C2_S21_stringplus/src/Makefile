CC = gcc
GCOV=-fprofile-arcs -ftest-coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
  OPEN=xdg-open
else
  LIBS=-lcheck
  OPEN=open
endif
.PHONY: clean

all: test

test: clean s21_string.a 
	$(CC) s21_string_tests.c s21_string.a $(LIBS) -o s21_string_tests.out
	./s21_string_tests.out

gcov_report: s21_string.a
	$(CC) $(GCOV) s21_string_tests.c s21_string.c $(LIBS) -o gcov_s21_string_tests.out
	./gcov_s21_string_tests.out
	lcov -t "GCOV_STRING_CHECK_REPORT" -o gcov_s21_string_tests.info -c -d . 
	genhtml -o report gcov_s21_string_tests.info

s21_string.a: 
	$(CC) -c s21_string.c -o s21_string.o
	ar rcs s21_string.a s21_string.o

leaks:
	make test
	leaks -atExit -- ./s21_string_tests.out | grep LEAK:
	make clean
	
linter: 
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_string.c *.c *.h

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.gcda	
	rm -f *.gcno
	rm -f *.html
	rm -f *.out
	rm -f *.css
	rm -f *.info
	rm -rf ./report
