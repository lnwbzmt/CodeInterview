#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

int maxProductAfterCutting_solution1(int Length)
{

	int max = 0;
	if(Length <= 1)
		return 0;
	if(Length == 3)
		return 2;
	int *products = new int[Length+1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	for(int i = 4; i <= Length; ++i)
	{
		max = 0;
		for(int j = 1; j <= i/2; ++j)
		{
			int product = products[j]*products[i-j];
			if(max < product)
				max = product;
			products[i] = max;
		}
		
	}
	max = products[Length];
	delete[] products;
	return max;
/*
	    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i = 4; i <= length; ++i)
    {
        max = 0;
        for(int j = 1; j <= i / 2; ++j)
        {
            int product = products[j] * products[i - j];
            if(max < product)
                max = product;

            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;*/
}

int main()
{
	cout << maxProductAfterCutting_solution1(4) << endl;
	return 0;
}