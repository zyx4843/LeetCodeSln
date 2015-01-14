// Source : https://oj.leetcode.com/problems/partition-list/
// Author : zheng yi xiong 
// Date   : 2015-01-06

/********************************************************************************** 
* 
* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

* You should preserve the original relative order of the nodes in each of the two partitions.

* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		if (NULL == head)
		{
			return NULL;
		}
		
		ListNode *pNode = head, *pGreater = NULL, *pLess = NULL, *pEnd = NULL;
		while (NULL != pNode)
		{
			if (x > pNode->val)
			{
				if (NULL == pLess)
				{
					head = pNode;
				}
				else
				{
					pLess->next = pNode;
				}
				pLess = pNode;
			}
			else
			{
				if (NULL == pGreater)
				{
					pGreater = pNode;
					pEnd = pNode;
				}
				else
				{
					pEnd->next = pNode;
				}
				pEnd = pNode;
			}
			pNode = pNode->next;
		}

		if (NULL != pLess && NULL != pGreater)
		{
			pLess->next = pGreater;
			pEnd->next = NULL;
		}

		return head;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int int_array[] = {1, 4, 3, 2, 5, 2};
	ListNode *pHead = new ListNode(int_array[0]);
	ListNode *pNode = pHead;
	for (int i = 1; i < sizeof(int_array) / 4; ++i)
	{
		pNode->next = new ListNode(int_array[i]);
		pNode = pNode->next;
	}
	Solution so;
	ListNode *pRet = so.partition(pHead, 3);
	return 0;
}

