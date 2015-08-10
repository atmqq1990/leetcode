#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		if (len == 0)
			return NULL;
		if (len == 1)
		{
			TreeNode *root = new TreeNode(preorder[0]);
			return root;
		}

		return build(preorder,0,len-1,inorder,0,len-1);
	}

	TreeNode* build(vector<int>&preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright)
	{
		if (pleft > pright)
			return NULL;
		if (pleft == pright)
		{
			TreeNode *p = new TreeNode(preorder[pleft]);
			return p;
		}
		TreeNode *root = new TreeNode(preorder[pleft]);
		
		int leftsize = 0;
		int j = ileft;
		while (j < inorder.size() && inorder[j] != preorder[pleft])
		{
			leftsize++;
			j++;
		}

		TreeNode *templeft = build(preorder,pleft+1,pleft+leftsize,inorder,ileft,ileft+leftsize-1);
		TreeNode *tempright = build(preorder,pleft+leftsize+1,pright,inorder,ileft+leftsize+1,iright);
		root->left = templeft;
		root->right = tempright;
		
		return root;
	}
};

void inorder_105(TreeNode *root)
{
	if (root)
	{
		inorder_105(root->left);
		cout << root->val << " ";
		inorder_105(root->right);
	}
}

void preorder_105(TreeNode *root)
{
	if (root)
	{
		cout << root->val << " ";
		preorder_105(root->left);
		preorder_105(root->right);
	}
}

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> pre = {1,2,4,5,3,6,7};
	vector<int> in = {4,2,5,1,6,3,7};
	cout << "orginal pre order: ";
	for (int i = 0; i < pre.size(); i++)
		cout << pre[i] << " ";
	cout << endl;
	cout << "orginal in order: ";
	for (int i = 0; i < in.size(); i++)
		cout << in[i] << " ";
	cout << endl;
	TreeNode *root = so.buildTree(pre,in);
	cout << "pre order from constructed tree: ";
	preorder_105(root);
	cout << endl;
	cout << "in order from constructed tree: ";
	inorder_105(root);
	cout << endl;

	system("pause");
	return 0;
}
*/