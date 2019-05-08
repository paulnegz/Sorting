/* File Name: Executive.h
 * Author: Paul Negedu
 * EECS 268 - Lab 7
 * Description:  Initializes the Executive methods used in Executive.cpp
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Sorts.h"
#include "SortTimer.h"
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

class Executive
{
public:
  /** @pre None
	*   @post Assigns user-determined values to the member variables.
	*   @return None.
	*/
  Executive(string sort, int lower, int upper, int inc, string fileN);

  /** @pre None.
	*   @post None.
	*   @return None.
	*/
  ~Executive();

  /** @pre Constructor has assigned values to member variables.
	*   @post Takes control from main() and performs the desired sorting algorithm.
	*   @return none.
	*/
  void sort();

private:
  string sortType; //The type of sort algorithm that the user desires
  int lowerBound;  //The lowest array size tested by the program
  int upperBound;  //The highest array size tested by the program
  int increment;   //How much the array size increases each trial
  string fileName; //Where the user wants the clock data to go

  bool sortTrue;   //Whether the sort parameter was accepted
  double elapsedTime_secs; //The amount of time taken to perform a sorting algorithm

};
#endif
