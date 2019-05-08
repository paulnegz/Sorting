/* File Name: SortTimer.hpp
 * Author: Paul Ngedu
 * EECS 268 - Lab 7
 * Description: Defines methods used to time sorts used in other classes
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#include "SortTimer.h"

template <typename T>
double SortTimer<T>::timer(std::function<void(T[],int)> sortchoice, T arr[],int size)
{
  clock_t t = clock(); //declares an instance of clock_t and defines it to current clock time
  sortchoice(arr, size); //uses the desired sort algorithm
  double algTime = (double)(clock() - t) / CLOCKS_PER_SEC * 1000;
  return(algTime); //returns amount of time needed.
}
