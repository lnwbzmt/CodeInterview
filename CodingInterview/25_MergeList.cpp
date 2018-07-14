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

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *MergeList(ListNode *pHead1,ListNode *pHead2)
{
	ListNode Node;
	Node.m_nValue = 0;
	Node.m_pNext = nullptr;
	ListNode *pHead = &Node;
	ListNode *pTmp = pHead;
	if(pHead1 == nullptr)
		return pHead2;
	if(pHead2 == nullptr)
		return pHead1;
	while(pHead1 != nullptr && pHead2 != nullptr)
	{
		if(pHead1->m_nValue <= pHead2->m_nValue)
		{
			pHead->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}	
		else
		{
			pHead->m_pNext = pHead2;
			pHead2 = pHead2->m_pNext;
		}
		pHead = pHead->m_pNext;
	}
	while(pHead1)
	{
		pHead->m_pNext = pHead1;
		pHead1 = pHead1->m_pNext;
	}
	while(pHead2)
	{
		pHead->m_pNext = pHead2;
		pHead2 = pHead2->m_pNext;
	}
	return pTmp->m_pNext;
}

int main()
{
	
}