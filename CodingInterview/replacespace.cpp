#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

void replaceSpace(char *str,int length)
{
/*
	int newlen,oldlen,count = 0;
	if(str == NULL)
		return;
	for(int i = 0; str[i] != '\0'; ++i)
	{
		oldlen++;
		if(str[i] == ' ')
			count++;
	}
	newlen = oldlen+2*count;
	if(newlen + 1 > length)
		return;
	char *newstr;
	newstr = (char *)malloc(sizeof(newlen));
	*(newstr+newlen) = '\0';
	//*(str+newlen) = '\0';
	for(int i = (newlen-1),j = (oldlen-1); i >= 0 && j >= 0; --i,--j)
	{
		if(*(str+j) != ' ')
			*(newstr+i) = *(str+j);
		else
		{
			*(newstr+i) = '0';
			--i;
			*(newstr+i) = '2';
			--i;
			*(newstr+i) = '%';
		}
	}
	strcpy(str,newstr);
	free(newstr);*/
	
	
	

	int i = 0,oldlen = 0,newlen = 0,count = 0;
	if(str == NULL || length <= 0)
		return;
	for(i = 0; str[i] != '\0'; ++i)
	{
		oldlen++;
		if(str[i] == ' ')
			count++;
	}
	char *p1 = str+oldlen;
	char *p2 = str+oldlen+2*count;
	
	while(p2>p1)
	{
		if(*p1 != ' ')
			*p2-- = *p1;
		else
		{
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';
			
		}
		p1--;
	}
	
}
int main()
{
	char a[] = " we are  happy ";
	replaceSpace(a,30);
	cout << a << endl;
	return 0;
}