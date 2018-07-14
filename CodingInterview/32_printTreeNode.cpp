#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void PrintTreeNode1(BinaryTreeNode *Tree)
{
	if(Tree == nullptr)
		return;
	queue<int> myque;
	myque.push(Tree->m_nValue);
	while(!myqueue.empty())
	{
		BinaryTreeNode *frontNode = myque.front();
		cout << frontNode->m_nValue << " ";
		myque.pop();
		if(frontNode->m_pLeft)
			myque.push(frontNode->m_pLeft->m_nValue);
		if(frontNode->m_pRight)
			myque.push(frontNode->m_pRight->m_pRight);
	}
	cout << endl;
}

void PrintTreeNode2(BinaryTreeNode *Tree)
{
	if(Tree == nullptr)
		return;
	int nextlevel = 0;
	int Tobeprinted = 1;
	queue<BinaryTreeNode *> myque;
	myque.push(Tree);
	while(!myque.empty())
	{
		BinaryTreeNode *TmpNode = myque.front();
		cout << TmpNode->m_nValue << " ";
		myque.pop();
		Tobeprinted--;
		if(TmpNode->m_pLeft)
		{
			myque.push(TmpNode->m_pLeft);
			nextlevel++;
		}
			
		if(TmpNode->m_pRight)
		{
			myque.push(TmpNode->m_pRight);
			nextlevel++;
		}
		if(Tobeprinted == 0)
		{
			cout << endl;
			Tobeprinted = nextlevel;
			nextlevel = 0;
		}	
		
	}
	return;
}

void PrintTreeNode3(BinaryTreeNode *Tree)
{
	if(Tree == nullptr)
		return;
	queue<BinaryTreeNode *> myque;
	int level = 1;
	int nextlevel = 0;
	int tobePrinted = 1;
	myque.push(Tree);
	while(!myque.empty())
	{
		BinaryTreeNode *TmpNode = Tree;
		cout << TmpNode->m_nValue << " ";
		tobePrinted--;
		if(level % 2 == 1)
		{
			if(TmpNode->m_pRight)
			{
				myque.push(TmpNode->m_pRight);
				nextlevel++;
			}
			if(TmpNode->m_pLeft)
			{
				myque.push(TmpNode->m_pLeft);
				nextlevel++;
			}
		}
		else
		{
			if(TmpNode->m_pLeft)
			{
				myque.push(TmpNode->m_pLeft);
				nextlevel++;
			}
			if(TmpNode->m_pRight)
			{
				myque.push(TmpNode->m_pRight);
				nextlevel++;
			}
		}
		if(tobePrinted == 0)
		{
			cout << endl;
			tobePrinted = nextlevel;
			nextlevel = 0;
			level++;
		}
	}
	return;
}

void Print(BinaryTreeNode *Tree)
{
	if(Tree == nullptr)
		return;
	stack<BinaryTreeNode *> levels[2];
	int current = 0;
	int next = 1;
	levels[current].push(Tree);
	while(!levels[0].empty() || !levels[1].empty())
	{
		BinaryTreeNode *TmpNode = levels[current].top();
		levels[current].pop();
		cout << TmpNode->m_nValue << " ";
		if(current == 0)
		{
			if(TmpNode->m_pLeft)
				levels[next].push(TmpNode->m_pLeft);
			if(TmpNode->m_pRight)
				levels[next].push(TmpNode->m_pRight);
		} 
		else
		{
			if(TmpNode->m_pRight)
				levels[next].push(TmpNode->m_pRight);
			if(TmpNode->m_pLeft)
				levels[next].push(TmpNode->m_pLeft);
		}
		if(levels[current].empty() == true)
		{
			cout << endl;
			current = 1-current;
			next = 1-next;
		}
	}
	return;
}
int main()
{
	
}