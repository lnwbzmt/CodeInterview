#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
} ;

vector<int> PrintListReversingly_Iteratively(ListNode* pHead)
{
	vector<int> ivec;
	stack<ListNode*> list;
	ListNode *tmpNode;
	if(pHead == nullptr)
		return ivec;
	while(pHead != nullptr)
	{
		list.push(pHead);
		pHead = pHead->m_pNext;
	}
	while(!(list.empty()))
	{
		tmpNode = list.top();
		cout << tmpNode->m_nKey << endl;
		ivec.push_back(tmpNode->m_nKey);
		list.pop();
	}
	return ivec;
}

int main()
{
	ListNode *pHead = new ListNode();
	pHead->m_nKey = 1;
	pHead->m_pNext = nullptr;
	ListNode *p1 = new ListNode();
	p1->m_nKey = 2;
	p1->m_pNext = nullptr;
	pHead->m_pNext = p1;
	PrintListReversingly_Iteratively(pHead);
	return 0;
}