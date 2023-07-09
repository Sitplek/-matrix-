SYS = $(shell uname)
CC = gcc
FLAGS = -c -Wall -Wextra -Werror -std=c11
SRCS = ./*.c
OBJS = $(SRCS:%.c=%.o)
LIB_NAME = s21_decimal.a

TEST_SRC = test_files/*.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_FLAG = --coverage -Wall -Wextra -Werror

ifeq ($(SYS), Darwin) # check OS
	LIB_FLAGS = -lcheck
else
	LIB_FLAGS = -lcheck -lsubunit -pthread -lrt -lm
endif

all: clean s21_decimal.a test

s21_decimal.a: $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)
	ranlib $(LIB_NAME)

%.o: %.c s21_decimal.h
	$(CC) $(FLAGS) $< -o $@
clean:
	rm -rf lib_obj ./*.o ./*.a ./*.o ./a.out gcov_test *.html *.css report lib/*.dSYM ./*.gcno ./*.gcda ./*.info ./*.dSYM ./CPPLINT*

test: s21_decimal.a
	$(CC) $(TEST_FLAG) $(TEST_SRC) $(SRCS) $(LIB_NAME) $(LIB_FLAGS) -o gcov_test 
	chmod +x *
	./gcov_test

gcov_report: s21_decimal.a
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d . # -t отвечает за имя теста https://stackoverflow.com/questions/837639/is-there-a-way-to-focus-lcov-code-coverage-reports-to-just-one-or-two-directorie
	genhtml -o report/ gcov_test.info # генерирует html страницу
	open ./report/index.html

check: test
	cp ../materials/linters/.clang-format .
	clang-format -style=google -i ./*.c s21_decimal.h test_files/*.c test_files/*.h
	clang-format -style=google -n ./*.c s21_decimal.h test_files/*.c test_files/*.h
