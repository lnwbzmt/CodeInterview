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

ListNode *FindKthTail(ListNode *pListHead,unsigned int k)
{
	if(pListHead == nullptr || k = 0)
		return nullptr;
	ListNode *pPre = pListHead;
	ListNode *pBehind = pListHead;
	for(int i = 0; i < k-1 && pPre != nullptr; ++i)
	{
		pPre = pPre->m_pNext; 
	}
	if(i != k-1)
		return nullptr;
	while(pPre->m_pNext != nullptr)
	{
		pPre = pPre->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}

int main()
{
	
}