#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

/*
bool Func(vector<int> ivec1,vector<int> ivec2)
{
	auto it1 = ivec1.begin();
	auto it2 = ivec2.begin();
	stack<int> istack;
	istack.push(*it1++);
	bool flag = true;
	
	while(it1 != ivec1.end() && it2 != ivec2.end())
	{
		if(istack.size() > 0)
		{
			if(istack.top() == *it2)
			{
				istack.pop();
				it2++;
			}
			else
				istack.push(*it1++);
		}
		else
		{
			istack.push(*it1++);
		}
	}
	if(it2 == ivec2.end())
		return true;
	while(istack.size() > 0 && it2 != ivec2.end())
	{
		if(istack.top() != *it2)
		{
			return false;
		}
		else
		{
			it2++;
			istack.pop();
		}
	}
	if(istack.size() == 0 && it2 == ivec2.end())
		return true;
	return false;
	
}*/

bool IsPopOrder(vector<int> ivec1,vector<int> ivec2)
{
	if(ivec1.size() == 0 || ivec2.size() == 0)
		return false;
	auto it1 = ivec1.begin();
	auto it2 = ivec2.begin();
	stack<int> istack;
	istack.push(*it1++);
	bool flag = true;
	
	while(it1 != ivec1.end() && it2 != ivec2.end())
	{
		if(istack.size() > 0)
		{
			if(istack.top() == *it2)
			{
				istack.pop();
				it2++;
			}
			else
				istack.push(*it1++);
		}
		else
		{
			istack.push(*it1++);
		}
	}
	if(it2 == ivec2.end())
		return true;
	while(istack.size() > 0 && it2 != ivec2.end())
	{
		if(istack.top() != *it2)
		{
			return false;
		}
		else
		{
			it2++;
			istack.pop();
		}
	}
	if(istack.size() == 0 && it2 == ivec2.end())
		return true;
	return false;
	
}
// ====================测试代码====================
void Test(const char* testName, vector<int> ivec1,vector<int> ivec2, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder(ivec1, ivec2) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, true);
}

void Test2()
{
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, true);
}

void Test3()
{
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop,false);
}

void Test4()
{
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, false);
}

// push和pop序列只有一个数字
void Test5()
{
    vector<int> push = {1};
    vector<int> pop = {2};

    Test("Test5", push, pop, false);
}

void Test6()
{
    vector<int> push = {1};
    vector<int> pop = {1};

    Test("Test6", push, pop, true);
}

/*
void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}*/
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    //Test7();

    return 0;
}