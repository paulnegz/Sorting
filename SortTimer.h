/* File Name: SortTimer.
 * Author: Paul Ngedu
 * EECS 268 - Lab 7
 * Description: Defines methods used to time sorts used in other classes
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#ifndef SORTTIMER_H
#define SORTTIMER_H

#include <iostream>
#include <time.h>
#include <functional>
#include "Sorts.h"

template <typename T>
class SortTimer
{
public:
    /** @pre Takes in a function, along with an array and its size.
	*   @post None.
	*   @return Returns the amount of time taken to sort an array.
	*/
    static double timer(std::function<void(T[],int)> sortchoice, T arr[],int size);

};
#include "SortTimer.hpp"
#endif
