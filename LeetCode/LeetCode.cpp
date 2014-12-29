// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
//#include "Solution.cpp"
#include "MinStack.h"
#include "LRUCache.cpp"
#include "Palindrome_Partitioning.cpp"
#include "Palindrome_Partitioning_II.cpp"
#include "Surrounded_Regions.cpp"
#include "Sum_Root_to_Leaf_Numbers.cpp"
#include "Longest_Consecutive_Sequence.cpp"
#include "Word_Ladder.cpp"
#include "Word_Ladder_II.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	/*string str = "A man, a plan, a canal: Panama";
	Solution solution;
	bool bret = solution.isPalindrome(str);
	vector<int> num;
	num.push_back(2);
	num.push_back(4);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	num.push_back(6);
	num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(2);
	num.push_back(2);
	int minNum = solution.findMin(num);

	int A[] = {2,3,-2,4};
	int maxSub = solution.maxSubSum(A, 4);
	int B[] = {3,-1,4};
	int max_product = solution.maxProduct(B, sizeof(B)/4);
	string s = "   a  ";
	solution.reverseWords(s);
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	int sum = solution.evalRPN(tokens);
	MinStack minStack;
	minStack.push(2);
	minStack.push(0);
	minStack.push(3);
	minStack.push(0);
	int stack_min = minStack.getMin();
	minStack.pop();
	stack_min = minStack.getMin();
	minStack.pop();
	stack_min = minStack.getMin();
	minStack.pop();
	stack_min = minStack.getMin();

	minStack.push(4);
	minStack.push(6);
	minStack.push(41);
	minStack.push(64);
	minStack.push(24);
	minStack.push(7);
	minStack.push(5);
	minStack.push(9);
	minStack.push(2);
	minStack.push(0);
	minStack.push(1);
	minStack.push(2);
	minStack.push(14);
	minStack.push(123);
	minStack.push(78);
	minStack.push(-6);
	minStack.push(14);
	minStack.push(8);
	minStack.push(-45);
	minStack.push(96);
	minStack.push(3);
	minStack.push(0);
	minStack.push(23);
	int top_stack = minStack.top();
	stack_min = minStack.getMin();
	for (int i = -10000; i < 10000; ++i)
	{
		minStack.push(i);
	}
	top_stack = minStack.top();
	stack_min = minStack.getMin();
	minStack.pop();
	minStack.pop();
	minStack.pop();
	minStack.pop();
	minStack.pop();
	minStack.pop();
	top_stack = minStack.top();
	stack_min = minStack.getMin();
	ListNode *head = new ListNode(1);
	ListNode *pPos = new ListNode(2);
	head->next = pPos;
	pPos->next = new ListNode(3);
	pPos = pPos->next;
	pPos->next = new ListNode(4);
	pPos = pPos->next;
	pPos->next = new ListNode(5);
	pPos = pPos->next;
	pPos->next = new ListNode(6);
	pPos = pPos->next;
	pPos->next = new ListNode(-8);
	pPos = pPos->next;
	pPos->next = new ListNode(5);
	pPos = pPos->next;
	pPos->next = new ListNode(11);
	pPos = pPos->next;
	pPos->next = new ListNode(15);
	pPos = pPos->next;
	pPos->next = new ListNode(-8);
	pPos = pPos->next;
	pPos->next = new ListNode(32);*/
	//ListNode *pSortNode = palindrome.sortList(head);
	//ListNode *pInsertSort = solution.insertionSortList(head);
	//solution.reorderList(head);
	/*LRUCache cache(2);
	cache.set(2, 1);
	cache.set(2, 2);
	int iret = cache.get(2);
	cache.set(1,1);
	cache.set(4,1);
	iret = cache.get(2);

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	vector<int> pos_vec = solution.postorderTraversal(root);
	vector<int> pre_vec = solution.preorderTraversal(root);*/
	/*string src = "aaaaaaa";
	stdext::hash_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aa");
	dict.insert("a");
	bool bRet = solution.wordBreak(src, dict);
	vector<string> vec_str = solution.WordBreak(src, dict);

	int C[] = {15, 15, 15, 68, 68, 68, 62, 62, 62, 32, 32, 32, 96, 85, 85, 85, 5, 5, 5};
	int single = solution.singleNumber(C, sizeof(C) / 4);

	vector<int> ratings;*/
	/*ratings.push_back(1);
	ratings.push_back(3);
	ratings.push_back(4);
	ratings.push_back(3);
	ratings.push_back(2);
	ratings.push_back(1);*/
	/*ratings.push_back(4);
	ratings.push_back(2);
	ratings.push_back(3);
	ratings.push_back(4);
	ratings.push_back(1);*/
	/*ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(4);
	ratings.push_back(4);
	ratings.push_back(3);*/
	/*int intarra[] = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	for (int i = 0; i < sizeof(intarra) / 4; ++i)
	{
		ratings.push_back(intarra[i]);
	}
	int candyNum = solution.candy(ratings);
	int candy2Num = solution.candy2(ratings);
	int gas_array[] = {1,2};
	int cost_array[] = {2, 1};
	vector<int> gas;
	for (int i = 0; i < sizeof(gas_array) / 4; ++i)
	{
		gas.push_back(gas_array[i]);
	}
	vector<int> cost;
	for (int i = 0; i < sizeof(cost_array) / 4; ++i)
	{
		cost.push_back(cost_array[i]);
	}
	int ret = solution.canCompleteCircuit(gas, cost);*/
	/*UndirectedGraphNode node0(0);
	UndirectedGraphNode node1(1);
	UndirectedGraphNode node2(2);
	node0.neighbors.push_back(&node1);
	node0.neighbors.push_back(&node2);
	node1.neighbors.push_back(&node2);
	node2.neighbors.push_back(&node2);
	UndirectedGraphNode *pGraph = solution.cloneGraph(&node0);*/
	/*CPalindrome_Partitioning palindrome_Partitioning;
	string str_partition = "aaabaa";
	vector<vector<string>> ret_vec_str = palindrome_Partitioning.partition(str_partition);
	CPalindrome_Partitioning_II palindrome_Partitioning2;
	int min_cut = palindrome_Partitioning2.minCut(str_partition);*/
	/*CSurrounded_Regions surrounded;
	vector<vector<char>> board(5, vector<char>(5));
	board[0][0] = 'O';board[0][1] = 'X';board[0][2] = 'X';board[0][3] = 'O';board[0][4] = 'X';
	board[1][0] = 'X';board[1][1] = 'O';board[1][2] = 'O';board[1][3] = 'X';board[1][4] = 'O';
	board[2][0] = 'X';board[2][1] = 'O';board[2][2] = 'X';board[2][3] = 'O';board[2][4] = 'X';
	board[3][0] = 'O';board[3][1] = 'X';board[3][2] = 'O';board[3][3] = 'O';board[3][4] = 'X';
	board[4][0] = 'X';board[4][1] = 'X';board[4][2] = 'O';board[4][3] = 'X';board[4][4] = 'O';
	surrounded.solve(board);*/
	/*TreeNode root(1);
	TreeNode left(2);
	TreeNode right(3);
	root.left = &left;
	root.right = &right;
	CSum_Root_to_Leaf_Numbers sum_root;
	int sumNode = sum_root.sumNumbers(&root);*/
	/*CLongest_Consecutive_Sequence longestSequence;
	int temp_int[] = {-1, 1, 0};
	vector<int> vec_int;
	for (int i = 0; i < sizeof(temp_int) / 4; ++i)
	{
		vec_int.push_back(temp_int[i]);
	}
	int ret_num  = longestSequence.longestConsecutive(vec_int);*/
	/*dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");*/
	/*CWord_Ladder word_ladder;
	int leng = word_ladder.ladderLength("sand", "acne", dict);*/
	//CWord_Ladder_II word_ladder2;
	//vector<vector<string>> ret_str = word_ladder2.findLadders("sand", "acne", dict);
	int prev = GetTickCount();
	int next = GetTickCount();
	int lost = next - prev;
	return 0;
}

