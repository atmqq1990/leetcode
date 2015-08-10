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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return NULL;
		return build(nums,0,len-1);
	}

	TreeNode* build(vector<int>&nums, int left, int right)
	{
		if (left > right)
			return false;
		if (left == right)
		{
			TreeNode *p = new TreeNode(nums[left]);
			return p;
		}
		int mid = (left + right) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		TreeNode *templeft = build(nums,left,mid-1);
		TreeNode *tempright = build(nums,mid+1,right);
		root->left = templeft;
		root->right = tempright;
		return root;
	}
};

void inorder_108(TreeNode *root)
{
	if (root)
	{
		inorder_108(root->left);
		cout << root->val << " ";
		inorder_108(root->right);
	}
}

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	for (int i = 1; i <= 9; i++)
		v.push_back(i);
	TreeNode *root = so.sortedArrayToBST(v);
	inorder_108(root);
	cout << endl;

	system("pause");
	return 0;
}
*/