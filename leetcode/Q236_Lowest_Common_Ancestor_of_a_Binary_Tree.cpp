#include<iostream>
#include<vector>
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
	vector<TreeNode*> path1;
	vector<TreeNode*> path2;
	bool find;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		find = false;
		findpath(path1, root, p);
		find = false;
		findpath(path2, root, q);
		int i = 0;
		int endi = min(path1.size(), path2.size());
		while (i < endi)
		{
			if (path1[i] != path2[i])
				break;
			i++;
		}
		return path1[i - 1];
	}

	void findpath(vector<TreeNode*>&pre, TreeNode *current, TreeNode*target)
	{
		if (current == NULL)
			return;

		if (find)
			return;
		if (current == target)
		{
			pre.push_back(current);
			find = true;
			return;
		}
		pre.push_back(current);
		findpath(pre, current->left, target);
		if (find)
			return;
		findpath(pre, current->right, target);
		if (find)
			return;

		pre.pop_back();
	}
};