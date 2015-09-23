//============================================================================
// Name        : bubble-sort.cpp
// Author      : Miguel Nava
// Date        : 09/21/2015
// Copyright   : Miguel Inc.
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class Sort
  */
	for (int k = 1; k < size; k++) {
		++num_cmps;		//account for comparison in for loop statement
		bool cont = false;
		for (int j = 0; j < size - k; j++)
			++num_cmps;		//account for comparison in nested for loop statement
			if (A[j+1] < A[j]) {
				++num_cmps;		//account for comparison in if statement
				int tmp = A[j]; // swap A[j] and A[j+1]
				A[j] = A[j+1];
				A[j+1] = tmp;
				cont = true;
			}
		if (!cont) break; // stop sorting
	}
}
