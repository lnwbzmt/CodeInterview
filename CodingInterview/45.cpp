#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

    bool cmp(const int & n1,const int &n2)
    {
        string a = to_string(n1);
        a += to_string(n2);
        string b = to_string(n2);
        b += to_string(n1);
        return a < b;
    }
    string PrintMinNumber(vector<int> numbers) {
        string str = "";
        if(numbers.size() == 0)
            return "";
        sort(numbers.begin(),numbers.end(),cmp);

        for(auto i : numbers)
            str += to_string(i);
        return str;
    }


int main()
{

	return 0;
}