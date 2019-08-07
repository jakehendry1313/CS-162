/***************************************************************************
** Program name: Lab 1 - determinant.cpp
** Author:       Jacob Hendry
** Date:         4/7/2019
** Description:  This file will hold the funcion call determinant that will
**               determine the matrix that was chosen by the user. Once its
**               determined it would calculate the determinant based on the
**               matrix size and will then return it to the main function.
***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

/******************************************************
* This linear search function will find the target
* value simply by searching the array created.
******************************************************/
/*
void lineSearch(int searchNum)
{
     string inputName = "";
     int number;

     cout << "--------------Linear Search-------------" << endl;

     cout << "What is target value: ";
     cin >> searchNum;
     cout << endl;

     //Open all of the files 
     for (int i = 1; i < 5; i++)
     {
          ifstream inputFile;
          if (i == 1)
          {
               inputName = "num.txt";
               inputFile.open("num.txt");
          }

          if (i == 2)
          {
               inputName = "early.txt";
               inputFile.open("early.txt");
          }

          if (i == 3)
          {
               inputName = "mid.txt";
               inputFile.open("mid.txt");
          }

          if (i == 4)
          {
               inputName = "end.txt";
               inputFile.open("end.txt");
          }

          //Error message if the file doesn't exist
          if (!inputFile)
          {
               cout << "Error! Cannot find file." << endl;
          }

          //Else search the file for the target value
          else
          {
               int count = 0;
               while (!inputFile.eof())
               {
                    inputFile >> number;
                    if (number == searchNum)
                         count++;
               }

               if (count == 0)
               {
                    cout << inputName << ": target value not found" << endl;
               }

               else
               {
                    cout << inputName << ": target value found" << endl;
               }

               cout << endl;
          }

          //Close the files
          inputFile.close();
     }
}
*/

void sortNum(string outputName)
{
     ofstream outputFile;
     string inputName = "";
     int values[10], number = 0;

     for (int i = 1; i < 5; i++)
     {
          ifstream inputFile;
          if (i == 1)
          {
               inputName = "num.txt";
               inputFile.open("num.txt");
          }

          if (i == 2)
          {
               inputName = "early.txt";
               inputFile.open("early.txt");
          }

          if (i == 3)
          {
               inputName = "mid.txt";
               inputFile.open("mid.txt");
          }

          if (i == 4)
          {
               inputName = "end.txt";
               inputFile.open("end.txt");
          }

          if (!inputFile)
               cout << "Unable to open: " << inputName << endl;

          else
          {
               int count = 0;
               while (inputFile.eof())	//do while data still to be read from file
               {
                    inputFile >> number;
               }

               int temp;			//bubble sort adapted from textbook page 618
               bool swap;
               do
               {
                    swap = false;
                    int count = 0;
                    for (int i = (count - 1); i >= 0; count--)
                    {
                         for (int j = 1; j <= i; j++)
                         {
                              if (values[count - 1] > values[count])
                              {
                                   temp = values[count - 1];
                                   values[count - 1] = values[count];
                                   values[count] = temp;
                                   swap = true;
                              }
                         }
                    }
               } while (swap);
          }

          cout << "Please enter the filename for the output file: " << endl;
          cin >> outputName;

          outputFile.open(outputName.c_str());

          int count = 0;
          for (int i = 0; i < count - 1; count++)
          {
                    outputFile << values[count];
          }

          outputFile.close();

          ifstream tempFile;
          tempFile.open(outputName.c_str());
          while (tempFile >> number)
          {
                    cout << number << endl;
          }

     }

     inputFile.close();
}

/*
void binSearch(int searchNum)
{
     cin.clear();
     string inputFileName = "";
     int number;
     for (int i = 1; i < 5; i++)
     {
          ifstream inputFile;
          if (i == 1)
          {
               inputFileName = "early.txt";
               inputFile.open("early.txt");
          }
          if (i == 2)
          {
               inputFileName = "mid.txt";
               inputFile.open("mid.txt");
          }
          if (i == 3)
          {
               inputFileName = "end.txt";
               inputFile.open("end.txt");
          }
          if (i == 4)
          {
               inputFileName = "num.txt";
               inputFile.open("num.txt");
          }

          if (!inputFile)
               cout << "Unable to open: " << inputFileName << endl;	//error message if file not opened
          else
          {
               vector<int> values;
               //put data in ascending order in a vector
               int count = 0;
               while (inputFile >> number)	//do while data still to be read from file
               {
                    values.push_back(number);
               }

               int temp;			//bubble sort adapted from textbook page 618
               bool swap;
               do
               {
                    swap = false;
                    for (unsigned count = 0; count < values.size() - 1; count++)
                    {
                         if (values[count] > values[count + 1])
                         {
                              temp = values[count];
                              values[count] = values[count + 1];
                              values[count + 1] = temp;
                              swap = true;
                         }
                    }
               } while (swap);


               //Binary Search adapted from textbook page 601
               int first = 0;
               int last = values.size() - 1;
               int middle;
               int position = -1;
               bool found = false;
               while (!found && first <= last)
               {
                    middle = (first + last) / 2;
                    if (values[middle] == searchNum)
                    {
                         found = true;
                         position = middle;
                    }
                    else if (values[middle] > searchNum)
                         last = middle - 1;
                    else
                    {
                         first = middle + 1;
                    }
               }
               if (position != -1)
               {
                    cout << searchNum << " was found at position " << position << " in file " << inputFileName << "." << endl;
               }
               else cout << searchNum << " was NOT found in " << inputFileName << "." << endl;
          }
          inputFile.close();
     }
}
*/