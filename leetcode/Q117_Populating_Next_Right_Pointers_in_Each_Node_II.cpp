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
		TreeLinkNode *start = root->left;
		TreeLinkNode *cur = root;

		while (cur != NULL)
		{
			while (cur != NULL)
			{
				TreeLinkNode *temp = cur->next;
				while (temp)
				{
					if (temp->left || temp->right)
						break;
					temp = temp->next;
				}

				if (cur->left != NULL && cur->right != NULL)
				{
					if (start == NULL)
						start = cur->left;
					cur->left->next = cur->right;
					if (temp != NULL)
					{
						if (temp->left)
							cur->right->next = temp->left;
						else
							cur->right->next = temp->right;
					}
					cur = temp;
				}
				else if (cur->left != NULL && cur->right == NULL)
				{
					if (start == NULL)
						start = cur->left;
					if (temp != NULL)
					{
						if (temp->left)
							cur->left->next = temp->left;
						else
							cur->left->next = temp->right;
					}
					cur = temp;
				}
				else if (cur->left == NULL && cur->right != NULL)
				{
					if (start == NULL)
						start = cur->right;
					if (temp != NULL)
					{
						if (temp->left)
							cur->right->next = temp->left;
						else
							cur->right->next = temp->right;
					}
					cur = temp;
				}
				else if (cur->left == NULL && cur->right == NULL)
				{
					cur = cur->next;
				}

			}
			cur = start;
			if (cur)
				start = cur->left;
		}
	}
};

void lever_order117(TreeLinkNode *root)
{
	if(root == NULL)
		return;
	TreeLinkNode *newstart = root->left;
	TreeLinkNode *cur = root;
	while(newstart || cur)
	{
		while(cur != NULL)
		{
			if(newstart == NULL)
			{
				if(cur->left)
					newstart = cur->left;
				else if(cur->right)
					newstart = cur->right;
			}
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
	TreeLinkNode g(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &g;
	so.connect(&a);
	lever_order117(&a);

	system("pause");
	return 0;
}
*/