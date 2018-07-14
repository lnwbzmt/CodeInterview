#include <string.h>
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <exception>
using namespace std;

int Fibonacci(int n)
{
	int result[] = {
		0,1
	};
	if(n <= 1)
		return result[n];		
	int tmp2=1,tmp1=0,sum = 0;
	for(int i = 2; i <= n; ++i)
	{
		sum = tmp1+tmp2;
		tmp1 = tmp2;
		tmp2 = sum;
	}
	return sum;
	
}

int jumpFloorII(int number)
{
	if(number <= 2)
		return number;
	int sum = 2,sumMinusOne = 2;
	for(int i = 3; i <= number; ++i)
	{
		sum += sumMinusOne;
		sumMinusOne = sum;
	} 
	return sum;
} 
int main()
{
	cout <<Fibonacci(39) <<endl;
}