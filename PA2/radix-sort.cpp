//============================================================================
// Name        : radix-sort.cpp
// Author      : Robert Hodge 
// Date        : 2/16/2017
// Copyright   : Robert Hodge ©
// Description : Implementation of radix sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
using namespace std;

// A function to get maximum value in an array
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}


// A function to do counting sort on the array
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void
RadixSort::sort(int A[], int size)
{
  // Find the maximum number to know number of digits
	int m = getMax(A, size);

	// Do counting sort for every digit
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(A, size, exp);
}
