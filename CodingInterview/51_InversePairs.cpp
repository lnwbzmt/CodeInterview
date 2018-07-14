#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <cstring>
#include <limits>
using namespace std;

int reverseNum = 0;

typedef int ElementType;

/*
//归并排序
void Merge(ElementType A[],ElementType TmpArray[],int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,TmpPos;
	
	LeftEnd = Rpos-1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;
	
	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
		{
			reverseNum += (LeftEnd-Lpos+1);
			TmpArray[TmpPos++] = A[Rpos++];
		}
			
	}
	while(Lpos <= LeftEnd)
	{
		reverseNum += (RightEnd-Rpos+1);
		TmpArray[TmpPos++] = A[Lpos++];
	}
	while(Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];
	for(i = 0; i < NumElements; ++i,--RightEnd)
		A[RightEnd] = TmpArray[RightEnd];
}
void Msort(ElementType A[],ElementType TmpArray[],int Left,int Right)
{
	int Center;
	if(Left < Right)
	{
		Center = (Left + Right) / 2;
		Msort(A,TmpArray,Left,Center);
		Msort(A,TmpArray,Center+1,Right);
		Merge(A,TmpArray,Left,Center+1,Right);
	} 
} */


void Msort(int *data,int *tmp,int left,int right);
void Merge(int *data,int *tmp,int left,int rightBegin,int rightEnd);
int InversePairs(int *data,int n) 
{
	if(data == nullptr || n <= 0)
		return 0;
	reverseNum = 0;
	int *tmp = new int[n];
	Msort(data,tmp,0,n-1);
	delete[] tmp;
	return reverseNum;  
}


void Msort(int *data,int *tmp,int left,int right)
{
	int center = (left+right)/2;
	if(left < right)
	{
		Msort(data,tmp,left,center);
		Msort(data,tmp,center+1,right);
		Merge(data,tmp,left,center+1,right);
	}
}

void Merge(int *data,int *tmp,int left,int rightBegin,int rightEnd)
{
	int leftBegin = left;
	int leftEnd = rightBegin-1;
	int i = left;
	int num = rightEnd-leftBegin+1;
	while(leftBegin <= leftEnd && rightBegin <= rightEnd)
	{
		if(data[leftBegin] <= data[rightBegin])
			tmp[i++] = data[leftBegin++];
		else
		{
			reverseNum += (leftEnd-leftBegin+1);
			tmp[i++] = data[rightBegin++];
			//reverseNum++;
		}
	}
	while(leftBegin <= leftEnd)
	{
		tmp[i++] = data[leftBegin++];
		//reverseNum += (rightEnd-rightBegin+1);
	}
		
	while(rightBegin <= rightEnd)
		tmp[i++] = data[rightBegin++];
	for(int j = 0; j < num; ++j,--rightEnd)
	{
		data[rightEnd] = tmp[rightEnd];
	}
}




// ====================测试代码====================
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}

