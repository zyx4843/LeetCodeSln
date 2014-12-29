// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

* For example:
* Given binary tree {3,9,20,#,#,15,7},
*     3
*    / \
*   9  20
*     /  \
*    15   7
* return its zigzag level order traversal as:
* [
*   [3],
*   [9,20],
*   [15,7]
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > vec_vec_int;
		if (NULL == root)
		{
			return vec_vec_int;
		}

		int parent_num = 0, son_num = 1, vec_vec_index = -1,vec_index = 0;
		queue<TreeNode *> queue_node;
		queue_node.push(root);
		TreeNode *pNode = NULL;
		while (!queue_node.empty())
		{
			if (0 == parent_num)
			{
				vector<int> temp_vec_int(son_num);
				vec_vec_int.push_back(temp_vec_int);

				parent_num = son_num;
				son_num = 0;

				++vec_vec_index;
				vec_index = 0;

			}
			else
			{
				++vec_index;
			}

			pNode = queue_node.front();
			queue_node.pop();
			vec_vec_int[vec_vec_index][vec_index] = pNode->val;

			if (NULL != pNode->left)
			{
				queue_node.push(pNode->left);
				++son_num;
			}

			if (NULL != pNode->right)
			{
				queue_node.push(pNode->right);
				++son_num;
			}

			--parent_num;
		}

		return vec_vec_int;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(3);
	TreeNode node2_1(9);
	TreeNode node2_2(20);
	TreeNode node3_1(15);
	TreeNode node3_2(7);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_2.left = &node3_1;
	node2_2.right = &node3_2;

	Solution so;
	vector<vector<int> > vec_vec_int = so.levelOrder(&node1);

	return 0;
}

