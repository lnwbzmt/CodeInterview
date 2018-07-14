#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
/*
double Power(double base, int exponent) 
{
	double result = 1.0;
    if(exponent > 0)
    {
    	for(int i = 0; i < exponent; ++i)
    	{
	    	result *= base;
	    }
    }
    else
    {
    	try{
	    	for(int i = 0; i < abs(exponent); ++i)
	    	{
	    		result *= base;
	    	}
	    	result = 1/result;
	    }
	    catch(...)
	    {
    		cout << "error" << endl;
    	}
    }
    return result; 
}*/


bool g_InvaildInput = false;
bool equal(double num1,double num2)
{
	if((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001))
		return true;
	return false;
}
double PoweWithUnsignedExponent(double base,unsigned int exponent)
{
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;
	double result = PoweWithUnsignedExponent(base,exponent>>1);
	result *= result;
	if(exponent & 0x01)
		result *= base;
	return result;
}
double Power(double base,int exponent)
{

	g_InvaildInput = false;
	if(equal(base,0.0) && exponent < 0)
	{
		g_InvaildInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)exponent;
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PoweWithUnsignedExponent(base,absExponent);
	if(exponent < 0)
		result = 1.0/result;
	return result;
/*
	         g_InvaildInput = false;
        if(equal(base,0.0) && exponent <= 0)
        {
            g_InvaildInput = true;
            return 0.0;            
        }
        
        unsigned int absexponent = (unsigned int)exponent;
        if(exponent < 0)
            absexponent = (unsigned int)(-exponent);
        double result = 1.0;
        for(int i = 0 ; i < absexponent; ++i)
        {
            result *= base;
        }
        if(exponent < 0)
            result = 1.0 / result;
        return result;*/
    
} 

int main()
{
	int base,exponent;
	while(cin >> base >> exponent)
		cout << Power(base,exponent) << endl;
	return 0;
} 