#Program:     makefile for letter frequency
#Author:      Jacob Hendry
#Date:        4/14/2019
#Description: This is the makefile that will combine every file needed to
#             compile the program.

CC = g++
CFLAGS = -c -Wall -std=c++11

output: lettersMain.o letters.o
	$(CC) lettersMain.o letters.o -o output

lettersMain.o: lettersMain.cpp
	$(CC) $(CFLAGS)  lettersMain.cpp

letters.o: letters.cpp letters.hpp
	$(CC) $(CFLAGS)  letters.cpp

clean:
	rm *.o output
