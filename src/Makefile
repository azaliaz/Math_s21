.PHONY: all clean test s21_math.a check rebuild open gcov_report
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: s21_math.a gcov_report

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

s21_math.o: s21_math.c
	$(CC) -c s21_math.c -o s21_math.o

test: clean s21_math.a 
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) s21_math_test.c s21_math.a -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) s21_math_test.c s21_math.a -o test.out $(LIBS) $(LINUX)
endif

gcov_report: 
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) s21_math_test.c s21_math.c -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) s21_math_test.c s21_math.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "test" -o test.info -c -d .
# genhtml -o report/ gcov_test.info
	genhtml -o report/ test.info
	open report/index.html 

# gcov_test.info: gcov_test gcov_test.gcda
# 	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

# gcov_test: s21_math_test.c

# ifeq ($(OS), Darwin)
# 	$(CC) $(CFLAGS) $(LFLAGS) s21_math_test.c s21_math.c -o gcov_test $(LIBS)
# else
# 	$(CC) $(CFLAGS) $(LFLAGS) s21_math_test.c s21_math.c -o gcov_test $(LIBS) $(LINUX)
# endif

# gcov_test.gcda: 
# 	chmod +x *
# 	./gcov_test

# open: gcov_report
# 	open report/index.html

rebuild: clean all

check:
	cppcheck *.c
	clang-format -n *.c
	clang-format -n *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind ./test.out --leak-check=full
endif
	make clean

clean:
	rm -rf *.o *.a *.info *.out
	rm -rf report
	rm -rf *.gcno
	rm -rf *.gcda
