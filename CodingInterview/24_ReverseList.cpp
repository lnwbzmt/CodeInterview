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

ListNode *ReverseList(ListNode *pHead)
{
	if(pHead == nullptr || pHead->m_pNext == nullptr)
		return pHead;
	ListNode *pBefore = nullptr;
	ListNode *pCur = pHead;
	ListNode *pLater = pCur->m_pNext;
	//ListNode *pTmp = nullptr;
	while(pLater != nullptr)
	{
		//pTmp = pLater;
		pCur->m_pNext = pBefore;
		pBefore = pCur;
		pCur = pLater;
		pLater = pLater->m_pNext;
	}
	pCur->m_pNext = pBefore;
	return pCur;
}


