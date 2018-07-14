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

class CharStatistics
{
	public:
	CharStatistics():Index(0)
	{
		for(int i = 0; i < 256; ++i)
		{
			ocurrance[i] = -1;
		}
	}
	void Insert(char ch)
	{
		if(ocurrance[i] == -1)
			ocurrance[i] = i;
		else
		{
			if(ocurrance[i] >= 0)
				ocurrance[i] = -2;
		}
	}
	char FirstAppearingOnce()
	{
		int ch;
		int MinIndex = numeric_limits<int>::max();
		for(int i = 0; i < 256; ++i)
		{
			if(ocurrance[i] >= 0 && ocurrance[i] < MinIndex)
			{
				ch = (char)i;
				MinIndex = ocurrance[i];
			}
		}
		return ch;
	}
	private:
	int ocurrance[256];
	int Index;
}