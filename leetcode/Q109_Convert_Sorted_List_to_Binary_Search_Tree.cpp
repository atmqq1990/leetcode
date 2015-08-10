#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode *end = head;
		if (head == NULL)
			return NULL;
		while (end->next != NULL)
			end = end->next;
		return build(head,end);
	}

	TreeNode *build(ListNode *start,ListNode *end)
	{
		if (start == NULL)
			return NULL;
		if (start == end)
		{
			TreeNode *p = new TreeNode(start->val);
			return p;
		}
		if (start->next == end)
		{
			TreeNode *root = new TreeNode(start->val);
			TreeNode *p = new TreeNode(end->val);
			root->right = p;
			return root;
		}
		ListNode *p = start;
		ListNode *q = start->next;
		ListNode *pre = p;
		while (q != end && q->next != end)
		{
			pre = p;
			p = p->next;
			q = q->next;
			q = q->next;
		}
		if (q->next == end)
		{
			pre = p;
			p = p->next;
		}
		TreeNode *root = new TreeNode(p->val);
		TreeNode *templeft = build(start,pre);
		TreeNode *tempright = build(p->next,end);
		root->left = templeft;
		root->right = tempright;
		return root;
	}
};

void inorder_109(TreeNode *root)
{
	if (root)
	{
		inorder_109(root->left);
		cout << root->val << " ";
		inorder_109(root->right);
	}
}

/*
int main(int argc, char **args)
{
	Solution so;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	TreeNode *root = so.sortedListToBST(&a);
	inorder_109(root);
	cout << endl;

	system("pause");
	return 0;
}
*/