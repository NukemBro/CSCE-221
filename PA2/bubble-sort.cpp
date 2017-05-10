//============================================================================
// Name        : bubble-sort.cpp
// Author      : Grant Hruzek
// Date        : 2/7/17
// Copyright   : Grant Hruzek ©
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  for (int i = 1; i < size; ++i) {
		bool cont = false;
		for (int j = 0; j < size - i; ++j) {
		++num_cmps;
		if (A[j] > A[j + 1]) {
			int temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			cont = true;
			}
		}
		if(!cont) break;
	}
}
