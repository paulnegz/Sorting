/* File Name: Executive.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 7
 * Description:  Defines the methods that will run the program, calling other classes
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#include "Executive.h"

using namespace std;

Executive::Executive(string sort, int lower, int upper, int inc, string fileN)
{
  sortType = sort;
  lowerBound = lower;
  upperBound = upper;
  increment = inc;
  fileName = fileN;
  sortTrue = false;
}

void Executive::sort()
{
    //Use the <time.h> library to measure how much time each sort took
    clock_t startTime;
    clock_t endTime;
    clock_t elapsedTime; //endTime - startTime

    //Open file object
    ofstream outFile;
    outFile.open(fileName);
    outFile << sortType << endl;

    if(sortType == "bubble")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating selection sort algorithm...\n";

      while (aSize <= upperBound)
{
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::bubbleSort(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The bubble sort algorithm for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;

    }
  }

    else if (sortType == "selection")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating selection sort algorithm...\n";

      while (aSize <= upperBound)
      {
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::selectionSort(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The selection sort algorithm for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;
      }
    }

    else if (sortType == "insertion")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating inesertion sort algorithm...\n";

      while (aSize <= upperBound)
      {
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::insertionSort(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The insertion sort algorithm for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;
      }

    }

    else if (sortType == "merge")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating merge sort algorithm...\n";

      while (aSize <= upperBound)
      {
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::mergeSort(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The merge sort algorithm for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;
      }
    }

    else if (sortType == "quick")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating quick sort algorithm...\n";

      while (aSize <= upperBound)
      {
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::quickSort(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The quick sort algorithm for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;
      }
    }

    else if (sortType == "quickWithMedian")
    {
      sortTrue = true;
      int aSize = lowerBound;

      cout << "Now calculating quick sort with median algorithm...\n";

      while (aSize <= upperBound)
      {
        int* array = new int[aSize];
        for(int i = 0; i < aSize; i++)
        {
          array[i] = rand() % aSize;
        }

        startTime = clock();
        Sorts<int>::quickSortWithMedian(array, aSize);
        endTime = clock();
        elapsedTime = endTime - startTime;
        elapsedTime_secs = (elapsedTime/static_cast<double>(CLOCKS_PER_SEC));

        outFile << aSize << "," << elapsedTime_secs << endl;

        cout << "The quick sort algorithm (with median) for " << aSize << " elements took " << elapsedTime_secs << " seconds.\n";

        aSize += increment;
        delete[] array;
      }
    }

    else sortTrue = false;

    if(sortTrue)
    {
      outFile.close();
    }
    else //Code runs if the user gives an invalid sort
    {
      cout << "Sorry, that is not a valid sort type.\n";
    }

}

Executive::~Executive()
{


}
