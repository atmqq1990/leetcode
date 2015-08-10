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
	void recoverTree(TreeNode* root) {
		TreeNode *first = NULL;
		TreeNode *second = NULL;
		TreeNode *pre = NULL;
		TreeNode *cur = root;
		TreeNode *temp;

		while (cur != NULL)
		{
			if (cur->left == NULL)
			{
				if (pre != NULL && pre->val > cur->val)
				{
					if (first == NULL)
						first = pre;
					second = cur;
				}
				pre = cur;
				cur = cur->right;
			}
			else
			{
				temp = cur->left;
				while (temp->right != NULL && temp->right != cur)
					temp = temp->right;
				if (temp->right != cur)
				{
					temp->right = cur;
					cur = cur->left;
				}
				else
				{
					if (pre != NULL && pre->val > cur->val)
					{
						if (first == NULL)
							first = pre;
						second = cur;
					}
					temp->right = NULL;
					pre = cur;
					cur = cur->right;
				}
			}
		}

		if (first && second)
		{
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}

};


void show_tree99(TreeNode *root)
{
	if(root!=NULL)
	{
		show_tree99(root->left);
		cout<<root->val<<" ";
		show_tree99(root->right);
	}
}

/*
int main()
{
	Solution so;
	TreeNode a(7);
	TreeNode b(9);
	TreeNode c(8);
	TreeNode d(2);
	TreeNode e(5);
	TreeNode f(3);
	TreeNode g(4);
	TreeNode h(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	e.left= &g;
	e.right = &h;
	so.recoverTree(&a);
	show_tree99(&a);
	cout<<endl;

	system("pause");
	return 0;
}
*/