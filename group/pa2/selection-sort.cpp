//============================================================================
// Name        : selection-sort.cpp
// Author      : Febe Collazo	
// Date        : Sept. 21, 2015
// Copyright   : Lecture Slides: Analysis of Algorithms
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void
SelectionSort::sort(int A[], int size)				// main entry point
{
  /* Complete this function with the implementation of selection sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
  for (int k = 0; k < size-1; k++)
  {
	int index = k;
	++num_cmps;	//account for comparison in for loop
	for (int i = k+1; i < size; i++)
		if (A[i] < A[index]) index =i;
		num_cmps += 2;	// acount for if statement and for loop comparisions
	int tmp = A[k];     // swaps A[k] and A[index]
	A[k] = A[index];
	A[index] = tmp;
  }
}
