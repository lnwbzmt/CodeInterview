#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

int  NumberOf1(int n) {
         int num = 0;
         if(n >= 0)
         {
             while(n)
             {
                 if(n & 1)
                     num++;
                 n >>= 1;
             }
         }
         else
         {
             n = abs(n);
             while(n)
             {
                 if(n & 1)
                     num++;
                 n >>= 1;
             }
             num++;
         }

	return num;
}
int main()
{
	cout << NumberOf1(3)<< endl;
	return 0;
}