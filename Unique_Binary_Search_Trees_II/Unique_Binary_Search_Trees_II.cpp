// Source : https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-29

/********************************************************************************** 
* 
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.

*   1         3     3      2      1
*    \       /     /      / \      \
*     3     2     1      1   3      2
*    /     /       \                 \
*   2     1         2                 3
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		vector<vector<TreeNode *>> vec_tree(n + 1);
		vec_tree[1].push_back(1);
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
	return 0;
}

