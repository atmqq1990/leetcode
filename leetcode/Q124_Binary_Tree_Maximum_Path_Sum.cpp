#include<iostream>
#include<algorithm>
#include <utility>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		pair<int, int> res = path(root);
		return res.first;
	}

	// first records the maxpathsum until Node root, second records the path length of Node root
	pair<int, int> path(TreeNode *root)
	{
		if (root == NULL)
			return make_pair<int, int>(INT_MIN,INT_MIN);
		if (root->left == NULL && root->right == NULL)
			return pair<int, int>(root->val,root->val);
		pair<int, int> left = path(root->left);
		pair<int, int> right = path(root->right);
		int maxsum = max(left.first,right.first);
		int dep = max(left.second,right.second);
		
		int tempsum = root->val;
		if (tempsum < 0)
		{
			if (left.second < 0)
				tempsum = max(tempsum, left.second);
			else
				tempsum += left.second;
			if (right.second < 0)
				tempsum = max(tempsum, right.second);
			else
				tempsum += right.second;
		}
		else
		{
			if (left.second > 0)
				tempsum += left.second;
			if (right.second > 0)
				tempsum += right.second;
		}

		maxsum = max(maxsum, tempsum);
		if (dep > 0)
			dep += root->val;
		else
			dep = root->val;
		return pair<int, int>(maxsum,dep);
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	TreeNode a(0);
	TreeNode b(1);
	TreeNode c(1);
	a.left = &b;
	a.right = &c;
	int res = so.maxPathSum(&a);
	cout << res << endl;

	system("pause");
	return res;
}
*/