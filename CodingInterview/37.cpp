#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void Serialize(BinaryTreeNode *pRoot,ostream &stream)
{
	if(pRoot == nullptr)
	{
		stream << "$,";
		return;
	}
	stream << pRoot->m_nValue << ",";
	Serialize(pRoot->m_pLeft,stream);
	Serialize(pRoot->m_pRight,stream);
}

bool ReadStream(istream &stream,int *number)
{
	if(stream.eof())
		return false;
	char c[32];
	c[0] = '\0';
	int i = 0;
	char ch;
	stream >> ch;
	while(!stream.eof() && ch != ',')
	{
		c[i++] = ch;
		stream >> ch;
	}
	bool isNumeric = false;
	if(i > 0 && c[0] != '$')
	{
		*number = atoi(c);
		isNumeric = true;
	}
	return isNumeric;
}

void DesignTree(BinaryTreeNode **Tree,istream &stream)
{
	int val;
	while(ReadStream(stream,&val))
	{
		*Tree->m_nValue = val;
		*Tree->m_pLeft = nullptr;
		*Tree->m_pRight = nullptr;
		
		DesignTree((*Tree)->m_pLeft,stream);
		DesignTree((*Tree)->m_pRight,stream);
	}
}