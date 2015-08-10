#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		TreeNode *pleft = root;
		TreeNode *pright = root;
		int leftheight = 0;
		int rightheight = 0;
		while (pleft)
		{
			pleft = pleft->left;
			leftheight++;
		}
		while (pright)
		{
			pright = pright->right;
			rightheight++;
		}
		if (leftheight == rightheight)
		{
			return (1 << leftheight) - 1;
		}
		return countNodes(root->left) + countNodes(root->right) + 1;
		
	}

};