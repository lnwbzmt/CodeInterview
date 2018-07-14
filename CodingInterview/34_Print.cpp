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
void print(BinaryTreeNode *TreeNode,int n,vector<BinaryTreeNode *> vecNode);
void Print(BinaryTreeNode *Tree,int n)
{
	if(Tree == nullptr)
		return;
	if(Tree->m_nValue > n)
		return;
	vector<BinaryTreeNode *> vecNode{
		Tree
	};
	if(Tree->m_pLeft)
		print(Tree->m_pLeft,n-Tree->m_nValue,vecNode);
	if(Tree->m_pRight)
		print(Tree->m_pRight,n-Tree->m_nValue,vecNode);
	return;
}

void print(BinaryTreeNode *TreeNode,int n,vector<BinaryTreeNode *> vecNode)
{
	if(n < 0)
		return;
	if(n == 0)
	{
		for(auto i : vecNode)
			cout << i->m_nValue << " ";
		cout << endl;
		return;
	}
	if(TreeNode->m_nValue > n)
		return;
	vecNode.push_back(TreeNode);
	if(TreeNode->m_pLeft)
		print(TreeNode->m_pLeft,n-TreeNode->m_nValue,vecNode);
	if(TreeNode->m_pRight)
		print(TreeNode->m_pRight,n-TreeNode->m_nValue,vecNode);
	return;
			
}

int main()
{
	BinaryTreeNode *Node;
	Node->m_nValue = 3;
	Node->m_pLeft = nullptr;
	Node->m_pRight = nullptr;
	
	Print(Node,3);
	return 0;
}