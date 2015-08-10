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

	vector<TreeNode*> generateTrees(int n) {
		return subtrees(n,1);
	}

	vector<TreeNode*> subtrees(int nodenum, int startvalue)
	{
		vector<TreeNode*> rootve;
		if (nodenum == 0)
		{
			rootve.push_back(NULL);
			return rootve;
		}
		if (nodenum == 1)
		{
			TreeNode *p = new TreeNode(startvalue);
			rootve.push_back(p);
			return rootve;
		}
		for (int i = 0; i < nodenum; i++)
		{
			vector<TreeNode*> leftvec = subtrees(i,startvalue);
			vector<TreeNode*> rightvec = subtrees(nodenum-1-i,startvalue+i+1);
			for (int j = 0; j < leftvec.size(); j++)
			{
				for (int k = 0; k < rightvec.size(); k++)
				{
					TreeNode* root = new TreeNode(startvalue+i);
					root->left = leftvec[j];
					root->right = rightvec[k];
					rootve.push_back(root);
				}
			}
		}

		return rootve;
	}

};


void inorder_show95(TreeNode * root)
{
	if (root != NULL)
	{
		cout << root->val<<" ";
		inorder_show95(root->left);
		inorder_show95(root->right);
	}

}

/*
int main(int argc, char **args)
{
	Solution so;
	vector<TreeNode*> res = so.generateTrees(3);
	for (int i = 0; i < res.size(); i++)
	{
		inorder_show95(res[i]);
		cout << endl;
	}

	system("pause");
	return 0;
}
*/