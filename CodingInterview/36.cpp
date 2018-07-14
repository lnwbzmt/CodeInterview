#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConverTreeToList(BinaryTreeNode *pTree)
{
	if(pTree == nullptr)
		return nullptr;
	BinaryTreeNode *pHead = nullptr;
	InOrderTraverse(pTree,pHead);
	return pHead;
} 
BinaryTreeNode *pCur = nullptr;
BinaryTreeNode *pLast = nullptr;
BinaryTreeNode *pHead = nullptr;
void InOrderTraverse(BinaryTreeNode *pNode)
{
	if(pNode == nullptr)
		return;
	InOrderTraverse(pNode->m_pLeft);
	pCur = pNode;
	if(pLast != nullptr)
	{
		pLast->m_pRight = pCur;
		pCur->m_pLeft = pLast;
	}
	else
	{
		pHead = pCur;
	}
	pLast = pCur;
	InOrderTraverse(pNode->m_pRight);
	
}