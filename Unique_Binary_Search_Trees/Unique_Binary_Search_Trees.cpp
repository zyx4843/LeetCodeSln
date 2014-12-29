// Source : https://oj.leetcode.com/problems/unique-binary-search-trees/
// Author : zheng yi xiong 
// Date   : 2014-12-29

/********************************************************************************** 
* 
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

* For example,
* Given n = 3, there are a total of 5 unique BST's.

*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> vec_num_tree(n + 1, 0);
		vec_num_tree[0] = 1;
		vec_num_tree[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				vec_num_tree[i] += vec_num_tree[j] * vec_num_tree[i - j - 1];
			}
		}

		return vec_num_tree[n];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 4;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	int num_trees = so.numTrees(n);

	return 0;
}

