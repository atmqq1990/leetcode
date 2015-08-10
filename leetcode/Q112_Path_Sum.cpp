#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool has = false;
	bool hasPathSum(TreeNode* root, int sum) {
		haspath(root,0,sum);
		return has;
	}

	void haspath(TreeNode *root, int presum, int sum)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			if (presum + root->val == sum)
			{
				has = true;
				return;
			}
		}
		else
		{		
			if (root->left != NULL)
				haspath(root->left,presum+root->val,sum);
			if (has)
				return;
			if (root->right != NULL)
				haspath(root->right,presum+root->val,sum);	
		}
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	TreeNode a(-2);
	TreeNode b(-3);
	
	a.right = &b;
	
	bool res = so.hasPathSum(&a,-5);
	cout << res << endl;

	system("pause");
	return 0;
}
*/