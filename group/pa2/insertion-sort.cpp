//============================================================================
// Name        : insertion-sort.cpp
// Author      : Febe Collazo
// Date        : Sept. 21, 2015
// Copyright   : Lecture slides: Analysis of Algorithms
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{
	
  /* Complete this function with the implementation of insertion sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
  for (int k = 1; k < size; k++)
  {
	int tmp = A[k];
	int j = k;
	++num_cmps;			//account for comparison in for loop
	for (; j > 0 && tmp < A[j-1]; j--){
		A[j] = A[j-1];
		if (j!=k) ++num_cmps;	//account for comparison in for loop
	}
	A[j] = tmp;
  }
}
