// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : zheng yi xiong 
// Date   : 2015-01-08

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (NULL == head)
		{
			return NULL;
		}

		ListNode *pRoot = new ListNode(head->val - 1);
		pRoot->next = head;

		bool bDelete = false;
		ListNode *pPrev = pRoot, *pNode = head->next;
		ListNode *pTemp = NULL;
		while (NULL != pNode)
		{
			if (pPrev->next->val != pNode->val)
			{
				if (bDelete)
				{
					bDelete = false;
					pTemp = pPrev->next;
					pPrev->next = pNode;
					pNode = pNode->next;
					delete pTemp;
				}
				else
				{
					pPrev->next->next = pNode;
					pPrev = pPrev->next;
					pNode = pNode->next;
				}
			}
			else
			{
				bDelete = true;
				pPrev->next->next = NULL;
				pTemp = pNode;
				pNode = pNode->next;
				delete []pTemp;
			}
		}

		if (bDelete)
		{
			pTemp = pPrev->next;
			pPrev->next = NULL;
			delete pTemp;
		}

		head = pRoot->next;
		delete pRoot;

		return head;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	int maxNumber = 3;
	if ( argc > 2) {
		n = _wtoi(argv[1]);
		maxNumber = _wtoi(argv[2]);
	}

	ListNode *head = new ListNode(1);
	ListNode *pNode = head;

	cout<<"sorted linked list:\n";
	cout<<head->val;

	srand(time(0));
	for(int i = 1; i < n; ++i) {
		int duplicate = rand() % maxNumber + 1;
		for (int j = 0; j < duplicate; ++j)
		{
			pNode->next = new ListNode(i + 1);
			pNode = pNode->next;
			cout<<" "<<pNode->val;
		}
	}
	cout<<endl;

	Solution so;
	ListNode *pHead = so.deleteDuplicates(head);

	cout<<"return list:\n ";
	pNode = pHead;
	while (NULL != pNode)
	{
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;

	system("pause");

	return 0;
}

