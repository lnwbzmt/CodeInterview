#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int FindGreatestSumOfSubArray(int *pData,int nLength)
{
	if(pData == nullptr || nLength <= 0)
		return 0;
	int sum = 0;
	int maxSum = 0x80000000;
	for(int i = 0; i < nLength; ++i)
	{
		int tmp = pData[i]+sum;
		if(pData[i] >= tmp)
		{
			sum = pData[i];
		}
		else
		{
			sum += pData[i];
		}
		if(sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}
int main()
{
	int a[] = {
		-2, -8, -1, -5, -9
	};
	cout << FindGreatestSumOfSubArray(a,sizeof(a)/sizeof(int)) << endl;
	return 0;
}