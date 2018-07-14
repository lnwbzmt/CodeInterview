#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

int movingCountCore(int threshold,int rows,int cols,int row,int col,bool* visited)
{
	int sum = 0;
	int tmp = row;
	int count = 0;
	while(tmp != 0)
	{
		sum += tmp%10;
		tmp /= 10;
	}
	tmp = col;
	while(tmp != 0)
	{
		sum += tmp%10;
		tmp /= 10;
	}
	if(row >= 0 && row < rows && col >= 0 && col < cols && sum <= threshold && !visited[row*cols+col])
	{
		visited[row*cols+col] = true;
		count =1+movingCountCore(threshold,rows,cols,row+1,col,visited)+movingCountCore(threshold,rows,cols,row-1,col,visited)+movingCountCore(threshold,rows,cols,row,col+1,visited)+movingCountCore(threshold,rows,cols,row,col-1,visited);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if(threshold < 2 || rows < 1 || cols < 1)
		return 0;
	int count = 0;
	bool* visited = new bool[rows*cols];
	memset(visited,0,rows*cols);
	return movingCountCore(threshold,rows,cols,0,0,visited);
}


int main()
{
	cout  << movingCount(2,1,2) << endl;
	return 0;
}