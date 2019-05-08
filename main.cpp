/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 7
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#include <iostream>
#include "Executive.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
 //check program parameters - did the user add a file to be opened?
 if (argc < 6)
 {
   cout << "Be sure you have the correct number of parameters. \n"
        << "You will need: ./sort <SORT TYPE> <LWR BOUND> <UPR BOUND> <INCREMENT> <OUTPUT FILE NAME>\n";
 }
 else
 {
   string sortType = argv[1];
   int lowerBound = stoi(argv[2]);
   int upperBound = stoi(argv[3]);
   int increment = stoi(argv[4]);
   string fileName = argv[5];

   //run code in Executive.cpp
   Executive exec(sortType, lowerBound, upperBound, increment, fileName);
   exec.sort();
 }
 return 0;
}
