/**************************************************************************
** Program name: Lab 2 - lettersMain.cpp
** Name:         Jacob Hendry
** Date:         4/14/2019
** Description:  This is the main file that will implement the two functions
**               count_letters and output_letters. It will ask the user for
**               the input file to read from and then use the two functions
**               to determine the frequency of letters in that file.
***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "letters.hpp"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
     const int ARR_SIZE = 26;
     ifstream inputFile;
     ofstream outputFile;
     string fileName;
     int arrLetters[ARR_SIZE];  //This will hold the const array of 26

     //The user will enter the text file
	 cout << "Enter the input file with the extension .txt: " << endl;
     
	 getline(cin, fileName);

     inputFile.open(fileName);

	 //If the input file doesn't exist it won't work 
     if (!inputFile)
     {
          cout << "Error! - Please try again." << endl;
          return 1;
     }

	 //If the file works, it continues with the functions
     while (inputFile)
     {
          for (int i = 0; i < ARR_SIZE; i++)
          {
               arrLetters[i] = 0;
          }

          count_letters(inputFile, arrLetters);
          output_letters(outputFile, arrLetters);

          inputFile.peek();
     }

	 //Need to close the input file
     inputFile.close();

     return 0;
}
