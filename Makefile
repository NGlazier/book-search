# Created by: Nasseef Abukamail
# This Makefile will run tests for the book class
# The tests will run automatically on Travis-CI.
# This is to test continuous integration (CI).
#
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.out: book.o book.h book_main.o
	$(CC) $(CFLAGS) _TEST/book.o _TEST/book_main.o -o a.out

book.o: book.cc book.h
	$(CC) -c $(CFLAGS) book.cc -o _TEST/book.o

book_main.o: book_main.cc book.h
	$(CC) -c $(CFLAGS) book_main.cc -o _TEST/book_main.o

######################################### R U N   T E S T s ##################################################
run_tests: book.h book.o book_main.o
	head book.cc
	$(CC) $(CFLAGS) _TEST/book.o _TEST/book_main.o -o _TEST/a.out
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/book.o -o _TEST/run_tests && ./_TEST/run_tests -sr compact
	sh _TEST/run_tests.sh
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.out _TEST/a.out