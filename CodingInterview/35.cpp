#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibing;
}
void CloneNodes(ComplexListNode *pHead);
void ConnectSiblingNodes(ComplexListNode *pHead);
ComplexListNode *ReconnectNodes(ComplexListNode *pHead);

ComplexListNode *Clone(ComplexListNode *pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *TmpNode;
	while(pHead != nullptr)
	{
		TmpNode->m_nValue = pHead->m_nValue;
		TmpNode->m_pNext = pHead->m_pNext;
		pHead->m_pNext = TmpNode;
		pHead = TmpNode->m_pNext;
	}
}
void ConnectSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead->m_pNext;
	while(pHead != nullptr)
	{
		ComplexListNode *pTmp = pHead->m_pSibing;
		if(pTmp == nullptr)
		{
			pNode->m_pSibing = nullptr;
		}
		else
		{
			pNode->m_pSibing = pTmp->m_pNext;
		}
		pHead = pNode->m_pNext;
		pNode = pHead->m_pNext;
	}
}
ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pHead2 = pHead->m_pNext;
	ComplexListNode *pTmp = pHead2;
	while(pHead != nullptr)
	{
		pHead->m_pNext = pHead2->m_pNext;
		pHead = pHead2->m_pNext;
		if(pHead != nullptr)
		{
			pHead2->m_pNext = pHead->m_pNext;
			pHead2 = pHead->m_pNext;
		}
		else
		{
			pHead2->m_pNext = nullptr;
		}
	
	}
	return pTmp;
}