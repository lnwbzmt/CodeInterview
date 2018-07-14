#include <iostream>
#include <vector>
#include <functional> 

using namespace std;

typedef multiset<int,greater<int>>  intSet;

void GetLeastNumbers(const vector<int> &data,intSet &leastNumbers,int k)
{
	leastNumbers.clear();
	
	auto iter = data.begin();
	for(;iter != data.end(); ++iter)
	{
		if(leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
		else
		{
			auto iterGreatest = leastNumbers.begin();
			if(*iterGreatest > *iter)
			{
				leastNumbers.erase(*iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

