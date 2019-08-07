/*****************************************************************************
** Program name: Lab 2 - letters.cpp
** Author:       Jacob Hendry
** Date:         4/14/2019
** Description:  This file will include the count_letters and output_letters
**               functions. The count_letters function will take an input 
**               file stream variable and a pointer to an array of integers.
**               The output_letters will take an output file stream variable
**               and a pointer to an array of integers that contains 
**               frequencies of letter.
***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "letters.hpp"

using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*****************************************************
The count_letters function will count every string in
the input file and count the frequency of each letter.
******************************************************/
void count_letters(ifstream &fileInput, int* arrLetters)
{
     char characterLetter;
     string lineString;

     getline(fileInput, lineString);

     //This for loop will 
     for (unsigned int i = 0; i < lineString.length(); i++)
     {
          characterLetter = tolower(lineString[i]);

          if ((characterLetter >= 97) && (characterLetter <= 122))
          {
               arrLetters[characterLetter - 97]++;
          }
     }
}
/*****************************************************
 * This output_letters function will output the 
 * letters to an output file and will display all
 * letters in the alphabet.
 ****************************************************/
void output_letters(ofstream &fileOutput, int* arrLetters)
{
     string outFile;
     char letters = 'a';
     const int ARR_SIZE = 26;       //Constant array to hold all 26 letters

     cout << "Enter the name for the output file with the"
	         "extension .txt: " << endl;
     getline(cin, outFile);

     fileOutput.open(outFile);

	 //Displays the letters in the output file
     for (int i = 0; i < ARR_SIZE; i++)
     {
          fileOutput << letters << ": " << arrLetters[i] << "\n";
          letters++;
     }

     fileOutput.close();
}
