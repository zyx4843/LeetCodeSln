// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Given a binary tree, determine if it is a valid binary search tree (BST).

* Assume a BST is defined as follows:

*   1.The left subtree of a node contains only nodes with keys less than the node's key.
*   2.The right subtree of a node contains only nodes with keys greater than the node's key.
*   3.Both the left and right subtrees must also be binary search trees.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void PreorderTraversal(TreeNode *pNode, bool &bValidBST)
	{
		if (NULL == pNode || (!bValidBST))
		{
			return;
		}

		PreorderTraversal(pNode->left, bValidBST);
		if (NULL != m_pPrvNode)
		{
			if (pNode->val <= m_pPrvNode->val)
			{
				bValidBST = false;
				return;
			}
		}
		m_pPrvNode = pNode;
		PreorderTraversal(pNode->right, bValidBST);
	}
public:
	bool isValidBST(TreeNode *root) {
		bool bValidBST	= true;
		m_pPrvNode		= NULL;
		PreorderTraversal(root, bValidBST);
		return bValidBST;
	}
private:
	TreeNode	*m_pPrvNode;
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(5);
	TreeNode node2_1(3);
	TreeNode node2_2(8);
	TreeNode node3_1(2);
	TreeNode node3_2(4);
	TreeNode node3_3(6);
	TreeNode node3_4(9);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	node2_1.right = &node3_2;
	node2_2.left = &node3_3;
	node2_2.right = &node3_4;
	/***********************************/
	/*             5                   */
	/*           /   \                 */
	/*          3     8                */
	/*         / \   / \               */
	/*        2   4 6   9              */
	/***********************************/

	Solution so;
	bool bValidBST	= so.isValidBST(&node1);

	return 0;
}

