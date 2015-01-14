// Source : https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
// Author : zheng yi xiong 
// Date   : 2015-01-07

/********************************************************************************** 
* 
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

* The largest rectangle is shown in the shaded area, which has area = 10 unit.

* For example,
* Given height = [2,1,5,6,2,3],
* return 10.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		stack<int> height_pos;
		height.push_back(0);
		int max_area = 0, temp_pos = 0, temp_area = 0;
		for (int i = 0; i < height.size(); )
		{
			if (height_pos.empty() || height[i] > height[height_pos.top()])
			{
				height_pos.push(i ++);
			}
			else
			{
				temp_pos = height_pos.top();
				height_pos.pop();
				temp_area = height_pos.empty() ? (i * height[temp_pos]) : ((i - height_pos.top() - 1) * height[temp_pos]);
				max_area = max(max_area, temp_area);
			}
		}


		return max_area;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 6;
	int maxNumber = 10;
	if ( argc > 2) {
		n = _wtoi(argv[1]);
		maxNumber = _wtoi(argv[2]);
	}

	vector<int> height(n, 0);
	srand(time(0));
	for(int i = 0; i < n; ++i) {
		height[i] = rand() % maxNumber;
	}

	cout<<"bar height:\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<' '<<height[i];
	}
	cout<<endl;

	Solution so;
	int area = so.largestRectangleArea(height);

	cout<<"max area = "<<area<<endl;

	system("pause");

	return 0;
}

