// Cassian
// 9/16/22
// week 2 assignment, binary search
// main.cpp - using binary search to find specific value and its index in an array


#include <iostream>
#include <algorithm>

using namespace std;


int binarySearch(double array[], double num, int lower, int upper) // declare method with parameters to take in
{
	if (upper >= lower) // if upper bound is greater than lower bound
	{
		int mid = lower + (upper - lower) / 2; // set mid position
		if (array[mid] == num) // if mid is the number
			return mid;

		if (array[mid] > num) // then number must be in lower half, so search that
			return binarySearch(array, num, lower, mid - 1);

		return binarySearch(array, num, mid + 1, upper); // or search the right half otherwise
	}

	return -1;
}

int main()
{
	double numArray[] = { 4.5, 6, 1, 9.2, 4, 77, 1200, 16.4 }; // declare array with double values
	double num = 9.2; // assign variable to the number
	int x = sizeof(numArray) / sizeof(numArray[0]); // assign variable to the array length
	sort(numArray, numArray + x); // sort the array first so order is asc

	int numPos = binarySearch(numArray, num, 0, x - 1); // assign

	if (numPos == -1) // if the method can't find it and returns -1
		printf("The number's position could not be found");
	else
		printf("The number is found at position %d", numPos); // print numPos

}

