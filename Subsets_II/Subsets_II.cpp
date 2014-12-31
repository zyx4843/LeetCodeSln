// Source : https://oj.leetcode.com/problems/subsets-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-31

/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.

* Note:
*  Elements in a subset must be in non-descending order.
*  The solution set must not contain duplicate subsets.
* For example,
*  If S = [1,2,2], a solution is:

* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

