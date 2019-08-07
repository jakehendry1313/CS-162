/**************************************************************************
** Program name: Lab 2 - letters.hpp
** Name:         Jacob Hendry
** Date:         4/14/2019
** Description:  This is the letters header file. It will hold the prototype
**               funtions to count the letters and to output the letters to
**               an output file.
***************************************************************************/
#ifndef LETTERS
#define LETTERS
#include <fstream>

using std::ifstream;
using std::ofstream;

//This function will count the letters in the input file
void count_letters(ifstream &fileInput, int* arrLetters);

//This function will output the letters to an output file
void output_letters(ofstream &fileInput, int* arrLetters);

#endif
