GCC=gcc -Wall -Werror -Wextra

all: test gcov_report

convertors.a : convertors.c
	$(GCC) -c convertors.c 
	ar rc  convertors.a convertors.o 
	ranlib convertors.a

test: clean test_convertors.c convertors.a
	# gcc  -Wall -Wextra -Werror -std=c11 -c test_convertors.c -o test_convertors.o
	gcc test_convertors.c -lcheck  convertors.a -o test
	./test

rebuild: clean all

temp: 
	$(GCC) temp.c -o temp

clean:
	rm -rf s21_math
	rm -rf s21_test
	rm -rf test
	rm -rf out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
