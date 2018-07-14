#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxValue_solution1(const int* array,int rows,int cols)
{
	if(array == nullptr || rows <= 0 || cols <= 0)
		return 0;
	int maxVal;
	int **maxValues = new int* [rows];
	for(int i = 0; i < rows; i++)
	{
		maxValues[i] = new int[cols];
	}
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			int left = 0; 
			int high = 0;
			if(i > 0)
				high = maxValues[i-1][j];
			if(j > 0)
				left = maxValues[i][j-1];
			maxValues[i][j] = max(left,high) + array[i*cols+j];
		}
	}
	maxVal = maxValues[rows-1][cols-1];
	for(int i = 0 ;i < rows; ++i)
		delete[] maxValues[i];
	delete[] maxValues;
	return maxVal;
/*
	int val[rows][cols] = {
		0
	};
	int tmp = 0;
	for(int i = 0; i < rows; ++i)
	{
		tmp = 0;
		for(int j = 0; j < cols; ++j)
		{
			tmp = array[i*cols + j];
			if(i > 0 && j > 0)
			{
				val[i][j] = max(val[i-1][j],val[i][j-1]) + tmp;
			}
			else
			{
				if(i == 0 && j == 0)
					val[i][j] = tmp;
				else
				{
					if(i == 0)
						val[i][j] = val[i][j-1] + tmp;
					else
						val[i][j] = val[i-1][j] + tmp;
				}
			}
		}
	}
	return val[rows-1][cols-1];*/
}

// ====================测试代码====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
    if(getMaxValue_solution1(values, rows, cols) == expected)
        std::cout << testName << ": solution1 passed." << std::endl;
    else
        std::cout << testName << ": solution1 FAILED." << std::endl;

/*
    if(getMaxValue_solution2(values, rows, cols) == expected)
        std::cout << testName << ": solution2 passed." << std::endl;
    else
        std::cout << testName << ": solution2 FAILED." << std::endl;*/
}

void test1()
{
    // 三行三列
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // 空指针
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}