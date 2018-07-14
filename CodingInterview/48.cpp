#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <cstring>
using namespace std;
bool isUgly(int num)
{
	while(num % 2 == 0)
		num /= 2;
	while(num % 5 == 0)
		num /= 5;
	while(num % 3 == 0)
		num /= 3;
	return (num == 1)?true:false;
}
int Min(int n1,int n2,int n3)
{
	int n = (n1 < n2)?n1:n2;
	n = (n < n3)?n : n3;
	return n;
}
int GetUglyNumber_Solution2(int index)
{
	if(index <= 0)
		return 0;
	int *nUglyNum = new int[index];
	nUglyNum[0] = 1;
	int nextIndex = 1;
	int *nUglyindex2 = nUglyNum;
	int *nUglyindex3 = nUglyNum;
	int *nUglyindex5 = nUglyNum;
	int nNum = 1;
	while(nNum < index)
	{
		int nMin = Min(*nUglyindex2*2,*nUglyindex3*3,*nUglyindex5*5);
		nUglyNum[nextIndex] = nMin;
		nextIndex++;
		
		while(*nUglyindex2 * 2 <= nMin)
			++nUglyindex2;
		while(*nUglyindex3 * 3 <= nMin)
			++nUglyindex3;
		while(*nUglyindex5 * 5 <= nMin)
			++nUglyindex5;
		nNum++;
	}
	int nMin = nUglyNum[nNum-1];
	delete[] nUglyNum;
	return nMin;
} 

// ====================²âÊÔ´úÂë====================
void Test(int index, int expected)
{
/*
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");*/

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
/*
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);*/
	int index;
	while(cin >> index)
		cout << GetUglyNumber_Solution2(index) << endl; 
    return 0;
}

