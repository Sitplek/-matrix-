CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -std=c11
GCOVFLAGS:=-fprofile-arcs -ftest-coverage
LDFLAGS:=-lcheck -lgcov -fprofile-arcs --coverage
ifeq ($(shell uname), Linux)
LDFLAGS +=-lpthread -lrt -lm -lsubunit
OPEN_CMD:=xdg-open
else ifeq ($(shell uname), Darwin)
OPEN_CMD:=open
endif

SRC:= $(wildcard s21_*.c)
OBJ = $(addprefix ,$(SRC:.c=.o))
OBJ_GCOV = $(addprefix ,$(SRC:.c=.o))
TEST_SRC:= $(wildcard tests/test_*.c)
TEST_OBJ = $(addprefix tests/,$(TEST_SRC:.c=.o))

all: s21_matrix.a test

s21_matrix.a: $(OBJ)
	ar -src $@ $(OBJ)

s21_matrix_gcov.a: $(OBJ_GCOV)
	ar -src $@ $(OBJ_GCOV) 

test: tests/test_s21_matrix.o s21_matrix_gcov.a
	$(CC) -g $< s21_matrix_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	clear
	./test

clean:
	rm -rf *.o
	rm -f gcov_obj/*.gc*
	rm -f ./test
	rm -f -r out
	rm -f gcov_obj/*.info
	rm -f .DS_Store
	rm -f *.a
	rm -rf test.dSYM
	rm -f tests/*.o
	rm -f ../.DS_Store
	clear

%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

gcov_report: test
	lcov -c -d . -o /coverage.info
	genhtml /coverage.info --output-directory out
	$(OPEN_CMD) out/index.html

rebuild: clean all

clang:
	clang-format -i *.c *.h tests/*.c
