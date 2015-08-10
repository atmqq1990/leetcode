#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		TreeLinkNode *newstart = root->left;
		TreeLinkNode *cur = root;
		while (newstart != NULL)
		{
			while (cur != NULL)
			{
				cur->left->next = cur->right;
				if (cur->next != NULL)
					cur->right->next = cur->next->left;
				cur = cur->next;

			}
			cur = newstart;
			newstart = cur->left;
		}
	}
};


void lever_order116(TreeLinkNode *root)
{
	if(root == NULL)
	return;
	TreeLinkNode *newstart = root->left;
	TreeLinkNode *cur = root;
	while(newstart || cur)
	{
		while(cur != NULL)
		{
			cout<<cur->val<<" ";
			cur = cur->next;
		}
		cout<<endl;
		cur = newstart;
		if(cur)
			newstart = cur->left;
	}
}

/*
int main()
{
	Solution so;
	TreeLinkNode a(1);
	TreeLinkNode b(2);
	TreeLinkNode c(3);
	TreeLinkNode d(4);
	TreeLinkNode e(5);
	TreeLinkNode f(6);
	TreeLinkNode g(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	so.connect(&a);
	lever_order116(&a);

	system("pause");
	return 0;
}
*/