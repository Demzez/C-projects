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

all: test gcov_report

test: clean s21_math.a 
	$(CC) suite*.c s21_math_tests.c s21_math.a $(LIBS) -o s21_math_tests.out
	./s21_math_tests.out

gcov_report: s21_math.a
	$(CC) $(GCOV) suite*.c s21_math_tests.c s21_math.c $(LIBS) -o gcov_s21_math_tests.out
	./gcov_s21_math_tests.out
	lcov -t "GCOV_MATH_CHECK_REPORT" -o gcov_s21_math_tests.info -c -d . 
	genhtml -o report gcov_s21_math_tests.info

s21_math.a: 
	$(CC) -c s21_math.c -o s21_math.o
	ar rcs s21_math.a s21_math.o

leaks:
	make test
	leaks -atExit -- ./s21_math_tests.out | grep LEAK:
	make clean
	
linter: 
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

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
