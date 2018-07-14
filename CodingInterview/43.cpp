#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool g_InvalidInput = false;
int calculate(int digits);
int digitAtIndex(int index,int digits);
int digitAtIndex(int index)
{
	if(index <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;
	int digits = 1;
	while(true)
	{
		int numbers = calculate(digits);
		if(index <= numbers * digits)
		{
			return digitAtIndex(index,digits);
		}
		index -= numbers * digits;
		digits++;
	}
	return -1;
} 
int calculate(int digits)
{
	if(digits < 0)
		return 0;
	if(digits == 1)
		return 10;
	else
	{
		return 9*pow(10,digits-1);
	}
}
int digitAtIndex(int index,int digits)
{
	int beginNum = 0;
	if(digits == 1)
	{
		beginNum = 0;
	}
	else
	{
		beginNum = pow(10,digits-1);
	}
	int num = beginNum + (index / digits);
	int indexFromBegin = index % digits;
	int indexFromEnd = digits - indexFromBegin;
	indexFromEnd--;
	while(indexFromEnd--)
		num /= 10;
	return num % 10;
}

int main()
{
	int num = 0;
	while(cin >> num)
	{
		cout << digitAtIndex(num) << endl;
	}
	return 0;
}