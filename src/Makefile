CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c++17
CHECK_FLAG = -lstdc++
TESTFLAGS = -pthread -lgtest
SANITIZE=-fsanitize=address -g
LCOVFLAGS = --ignore-errors inconsistent --ignore-errors mismatch

LIB_NAME = s21_matrix_oop

SRCS=$(wildcard s21_*.cpp)

OBJS=$(SRCS:.cpp=.o)

all: clean test

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css Main SANITIZE *.dSYM SANMAIN *.info report

clang-format:
	clang-format -i *.cpp *.h

test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) -c check.cpp -o check.o
	$(CC) $(FLAGS) $(CHECK_FLAG) check.o $(LIB_NAME).a $(TESTFLAGS) -o test
	rm -rf *.o

main: clean $(LIB_NAME).a
	$(CC) $(FLAGS) -c main.cpp -o main.o
	$(CC) $(FLAGS) $(CHECK_FLAG) main.o $(LIB_NAME).a -o Main
	rm -rf main.o

leaks : clean main
	leaks -atExit -- ./Main

sanitize: clean $(LIB_NAME).a
	$(CC) $(FLAGS) -c check.cpp -o check.o
	$(CC) $(FLAGS) $(SANITIZE) $(CHECK_FLAG) check.o $(LIB_NAME).a $(TESTFLAGS) -o SANITIZE
	rm -rf *.o


add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test
	./test
	lcov -t "check" -o check.info -c -d ./  --no-external $(LCOVFLAGS)
	genhtml -o report check.info $(LCOVFLAGS)
	open report/index.html

#cppcheck --enable=all --suppress=missingIncludeSystem src/