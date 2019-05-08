# Sorting
LAB07
<functional>
Allows for passing functions as parameters
<time.h>
timing functions
Even though it's name it time.h it's still included using:
<cassert>
Access to assert statements
Helpful Examples
Timing
#include <time.h>
<cstdlib>
For rand() and srand()
srand
seed random number generator
rand()
returns an int between 0 and RAND_MAX
Example usages:
//From C++ Reference website linked above
v0 = rand();               //v0 in the range of 0 to RAND_MAX
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
Assert Statements
Assert statements are pretty simple things: you provide a boolean expression you expect to true. If it's true, the the program continues as normal. But, if it's not, then the programs halts.
This is not the same as throwing an exception. An exception typically used in place of a method returning. An assert is used to prevent the program from continuing with something unrecoverable being wrong or missing.
assert( (2+2) == 4 ); //Nothing happens. 2+2 is 4
assert( (2+2) == 5 ); //It's 1984. They've won. Shut it down. Shut it down now.
Lab Overview
In this you will implements the following sorts:

bubble
selection
insertion
merge
quick
always chooses the last value in array as pivot value
quickWithMedian
quickWithMedian uses the median of the first, middle, and last value as the pivot

All of the sorts will be accessible through a Sorts class via static method calls.

Your program will be used to time a particular sort and collect timing data at increasing sizes of n. Your program will accept command line arguments that allows the user to choose the following options:

pick a sort they want to time
select the bounds for the size of the array
select how much the array size will increase with each new timing
provide the name of a desired output file to store timing data
Example command line input:

$>./lab07 bubble 100 1000 50 bubbleTime.txt 
What your program would do with this input is:

time bubble sort with a random array of size 100, 150...900, 950, and 1000, storing timing data for each size of n in the file "bubbleTime.txt"
Asserts
You must support the option to run an assert statement at the end of each of your sorts' runs. The user will have an optional last flag to evoke an assert after each sort runs.

$>./lab07 bubble 100 1000 50 bubbleTime.txt assert
Output file
Your output file should contain the follow data:

<name of sort>
<n>,<time to sort n>
<n>,<time to sort n>
<n>,<time to sort n>
<n>,<time to sort n>
<n>,<time to sort n>
Example of a bubbleTimes.txt that timed bubble sort over the range of 100 too 300 increasing n by 100 each time (I just made up these times):

bubbleSort
100,0.000034
200,0.000048
300,0.000452
Lab Write-up
Time all the sorts from size n=1000 to size n=100000 with the size of the array increasing by 1000 each time (e.g. collect timing data for n=1000, n=2000...n=99000, n=100000 for each sort)

Warning the timing will take a non-trivial amount of time to run. Test your code with small values for n, across small intervals to make sure you program works before firing off the big timing run.

Questions

Plot your data in a spreadsheet with time in seconds on the y-axis and the size of n on the x-axis (plots should be in the pdf you turn). Make sure the sorts are clearly labeled
Do the sorts we know to be of O(n^2) complexity demonstrate this behavior? (The iterative sorts)
Do the sorts we know to be of O(n*lg(n)) complexity demonstrate this behavior? (The recursive sorts)
For any plot points that are outliers (far away from the rest of the curve), how do you explain them?

Classes
Sorts Class
This class will still contain bubble, selection, insertion, merge, quick, and quickSortWithMedian (a modification of quick sort) sorts along with any helper methods a sort may need.

This class will contain all static method methods and hold no member variables.

public methods:

static void bubbleSort(T arr[], int size);
static void selectionSort(T arr[], int size);
static void insertionSort(T arr[], int size);
static void mergeSort(T arr[], int size);
static void quickSort(T arr[], int size);
Calls quickSortRec with median flag set to false
static void quickSortWithMedian(T arr[], int size);
Calls quickSortRec with median flag set to true
static bool isSorted(T arr[], int size);
Returns true only if the array is sorted


Notes:

The keyword static grants access to a methods without declaring an instance of that class
Example call:
#include "Sorts.h"
int main()
{
   //create an array of ints

   Sorts<int>::bubbleSort(someArray, someSize); //calls bubble sort on the array
}
private methods:

static void merge(T* a1, T* a2, int size1, int size2)
used by merge sort to two sorted combine arrays (which are actually two halved of a single array) into a single sorted array
static void quickSortRec(T arr[], int first, int last, bool median);
sorts the array by partitioning the array, quick sorting every left of the pivot, and quick sorting everything right of the pivot
passes median to partition to inform that method how to pick a pivot value
static void setMedianPivot(T arr[], int first, int last)
used by quickSort
puts the median value of the array in the last position
REMINDER: We only consider the first, middle, and last value. Example, if the array had 100 elements, we'd only look at index 0, 50, and 99 and find the median among those values
make sure not to lose any values in the process!
static int partition(T arr[], int first, int last, bool median)
used by quickSort
partitions the array
chooses a pivot based on the median flag, if median is true, use setMedianPivot, otherwise select the last element in the array
returns the index of the pivot
SortTimer Class
I recommend making a simple class used to time sorts. Some methods able to time a particular sort, create an array of a desired filled random values, and any other helper methods used for timing.

<time.h>
The standard libary <time.h> include timing methods like clock() and time(). It's important to use clock() instead of time() because clock tells how much processor time was spent doing something versus how much actual time. Why don't we want actual time? Well, if your machine is doing a LOT of other tasks (e.g. watching netflix, playing a game, download 100% legal music) then your sorting algorithm could appear slower than it actually is only because other processes were using the processor instead.

Example of timing: Original from C++ Reference. It had an error in it that I fixed below. I did not fix the shameful formatting they used.

/* clock example: frequency of primes */
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */

int frequency_of_primes (int n) {
  int i,j;
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}

int main ()
{
  clock_t t;
  int f;
  t = clock();
  printf ("Calculating...\n");
  f = frequency_of_primes (99999);
  printf ("The number of primes lower than 100,000 is: %d\n",f);
  t = clock() - t;
  printf ("It took me %d clicks (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);
  return 0;
}
Functions as parameters
With the <functional> library you can treat functions as parameters, meaning you can choose what function you want another function to call.

This is very useful for us, because it allows us to create a single timing method then just pass in the name of the sort function we want to run along with the array we want it to sort.

Example:

double SortTimer::timeASort(std::function<void(T[],int)> sort, T arr[], int size)
{
   //start a timer

   //call the sort passed to us
   sort(arr, size);

   //stop the timer

   //return the time
}
Rubric
[50pts] Lab write-up
[35pts] Question 1
NOTE: Data must be generated using your program!
[5pts] Question 2
[5pts] Question 3
[5pts] Question 4
[35pts] Sorts
[5pts] bubble
[5pts] selection
[5pts] insertion
[5pts] merge
[7.5pts] quick
[7.5pts]quickWithMedian
[10pts] Modularity
[5pts] Documentation
