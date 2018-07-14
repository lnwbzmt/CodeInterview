#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
}

void DeleteNode(ListNode **pListHead,ListNode* pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
		return;
	if(pToBeDeleted->m_pNext != nullptr)		//要删除的不是尾节点 
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
	}
	else
	{
		if(pToBeDeleted == *pListHead)
		{
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
			pListHead = nullptr;
		}
		else
		{
			ListNode *pTmp = *pListHead;
			while(pTmp->m_pNext != pToBeDeleted)
				pTmp = pTmp->m_pNext;
			pTmp->m_pNext = nullptr;
			delete pToBeDeleted;
		}
	}
	return;
}

int main()
{
	
}