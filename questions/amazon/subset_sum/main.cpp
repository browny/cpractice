
/*
 * Q: Given a set of non-negative integers, and a value sum, determine if there is a
 * subset of the given set with sum equal to given sum.
 * Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
 * Output:  True  //There is a subset (4, 5) with sum 9.
 */

//A recursive solution for subset sum problem
#include <stdio.h>

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;

	// If last element is greater than sum, then ignore it
	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);

	/* else, check if sum can be obtained by any of the following
	   (a) including the last element
	   (b) excluding the last element   */
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

// Driver program to test above function
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set)/sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum\n");
	else
		printf("No subset with given sum\n");
	return 0;
}
