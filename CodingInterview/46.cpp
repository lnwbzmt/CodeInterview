#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

string int2str(const long long int &int_temp);
int translate(const string &str);
int translate(long long int num)
{
	if(num < 0)
		return -1;
	string str = int2str(num);
	return translate(str);	
} 

string int2str(const long long int &int_temp)
{
	string str;
	stringstream stream;
	stream << int_temp;
	stream >> str;
	return str;
}

int translate(const string &str)
{

	int count = 0,tmp;
	int length = str.length();
	int *cnt = new int[length];
	for(int i = str.length()-1; i >= 0; --i)
	{
		count = 0;
		if(i == str.length()-1)
		{
			count = 1;
		}
		else
		{
			count = cnt[i+1];
			tmp = (str[i]-'0')*10+(str[i+1]-'0');
			if(tmp >= 10 && tmp <= 25)
			{
				if(i < str.length()-2)
				{
					count += cnt[i+2];
				}
				else
					count += 1;
			}
		}
		cnt[i] = count;
	}
	count = cnt[0];
	delete[] cnt;
	return count; 
/*
	    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for(int i = length - 1; i >= 0; --i)
    {
        count = 0;
         if(i < length - 1)
               count = counts[i + 1];
         else
               count = 1;

        if(i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;*/
}

int main()
{
	int n = 12258;

	cout << translate(n) << endl;
	return 0;
}