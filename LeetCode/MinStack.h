#pragma once

#define MAX_DATA 128

class MinStack
{
public:
	MinStack(void);
	~MinStack(void);

	void push(int x);
	void pop();
	int top();
	int getMin();
private:
	typedef struct _stack_node_
	{
		int			data[MAX_DATA];
		struct _stack_node_ *pNext;
	}STACK_NODE;

	typedef struct _min_node_
	{
		int			data[MAX_DATA];
		int			count[MAX_DATA];
		struct _min_node_ *pNext;
	}MIN_NODE;

	STACK_NODE		*m_pVecNode;
	int				m_nodeIndex;

	MIN_NODE		*m_pVecOrder;
	int				m_orderIndex;
};
