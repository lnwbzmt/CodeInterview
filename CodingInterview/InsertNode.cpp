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
	ListNode(int val):m_nValue(val),m_pNext(nullptr){
		
	}
};
//在有序的链表中插入一个节点 
ListNode *InsertNode(ListNode *pHead,ListNode *Node)
{
	if(pHead == nullptr)
		return Node;
	ListNode *pPre = pHead;
	ListNode *pCur = pHead->m_pNext;
	
	for(;pCur != nullptr && pCur->m_nValue < Node->m_nValue; pPre = pCur,pCur = pCur->m_pNext);
	pPre->m_pNext = Node;
	Node->m_pNext = pCur;
	return pHead;
} 

int main()
{
	ListNode *L1 = new ListNode(1);
	ListNode *L2 = new ListNode(2);
	ListNode *L3 = new ListNode(3);
	ListNode *L4 = new ListNode(5);
	
	L1->m_pNext = L2;
	L2->m_pNext = L3;
	L3->m_pNext = L4;
	
	ListNode *L5 = new ListNode(4);
	L1 = InsertNode(L1,L5);
	while(L1)
	{
		cout << L1->m_nValue << endl;
		L1 = L1->m_pNext;
	}
	return 0;
}