#include <string.h>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己写的 
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
	if(pre.size() == 0 || vin.size() == 0)
		return nullptr;
	int val = pre[0];
	int count_L = 0,count_R = 0,i;
	TreeNode *T = new TreeNode(val);
	vector<int> pre_L,pre_R,vin_L,vin_R;
	pre_L.resize(pre.size());
	pre_R.resize(pre.size());
	vin_L.resize(vin.size());
	vin_R.resize(vin.size());
	for(i = 0; i < vin.size(); ++i)
	{
		if(vin[i] == val)
		{
			break;
		}
	} 
	pre_L.resize(i);
	vin_L.resize(i);
	pre_R.resize(vin.size()-1-i);
	vin_R.resize(vin.size()-1-i);
	for(int j = 0,q = 1; j < i; ++j)
	{
		vin_L[j] = vin[j];
		pre_L[j] = pre[q++];
	}
	for(int j = i+1,q = 0; j < vin.size(); ++j)
	{
		vin_R[q] = vin[j];
		pre_R[q++] = pre[j];
	}
	T->left = reConstructBinaryTree(pre_L,vin_L);
	T->right = reConstructBinaryTree(pre_R,vin_R);
	return T;
}
//书上的代码
TreeNode *Construct(int *preorder,int *inorder,int length)
{
	if(preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
} 
TreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
	int rootValue = startPreorder[0];
	TreeNode* root = new TreeNode();
	root->val = rootValue;
	root->left = root->right = nullptr;
	
	if(startPreorder == endPreorder)
	{
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw exception("Invalid input."); 
	}
	int* rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid input.");
	int leftLength = rootInorder-startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0)
	{
		root->left = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->right = ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
	}
}
//前序遍历
void PreOrderTraverse(TreeNode *T)
{
	if(T == nullptr)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);
	return; 
} 

void InOrderTraverse(TreeNode *T)
{
	if(T == nullptr)
		return;
	InOrderTraverse(T->left);
	cout << T->val << " ";
	InOrderTraverse(T->right);
	return;
}
void PostOrderTraverse(TreeNode *T)
{
	if(T == nullptr)
		return;
	PostOrderTraverse(T->left);
	PostOrderTraverse(T->right);
	cout << T->val << " ";
	return;
}
int main()
{
	vector<int> pre{
		1,2,4,7,3,5,6,8
	};
	vector<int> vin{
		4,7,2,1,5,3,8,6
	};
	TreeNode *T = reConstructBinaryTree(pre,vin);
	PreOrderTraverse(T);
	cout << endl;
	InOrderTraverse(T);
	cout << endl;
	PostOrderTraverse(T);
	cout << endl;
	return 0;
} 