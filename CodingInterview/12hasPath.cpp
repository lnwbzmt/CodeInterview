#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool hasPathCore(char* matrix,int rows,int cols,int row,int col,int pathSize,bool* visited,char* str)
{
	if(str[pathSize] == '\0')
		return true;
	bool hasPath = false;
	if(row >= 0 && row <= rows && col >= 0 && col <= cols && !visited[row*cols+col] && matrix[row*cols+col] == str[pathSize])
	{
		++pathSize;
		hasPath = hasPathCore(matrix,rows,cols,row+1,col,pathSize,visited,str) || hasPathCore(matrix,rows,cols,row,col+1,pathSize,visited,str) || hasPathCore(matrix,rows,cols,row-1,col,pathSize,visited,str) || hasPathCore(matrix,rows,cols,row,col-1,pathSize,visited,str);
		if(!hasPath)
		{
			--pathSize;
			visited[row*cols+col] = false;
		}
	}
	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;
	bool* visited = new bool[rows*cols];
	memset(visited,0,rows*cols);
	
	int pathSize = 0;
	for(int row = 0; row < rows; ++i)
	{
		for(int col = 0; col < cols; ++j)
		{
			if(hasPathCore(matrix,rows,cols,row,col,pathSize,visited,str))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{

}