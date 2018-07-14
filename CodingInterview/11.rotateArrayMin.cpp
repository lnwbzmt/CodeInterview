#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

int MinInOrder(vector<int> rotateArray)
{
	int min = rotateArray[0];
	for(auto index = rotateArray.begin()+1; index != rotateArray.end(); ++index)
	{
		if(*index < min)
			min = *index;
	}
	return min;
}
int minNumberInRotateArray(vector<int> rotateArray) {
	if(rotateArray.size() == 0)
		return 0;
	auto index1 = rotateArray.begin();
	auto index2 = rotateArray.end()-1;
	auto center = index1;
	while(*index1 >= *index2)
	{
		if(index2 - index1 == 1)
		{
			center = index2;
			break;
		}
			
		center = index1 + (index2-index1)/2;
		if(*index1 == *index2 && *index1 == *center)
		{
			return MinInOrder(rotateArray);
		}
		else
		{
			if(*index1 <= *center)
				index1 = center;
			else
			{
				if(*index2 >= *center)
					index2 = center;
			}
		}
	}
	return *center;
}

int main()
{
	vector<int> ivec{
		0,1,1,1,1
	};
	cout << minNumberInRotateArray(ivec) << endl;
	return 0;
} 