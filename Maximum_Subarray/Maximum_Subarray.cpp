// Source : https://leetcode.com/problems/maximum-subarray/
// Author : zheng yi xiong 
// Date   : 2015-03-10

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

* For example, given the array [-2,1,-3, 4, -1, 2, 1, -5, 4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int maxSubSum = A[0], curSubSum = A[0];
		for (int i = 1; i < n; ++i)
		{
			if (0 > A[i])
			{
				if (curSubSum > maxSubSum)
				{
					maxSubSum = curSubSum;
				}

				if (A[i] > maxSubSum)
				{
					maxSubSum = A[i];
				}

				curSubSum += A[i];
			}
			else
			{
				if (0 >= curSubSum)
				{
					curSubSum = A[i];
				}
				else
				{
					curSubSum += A[i];
				}
			}
		}

		if (curSubSum > maxSubSum)
		{
			maxSubSum = curSubSum;
		}

		return maxSubSum;
	}
};

int maxSubArrayDivideConquer(int A[], int n) {
	int *sum = new int[n];
	sum[0] = A[0];
	int maxSub = A[0]; 
	for (int i = 1; i < n; ++i)
	{
		sum[i] = max(A[i], A[i] + sum[i-1]);
		maxSub = max(m, sum[i]);
	}
	delete[] sum;
	return maxSub;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {-2,1,-3, 4, -1, 2, 1, -5, 4};
	Solution so;
	int maxSubSum = so.maxSubArray(A, 9);
	return 0;
}

