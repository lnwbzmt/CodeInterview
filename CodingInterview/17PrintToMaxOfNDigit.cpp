#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;


void Print1ToMaxOfNDigits_1(int n)
{
	int number = 1;
	int i = 0;
	while(i++ < n)
		number *= 10;
	for(i = 1; i < number; ++i)
		printf("%d\t",i);
		
}

bool Increment(char *number);
void PrintNumber(char *number);

void Print1ToMaxOfNDigits_2(int n)
{
	if(n <= 0)
		return;
	char *number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';
	while(!Increment(number))
	{
		PrintNumber(number);
	} 
	delete[] number;
}

bool Increment(char *number)
{
/*
	int i = 0;
	while(*(number+i) == '0' && *(number+i) != '\0')
		++i;
	if(*(number+i) == '\0')
		--i;
	if(i == 0 && *number == '9')
	{
		return true;
	}
	else
	{
		if(*(number+i) == '9')
		{
			*(number+i) = '0';
			--i;
			*(number+i) = '1';
		}
		else
		{
			number[i]++;
		}
		return false;
	}*/
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for(int i = nLength- 1; i >= 0; --i)
	{
		int nSum = number[i]-'0'+nTakeOver;
		if(i == nLength-1)
			nSum++;
		if(nSum >= 10)
		{
			if(i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0'+nSum;
			}
		}
		else
		{
			number[i] = '0'+nSum;
			break;
		}
	}
	return isOverflow;
}
void PrintNumber(char *number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	
	for(int i = 0; i < nLength; ++i)
	{
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if(!isBeginning0)
			printf("%c",number[i]);
	}
	printf("\t");
}
int main()
{
	Print1ToMaxOfNDigits_2(2);
	return 0;
}