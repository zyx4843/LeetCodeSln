#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <hash_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct UndirectedGraphNode {
    int label;
	vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution{
public:
	bool isPalindrome(string s) {
		int i = 0;
		int j = s.length() - 1;
		while(i < j)
		{
			while( (!isAlphanumeric(s[i])) && (i < j) ) ++i;
			while( (!isAlphanumeric(s[j])) && (i < j) ) --j;
			if (s[i] != s[j])
			{
				break;
			}
			else
			{
				++i;
				--j;
			}
		}

		if (i < j)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	int findMin(vector<int> &num) {
		int big = num.size();
		if (0 == big)
		{
			return 0;
		}
		else if (1 == big)
		{
			return num[0];
		}
		else if (2 == big)
		{
			if (num[0] < num[1])
			{
				return num[0];
			}
			else
			{
				return num[1];
			}
		}

		big	= num.size() - 1;
		int little = 0;

		while(num[little] == num[big])
		{
			--big;
		}

		if (num[little] > num[big])
		{
			little = big;
			big = 0;
		}
		int mid = big / 2;
		int newMid = mid;
		do 
		{
			mid = newMid;
			if (num[mid] <= num[little])
			{
				little = mid;
			}
			else
			{
				big = mid;
			}
			newMid = (little + big) / 2;
		} while (newMid != mid);

		if (num[mid] <= num[little])
		{
			return num[mid];
		}
		else
		{
			return num[little];
		}
	}
	int maxSubSum(int A[], int n) {
		int positiveSum1 = 0, positiveSum2 = 0;
		int negativeSum = 0;
		int maxSubSum = 0;
		int i = 0;
		while( (i < n) && (0 >= A[i])) ++i;
		if (i >= n)
		{
			for (i = 0; i < n; ++i)
			{
				maxSubSum += A[i];
			}
			return maxSubSum;
		}

		for (; i < n; ++i)
		{
			if (0 > A[i])
			{
				if (0 > A[i])
				{
					negativeSum += A[i];
				}
				else
				{
					if (0 != positiveSum2)
					{
						if (0 <= (positiveSum2 + negativeSum))
						{
							positiveSum1 += positiveSum2 + negativeSum;
						}
						else if (positiveSum2 >= positiveSum1)
						{
							positiveSum1 = positiveSum2;
						}
						else
						{
							if (maxSubSum < positiveSum1)
							{
								maxSubSum = positiveSum1;
							}
							positiveSum1 = positiveSum2;
						}
						positiveSum2 = 0;
						negativeSum = A[i];
					}
					else
					{
						negativeSum = A[i];
					}
				}
			}
			else
			{
				if (0 == negativeSum)
				{
					positiveSum1 += A[i];
				}
				else
				{
					positiveSum2 += A[i];
				}
			}
		}

		if (0 == positiveSum2)
		{
			if (maxSubSum < positiveSum1)
			{
				maxSubSum = positiveSum1;
			}
		}
		else
		{
			if (0 <= (positiveSum2 + negativeSum))
			{
				positiveSum1 += positiveSum2 + negativeSum;
			}
			else if (positiveSum2 >= positiveSum1)
			{
				positiveSum1 = positiveSum2;
			}

			if (maxSubSum < positiveSum1)
			{
				maxSubSum = positiveSum1;
			}
		}

		return maxSubSum;
	}
	int maxProduct(int A[], int n) {
		int positiveProductFirst = 0, positiveProductLast = 0, midProduct = 1;
		int negativeFirst = 0, negativeLast = 0;
		int max_product = 0x80000000;
		int i = 0;
		while( (i < n) && (0 == A[i])) ++i;
		if (i >= n)
		{
			return 0;
		}

		for (; i < n; ++i)
		{
			if (0 == A[i])
			{
				if (0 == negativeLast)
				{
					if (0 != negativeFirst)
					{
						if (positiveProductLast > positiveProductFirst)
						{
							positiveProductFirst = positiveProductLast;
						}
						else if (0 == positiveProductFirst)
						{
							positiveProductFirst = negativeFirst;
						}
					}
				}
				else
				{
					positiveProductFirst = (0 == positiveProductFirst) ? 1 : positiveProductFirst;
					positiveProductLast = (0 == positiveProductLast) ? 1 : positiveProductLast;
					if (0 < midProduct)
					{
						positiveProductFirst *= midProduct * negativeFirst * negativeLast * positiveProductLast;
					}
					else
					{
						if ( (positiveProductFirst * negativeFirst) < (negativeLast * positiveProductLast) )
						{
							positiveProductFirst *= negativeFirst * midProduct;
						}
						else
						{
							positiveProductFirst = positiveProductLast * negativeLast * midProduct;
						}
					}
				}

				if (max_product < positiveProductFirst)
				{
					max_product = positiveProductFirst;
				}
				positiveProductFirst = 0;
				positiveProductLast = 0;
				negativeFirst = 0;
				negativeLast = 0;
				midProduct = 1;
				if (0 > max_product)
				{
					max_product = 0;
				}
				while( (i + 1 < n) && (0 == A[i + 1])) ++i;
			}
			else if (0 > A[i])
			{
				if (0 == negativeFirst)
				{
					negativeFirst = A[i];
				}
				else
				{
					if (0 != positiveProductLast)
					{
						midProduct *= positiveProductLast;
					}

					if (0 != negativeLast)
					{
						midProduct *= negativeLast;
					}

					positiveProductLast = 0;
					negativeLast = A[i];
				}
			}
			else
			{
				if (0 == negativeFirst)
				{
					if (0 == positiveProductFirst)
					{
						positiveProductFirst = A[i];
					}
					else
					{
						positiveProductFirst *= A[i];
					}
				}
				else
				{
					if (0 == positiveProductLast)
					{
						positiveProductLast = A[i];
					}
					else
					{
						positiveProductLast *= A[i];
					}
				}
			}
		}

		if (0 != A[n-1])
		{
			if (0 == negativeLast)
			{
				if (0 != negativeFirst)
				{
					if (positiveProductLast > positiveProductFirst)
					{
						positiveProductFirst = positiveProductLast;
					}
					else if (0 == positiveProductFirst)
					{
						positiveProductFirst = negativeFirst;
					}
				}
			}
			else
			{
				positiveProductFirst = (0 == positiveProductFirst) ? 1 : positiveProductFirst;
				positiveProductLast = (0 == positiveProductLast) ? 1 : positiveProductLast;
				if (0 < midProduct)
				{
					positiveProductFirst *= midProduct * negativeFirst * negativeLast * positiveProductLast;
				}
				else
				{
					if ( (positiveProductFirst * negativeFirst) < (negativeLast * positiveProductLast) )
					{
						positiveProductFirst *= negativeFirst * midProduct;
					}
					else
					{
						positiveProductFirst = positiveProductLast * negativeLast * midProduct;
					}
				}
			}

			if (max_product < positiveProductFirst)
			{
				max_product = positiveProductFirst;
			}
		}

		return max_product;
	}
	void reverseWords(string &s) {
		if (s.empty())
		{
			return;
		}

		string str = s;
		int alphaNum = 0;
		s.clear();
		for (int i = str.length() - 1; i >= 0; --i)
		{
			if (' ' == str[i])
			{
				if (0 < alphaNum)
				{
					s.append(&str[i + 1], alphaNum);
					s.append(&str[i], 1);
					alphaNum = 0;
				}
			}
			else
			{
				++alphaNum;
			}
		}

		if (' ' != str[0])
		{
			s.append(&str[0], alphaNum);
		}
		else
		{
			if (s.length() > 0)
			{
				if (' ' == s[s.length() - 1])
				{
					s.erase(s.length() - 1, 1);
				}
			}
		}
	}
	int evalRPN(vector<string> &tokens) {
		int len = tokens.size();
		if (1 == len)
		{
			return atoi(tokens[0].c_str());
		}

		int *pIteger = new int[len / 2 + 1];
		int index = 1;
		pIteger[0] = atoi(tokens[0].c_str());
		pIteger[1] = atoi(tokens[1].c_str());
		for (int i = 2; i < len; ++i)
		{
			if (1 == tokens[i].length())
			{
				if ("+" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] + pIteger[index];
					--index;
				}
				else if ("-" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] - pIteger[index];
					--index;
				}
				else if ("*" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] * pIteger[index];
					--index;
				}
				else if ("/" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] / pIteger[index];
					--index;
				}
				else
				{
					pIteger[++index] = atoi(tokens[i].c_str());
				}
			}
			else
			{
				pIteger[++index] = atoi(tokens[i].c_str());
			}
		}

		len = pIteger[0];
		delete []pIteger;

		return len;
	}

	int maxPoints(vector<Point> &points) {
		int num = points.size();
		if (2 >= num)
		{
			return num;
		}

		int maxPoint = 0;
		std::map<float, int> float_map;
		float float_tan = 0;
		int zero_count = 1;
		int two_zero = 0;
		for (int i = 0; i < num - 1; ++i)
		{
			for (int j = i + 1; j < num; ++j)
			{
				if (0 != points[j].x - points[i].x)
				{
					float_tan = (points[j].y - points[i].y) / (float)(points[j].x - points[i].x);
					if (float_map.find(float_tan) != float_map.end())
					{
						++float_map[float_tan];
					}
					else
					{
						float_map[float_tan] = 2;
					}
				}
				else if(points[j].y != points[i].y)
				{
					++zero_count;
				}
				else
				{
					++two_zero;
				}
			}

			for (std::map<float, int>::iterator it = float_map.begin(); it != float_map.end(); ++it)
			{
				if (maxPoint < it->second + two_zero)
				{
					maxPoint = it->second + two_zero;
				}
			}
			float_map.clear();

			if (maxPoint < zero_count + two_zero)
			{
				maxPoint = zero_count + two_zero;
			}
			zero_count = 1;

			if (maxPoint < two_zero + 1)
			{
				maxPoint = two_zero + 1;
			}
			two_zero = 0;
		}

		return maxPoint;
	}

	void quitSortList(ListNode *&begin, ListNode *&end)
	{
		if(end == begin)
		{
			return;
		}

		if(end == begin->next)
		{
			if(begin->val > end->val)
			{
				ListNode *pTemp = begin;
				begin = end;
				end = pTemp;
				begin->next = end;
			}

			return;
		}

		static ListNode scLeft(0);
		static ListNode scRight(0);
		ListNode *pLeft_begin = &scLeft, *pRight_begin = &scRight, *pLeft_end = &scLeft, *pRight_end = &scRight;
		ListNode *pPos = begin->next, *pMid_end = begin;

		while(end != pPos)
		{
			if(pPos->val < begin->val)
			{
				pLeft_end->next = pPos;
				pLeft_end = pPos;
			}
			else if (pPos->val == begin->val)
			{
				pMid_end->next = pPos;
				pMid_end = pPos;
			}
			else
			{
				pRight_end->next = pPos;
				pRight_end = pPos;
			}
			pPos = pPos->next;
		}

		if(pPos->val < begin->val)
		{
			pLeft_end->next = pPos;
			pLeft_end = pPos;
		}
		else if (pPos->val == begin->val)
		{
			pMid_end->next = pPos;
			pMid_end = pPos;
		}
		else
		{
			pRight_end->next = pPos;
			pRight_end = pPos;
		}

		pLeft_begin = (pLeft_begin != pLeft_end) ? scLeft.next : NULL;
		pRight_begin = (pRight_begin != pRight_end) ? scRight.next : NULL;

		pPos = begin;
		if(NULL != pLeft_begin)
		{
			quitSortList(pLeft_begin, pLeft_end);
			pLeft_end->next = begin;
			end = pMid_end;
			pPos = pLeft_begin;
		}

		if(NULL != pRight_begin)
		{
			quitSortList(pRight_begin, pRight_end);
			pMid_end->next = pRight_begin;
			end = pRight_end;
		}

		begin = pPos;
	}
	ListNode *sortList(ListNode *head) {
		if( (NULL == head) || (NULL == head->next) )
		{
			return head;
		}
		ListNode *pPos = head->next;
		ListNode left(0);
		ListNode right(0);
		ListNode *pLeft_end = &left, *pRight_end = &right, *pMid_end = head;

		while(NULL != pPos)
		{
			if(pPos->val < head->val)
			{
				pLeft_end->next = pPos;
				pLeft_end = pPos;
			}
			else if (pPos->val == head->val)
			{
				pMid_end->next = pPos;
				pMid_end = pPos;
			}
			else
			{
				pRight_end->next = pPos;
				pRight_end = pPos;
			}
			pPos = pPos->next;
		}

		if(pLeft_end != &left)
		{
			quitSortList(left.next, pLeft_end);
			pPos = left.next;
			pLeft_end->next = head;
		}
		else
		{
			pPos = head;
		}

		if(pRight_end != &right)
		{
			quitSortList(right.next, pRight_end);
			pRight_end->next = NULL;
		}

		pMid_end->next = right.next;

		return pPos;
	}

	ListNode *insertionSortList(ListNode *head) {
		if ( (NULL == head) || (NULL == head->next) )
		{
			return head;
		}
		ListNode *pSortHead = head;
		ListNode *pSortTail = head;
		ListNode *pPos = head->next;
		ListNode *pTemp = NULL, *pSortPos = NULL;

		while (NULL != pPos)
		{
			if (pPos->val < pSortHead->val)
			{
				pTemp = pSortHead;
				pSortHead = pPos;
				pPos = pPos->next;
				pSortHead->next = pTemp;
			}
			else if (pPos->val >= pSortTail->val)
			{
				pSortTail->next = pPos;
				pSortTail = pPos;
				pPos = pPos->next;
			}
			else
			{
				pSortPos = pSortHead;
				while ( (pSortPos->next != pSortTail) && (pSortPos->next->val < pPos->val) )
				{
					pSortPos = pSortPos->next;
				}

				pTemp = pSortPos->next;
				pSortPos->next = pPos;
				pPos = pPos->next;
				pSortPos->next->next = pTemp;
			}
		}

		pSortTail->next = NULL;
		return pSortHead;
	}

	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> postorder_vec;
		if (NULL == root)
		{
			return postorder_vec;
		}

		stack<TreeNode *> postorder_stack;
		vector<bool>		bVisit_vec;		//是否访问过
		postorder_stack.push(NULL);
		postorder_stack.push(root);
		bVisit_vec.push_back(false);
		TreeNode *pTempNode = postorder_stack.top();
		int visit_index = 0;
		while (NULL != pTempNode)
		{
			if ( (bVisit_vec[visit_index]) || ((NULL == pTempNode->right) && (NULL == pTempNode->left)) )
			{
				postorder_vec.push_back(pTempNode->val);
				postorder_stack.pop();
				bVisit_vec.pop_back();
				--visit_index;
			}
			else
			{
				bVisit_vec[visit_index] = true;
				if (NULL != pTempNode->right)
				{
					postorder_stack.push(pTempNode->right);
					bVisit_vec.push_back(false);
					++visit_index;
				}

				if (NULL != pTempNode->left)
				{
					postorder_stack.push(pTempNode->left);
					bVisit_vec.push_back(false);
					++visit_index;
				}
			}

			pTempNode = postorder_stack.top();
		}

		return postorder_vec;
	}

	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> preorder_vec;
		if (NULL == root)
		{
			return preorder_vec;
		}

		stack<TreeNode *> preorder_stack;
		preorder_stack.push(NULL);
		TreeNode *pTempNode = root;
		while (NULL != pTempNode)
		{
			preorder_vec.push_back(pTempNode->val);
			if (NULL != pTempNode->right)
			{
				preorder_stack.push(pTempNode->right);
			}

			if (NULL != pTempNode->left)
			{
				pTempNode = pTempNode->left;
			}
			else
			{
				pTempNode = preorder_stack.top();
				preorder_stack.pop();
			}
		}

		return preorder_vec;
	}

	ListNode *FindMidNode(ListNode *pHead)
	{
		ListNode *p1 = pHead, *p2 = pHead;
		while ( (NULL != p2) && (NULL != p2->next))
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}

		p2 = p1->next;
		p1->next = NULL;

		return p2;
	}

	ListNode *ReverseList(ListNode *pHead)
	{
		ListNode *pReverseHead = NULL, *pTemp = NULL;
		while (NULL != pHead)
		{
			pTemp = pReverseHead;
			pReverseHead = pHead;
			pHead = pHead->next;
			pReverseHead->next = pTemp;
		}

		return pReverseHead;
	}

	void reorderList(ListNode *head) {
		if ( (NULL == head) || (NULL == head->next) || (NULL == head->next->next) )
		{
			return;
		}

		ListNode *pMidNode = FindMidNode(head);
		pMidNode = ReverseList(pMidNode);

		ListNode *pPos = head, *pTemp = NULL;

		do 
		{
			pTemp = pPos->next;
			pPos->next = pMidNode;
			pMidNode = pMidNode->next;
			pPos->next->next = pTemp;
			pPos = pTemp;

		} while (NULL != pMidNode);
	}

	bool wordBreak(string s, stdext::hash_set<string> &dict) {
		if (s.empty())
		{
			return false;
		}

		vector<int> vec_end_pos;
		int start_pos = 0;
		int len = s.size();
		int end_pos = 1;
		vec_end_pos.push_back(0);
		for (; end_pos <= len; ++end_pos)
		{
			for (vector<int>::reverse_iterator it = vec_end_pos.rbegin(); it != vec_end_pos.rend(); ++it)
			{
				string sub_str = s.substr((*it), end_pos - (*it));
				if (dict.find(sub_str) != dict.end())
				{
					vec_end_pos.push_back(end_pos);
					break;
				}
			}
		}

		if (len == vec_end_pos.back())
		{
			return true;
		}

		return false;
	}

	vector<string> WordBreak(string s, stdext::hash_set<string> &dict) {
		if (s.empty())
		{
			vector<string> vec_str;
			return vec_str;
		}

		vector<int> vec_end_pos;
		int len = s.size();
		int end_pos = len - 1;
		vector<vector<string>> vec_start_str(len);
		bool bAdd = false;
		int vec_len = 0;
		for (; end_pos > 0; --end_pos)
		{
			bAdd = false;
			vec_len = vec_end_pos.size();
			string sub_str1 = s.substr(end_pos, len - end_pos);
			if (dict.find(sub_str1) != dict.end())
			{
				vec_start_str[vec_len].push_back(sub_str1);
				bAdd = true;
			}

			for (int i = 0; i < vec_end_pos.size(); ++i)
			{
				string sub_str2 = s.substr(end_pos, vec_end_pos[i] - end_pos);
				if (dict.find(sub_str2) != dict.end())
				{
					for (int j = 0; j < vec_start_str[i].size(); ++j)
					{
						vec_start_str[vec_len].push_back(sub_str2 + " " + vec_start_str[i][j]);
					}
					bAdd = true;
				}
			}

			if (bAdd)
			{
				vec_end_pos.push_back(end_pos);
			}
		}

		vec_len = vec_end_pos.size();
		string sub_str1 = s.substr(0, len);
		if (dict.find(sub_str1) != dict.end())
		{
			vec_start_str[vec_len].push_back(sub_str1);
		}

		for (int i = 0; i < vec_end_pos.size(); ++i)
		{
			string sub_str2 = s.substr(0, vec_end_pos[i]);
			if (dict.find(sub_str2) != dict.end())
			{
				for (int j = 0; j < vec_start_str[i].size(); ++j)
				{
					vec_start_str[vec_len].push_back(sub_str2 + " " + vec_start_str[i][j]);
				}
			}
		}

		return vec_start_str[vec_len];
	}

public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (NULL == head)
		{
			return NULL;
		}
		map<RandomListNode *, RandomListNode *> map_randomlist;

		RandomListNode *pCopyHead = new RandomListNode(head->label);
		map_randomlist.insert(map<RandomListNode *, RandomListNode *>::value_type(head, pCopyHead));
		RandomListNode *pSrcNode = head->next;
		RandomListNode *pDetNode = pCopyHead;
		while (NULL != pSrcNode)
		{
			pDetNode->next = new RandomListNode(pSrcNode->label);
			map_randomlist.insert(map<RandomListNode *, RandomListNode *>::value_type(pSrcNode, pDetNode->next));
			pSrcNode = pSrcNode->next;
			pDetNode = pDetNode->next;
		}

		pSrcNode = head;
		pDetNode = pCopyHead;
		while (NULL != pSrcNode)
		{
			if (NULL != pSrcNode->random)
			{
				pDetNode->random = map_randomlist[pSrcNode->random];
			}
			pSrcNode = pSrcNode->next;
			pDetNode = pDetNode->next;
		}

		return pCopyHead;
	}

	int singleNumber(int A[], int n) {
		int odd	= 0;		//三次中出现奇数次的数位
		int even = 0;		//三次中出现偶数次的数位
		int temp = 0;		//消除出现三次的数位
		for (int i = 0; i < n; ++i)
		{
			even ^= odd & A[i];
			odd ^= A[i];
			temp = ~(odd & even);
			even &= temp;
			odd &= temp;
		}

		return odd;
	}

	int singleNumber3(int A[], int n) {
		int single = 0;
		int mask = 0x1;
		int count = 0;
		for (int i = 0; i < 32; ++i)
		{
			count = 0;
			for (int j = 0; j < n; ++j)
			{
				if (A[j] & mask)
				{
					++count;
				}
			}

			if (1 == count % 3)
			{
				single |= mask;
			}

			mask = mask << 1;
		}

		return single;
	}

	int candy(vector<int> &ratings) {
		if (ratings.empty())
		{
			return 0;
		}
		int num = ratings.size();
		if (1 == num)
		{
			return 1;
		}
		int candyNum = 0;
		int increase_prev = 1;	//递增的前一个糖果数
		int decrease_count = 0;	//递减的个数
		int decrease_max = 0;
		int equel_num = 0;	//递增相等的个数
		int max_equel_num = 0;

		for (int i = 1; i < num; ++i)
		{
			if (ratings[i - 1] < ratings[i])
			{
				if (0 == decrease_count)
				{
					candyNum += increase_prev;
					++increase_prev;
				}
				else
				{
					if (increase_prev > decrease_max)
					{
						candyNum += (increase_prev - decrease_max) * (1 - max_equel_num);
					}
					increase_prev = 2;
					decrease_count = 0;
					decrease_max = 0;
					max_equel_num = 0;
				}
				equel_num = 0;
			}
			else if (ratings[i - 1] == ratings[i])
			{
				if (0 == decrease_count)
				{
					candyNum += increase_prev;
					increase_prev = 1;
					++equel_num;
				}
				else
				{
					candyNum += 1;
					decrease_count = 1;
				}
			}
			else
			{
				if (0 == decrease_count)
				{
					candyNum += 3;
					decrease_count = 2;
					decrease_max = 2;
					max_equel_num = equel_num;
				}
				else
				{
					++decrease_count;
					candyNum += decrease_count;
					++decrease_max;
				}
				equel_num = 0;
			}
		}

		if (0 == decrease_count)
		{
			if (ratings[num - 1] == ratings[num - 2])
			{
				candyNum += increase_prev;
				candyNum -= equel_num * (increase_prev - 1);
			}
			else
			{
				candyNum += increase_prev;
			}
		}
		else
		{
			if (increase_prev > decrease_max)
			{
				candyNum += (increase_prev - decrease_max) * (1 - max_equel_num);
			}
		}

		return candyNum;
	}

	int candy2(vector<int> &ratings)
	{
		vector<int> candyCnt(ratings.size()) ;
		//allocate candies, considering the minimal rating on the left
		candyCnt[0] = 1;
		for(int i = 1; i < ratings.size(); i++){
			candyCnt[i] = ratings[i] > ratings[i-1] ? candyCnt[i-1]+1 : 1;
		}
		//modify the allocation, considering the minimal rating on the right
		int totalCandy = candyCnt[ratings.size()-1];
		for(int i = ratings.size()-2; i >= 0; i--){
			candyCnt[i] = (ratings[i] > ratings[i+1] && candyCnt[i+1]+1 > candyCnt[i]) ? candyCnt[i+1]+1 : candyCnt[i];
			//count total candies by the way
			totalCandy += candyCnt[i];
		}

		return totalCandy;
	}

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.empty())
		{
			return -1;
		}

		int num = gas.size();
		if (1 == num)
		{
			return (0 <= (gas[0] - cost[0])) ? 0 : -1;
		}

		vector<int> remain_gas(num);
		vector<int> remain_pos(num);
		int temp_remain = 0;
		int index = 0;
		remain_gas[0] = gas[0] - cost[0];
		remain_pos[0] = 0;
		int remain_sum = remain_gas[0];
		for (int i = 1; i < num; ++i)
		{
			temp_remain = gas[i] - cost[i];
			if (0 <= (temp_remain ^ remain_gas[index]))
			{
				remain_gas[index] += temp_remain;
			}
			else
			{
				remain_gas[++index] = temp_remain;
				remain_pos[index] = i;
			}
			remain_sum += temp_remain;
		}

		if (0 > remain_sum)
		{
			return -1;
		}

		if (0 <= (remain_gas[index] ^ remain_gas[0]) )
		{
			remain_gas[0] += remain_gas[index];
			remain_pos[0] = remain_pos[index];
			--index;
		}

		for (int i = 0; i <= index; ++i)
		{
			if (0 <= remain_gas[i])
			{
				remain_sum = remain_gas[i];
				for (int j = i + 1; j < index; ++j)
				{
					remain_sum += remain_gas[j];
					if (0 > remain_sum)
					{
						break;
					}
				}

				if (0 <= remain_sum)
				{
					for (int j = 0; j < i; ++j)
					{
						remain_sum += remain_gas[j];
						if (0 > remain_sum)
						{
							break;
						}
					}

					if (0 <= remain_sum)
					{
						return remain_pos[i];
					}
				}
			}
		}

		return -1;
	}

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (NULL == node)
		{
			return NULL;
		}

		stack<UndirectedGraphNode *> stack_unSearchNode;
		map<int, UndirectedGraphNode *> map_undirectedGraph;
		UndirectedGraphNode *pRoot = new UndirectedGraphNode(node->label);
		map_undirectedGraph.insert(map<int, UndirectedGraphNode *>::value_type(node->label, pRoot));
		stack_unSearchNode.push(node);
		UndirectedGraphNode *pOld = NULL, *pNew = NULL, *pTemp = NULL;
		while(!stack_unSearchNode.empty())
		{
			pOld = stack_unSearchNode.top();
			stack_unSearchNode.pop();
			if (!pOld->neighbors.empty())
			{
				pNew = map_undirectedGraph[pOld->label];
				for (int i = 0; i < pOld->neighbors.size(); ++i)
				{
					if (map_undirectedGraph.end() != map_undirectedGraph.find(pOld->neighbors[i]->label))
					{
						pNew->neighbors.push_back(map_undirectedGraph[pOld->neighbors[i]->label]);
					}
					else
					{
						pTemp = new UndirectedGraphNode(pOld->neighbors[i]->label);
						map_undirectedGraph.insert(map<int, UndirectedGraphNode *>::value_type(pOld->neighbors[i]->label, pTemp));
						stack_unSearchNode.push(pOld->neighbors[i]);
						pNew->neighbors.push_back(pTemp);
					}
				}
			}
		}

		return pRoot;
	}

private:
	bool isAlphanumeric(char &c)
	{
		if ( (('0' <= c) && ('9' >= c)) || (('a' <= c) && ('z' >= c)) )
		{
			return true;
		}
		else if(('A' <= c) && ('Z' >= c))
		{
			c += 32; 
			return true;
		}
		else
		{
			return false;
		}
	}
};