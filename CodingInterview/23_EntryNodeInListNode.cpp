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

/*
struct IHttp
{
	virtual int SetProxy(const char *pszProxy) = 0;
	virtual int SendRequest(const char *pszRsp) = 0;
};

class CHttpCurl:public IHttp
{
	public:
	int SetProxy(const char* pszProxy)
	{
		m_strProxy = pszProxy;
		return 0;
	}
	int SendRequest(const char *pszRsp)
	{
		return 0;
	}
	private:
	string m_strProxy;
};

int main()
{
	IHttp *pHttp = new CHttpCurl;
	pHttp->SetProxy("192.168.0.1");
	pHttp->SendRequest("http://");
	delete pHttp;
	return 0;
}*/

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};


ListNode* MeetingNode(ListNode* pHead)
{
	if(pHead == nullptr || pHead->m_pNext == nullptr)
		return nullptr;
	ListNode *pFast = pHead->m_pNext;
	ListNode *pSlow = pHead;
	pFast = pFast->m_pNext;
	while(pFast && pFast->m_pNext)
	{
		if(pSlow == pFast)
			return pSlow;
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if(pFast->m_pNext)
		{
			pFast = pFast->m_pNext;
		}
		else
			return nullptr;
	}
}
ListNode* EntryNodeOfLoop(ListNode *pHead)
{
	ListNode *Meeting = MeetingNode(pHead);
	if(Meeting == nullptr)
		return nullptr;
	int NumOfNodes = 1;
	ListNode *pTmp = Meeting;
	while(pTmp->m_pNext != Meeting)
	{
		pTmp = pTmp->m_pNext;
		NumOfNodes++;
	}
	ListNode *pFast = pHead,*pSlow = pHead;
	while(NumOfNodes--)
	{
		pFast = pFast->m_pNext;
	}
	while(pFast != pSlow)
	{
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
	}
	return pSlow;
}

int main()
{

	return 0;
}