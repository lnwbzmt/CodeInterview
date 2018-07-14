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

void Permutation(char *pStr,char *pBegin);

void Permutation(char *pStr)
{
	if(pStr == nullptr)
		return;
	Permutation(pStr,pStr);
}

void Permutation(char *pStr,char *pBegin)
{
	if(*pBegin == '\0')
		printf("%s\n",pStr);
	else
	{
		for(char *Ch = pBegin; *Ch != '\0'; ++Ch)
		{
			char temp = *Ch;
			*Ch = *pBegin;
			*pBegin = temp;
			Permutation(pStr,pBegin+1);
			

			temp = *Ch;
			*Ch = *pBegin;
			*pBegin = temp;
		}
	}
}

int sum = 0;

void Permutation(int *pInt,int *pBegin);
void Judge(int *p);
int Permutation(int *pInt)
{
	if(pInt == nullptr)
		return 0;
	Permutation(pInt,pInt);
	return sum;
}

void Permutation(int *pInt,int *pBegin)
{
	if(*pBegin == 10)
	{
		Judge(pInt);
	}
	else
	{
		for(int *pTmp = pBegin; *pTmp != 10; ++pTmp)
		{
			int temp = *pTmp;
			*pTmp = *pBegin;
			*pBegin = temp;
			
			Permutation(pInt,pBegin+1);
			
			temp = *pTmp;
			*pTmp = *pBegin;
			*pBegin = temp;
		}
	}
}

void Judge(int *p)
{
	for(int i = 0; i < 8; ++i)
	{
		for(int j = i+1; j < 8; ++j)
		{
			if((i-j) == (*(p+i)-*(p+j)) || (j-i) == (*(p+i)-*(p+j)))
				sum++;
		}
	}
}
int EightQueensProblem()
{
	int ColumnIndex[9] = {
		0,1,2,3,4,5,6,7,10
	};
	return Permutation(ColumnIndex);
}

int main()
{
	cout << EightQueensProblem() << endl;
	return 0;
}