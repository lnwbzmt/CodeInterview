#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <cstring>
#include <map>
using namespace std;

char *DeleteRepeatingChar(char *pStr)
{
	const int num = 256;
	int *hashTable = new int[num];
	memset(hashTable,0,num*sizeof(int));
	char *pTmp = pStr;
	while(*pTmp != '\0')
	{
		hashTable[*(pTmp++)]++;
	}
	char *pStart = pStr;
	pTmp = pStr;
	while(*pStr != '\0')
	{
		if(hashTable[*pStr] > 0)
		{
			*pTmp++ = *pStr;
			hashTable[*pStr] = -1;
		}
		pStr++;
	}
	*pTmp = '\0';
	delete[] hashTable;
	return pStart;
} 

int main()
{
	char pStr[] = "google";
	printf("%s\n",DeleteRepeatingChar(pStr));
	return 0;
}