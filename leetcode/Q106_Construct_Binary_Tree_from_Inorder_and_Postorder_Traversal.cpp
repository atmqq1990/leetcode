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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int len = inorder.size();
		if (len == 0)
			return NULL;
		if (len == 1)
		{
			TreeNode *p = new TreeNode(inorder[0]);
			return p;
		}
		return build(inorder,0,len-1,postorder,0,len-1);
	}

	TreeNode *build(vector<int>&inorder, int ileft, int iright, vector<int>&postorder, int pleft, int pright)
	{
		if (pleft > pright)
			return NULL;
		if (pleft == pright)
		{
			TreeNode *p = new TreeNode(inorder[ileft]);
			return p;
		}
		TreeNode *root = new TreeNode(postorder[pright]);
		
		int leftsize = 0;
		int j = ileft;
		while (j < inorder.size() && inorder[j] != postorder[pright])
		{
			leftsize++;
			j++;
		}

		TreeNode *templeft = build(inorder,ileft,ileft+leftsize-1,postorder,pleft,pleft+leftsize-1);
		TreeNode *tempright = build(inorder,ileft+leftsize+1,iright,postorder,pleft+leftsize,pright-1);
		root->left = templeft;
		root->right = tempright;
		return root;
	}
};

void inorder_106(TreeNode *root)
{
	if (root)
	{
		inorder_106(root->left);
		cout << root->val << " ";
		inorder_106(root->right);
	}
}

void postorder_106(TreeNode *root)
{
	if (root)
	{
		postorder_106(root->left);
		postorder_106(root->right);
		cout << root->val << " ";
	}
}

/*
int main(int argc, char **args)
{
	Solution so;
	
	vector<int> in = {4,2,5,1,6,3,7};
	vector<int> post = {4,5,2,6,7,3,1};
	cout << "orginal in order: ";
	for (int i = 0; i < in.size(); i++)
		cout << in[i] << " ";
	cout << endl;
	cout << "orginal post order: ";
	for (int i = 0; i < post.size(); i++)
		cout << post[i] << " ";
	cout << endl;
	TreeNode *root = so.buildTree(in,post);
	cout << "in order from constructed tree: ";
	inorder_106(root);
	cout << endl;
	cout << "post order from constructed tree: ";
	postorder_106(root);
	cout << endl;

	system("pause");
	return 0;
}
*/