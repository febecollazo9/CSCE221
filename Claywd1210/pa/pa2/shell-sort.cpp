//============================================================================
// Name        : shell-sort.cpp
// Author      : Febe Collazo
// Date        : Sept. 21, 2015
// Copyright   : Lecture slides: Analysis of Algorithms
// Description : Implementation of shell sort in C++
//============================================================================

#include "sort.h"

void ShellSort(int A[], int size)
{
  /* Complete this function with the implementation of shell sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
  int gap = size/2;
  int next_gap;
  for (; gap > 1; gap = next_gap){
	for (int i = gap; i < size; i++){
		int tmp = A[i];
		int j = i;
		while (j >= gap && tmp < A[j-gap]){
			A[j] = A[j-gap];
			j -= gap;
		}
		A[j] = tmp;
	}
	if (gap == 2) next_gap = 1;
	else next_gap = gap/2.2;
  }
}