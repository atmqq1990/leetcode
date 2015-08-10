#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	TreeNode *root;
	TreeNode *cur;
	stack<TreeNode*> st;
	BSTIterator(TreeNode *root) {
		this->root = root;
		cur = root;
		if(cur != NULL)
			st.push(cur);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (cur!=NULL || !st.empty())
			return true;

		return false;
	}

	/** @return the next smallest number */
	int next() {
		while (cur != NULL && cur->left != NULL)
		{
			cur = cur->left;
			st.push(cur);
		}
		
		TreeNode *temp = st.top();
		st.pop();
		cur = temp->right;
		if (cur != NULL)
			st.push(cur);
		return temp->val;
	}

};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

/*
int main(int argc, char** args)
{
	TreeNode a(4);
	TreeNode b(2);
	TreeNode c(6);
	TreeNode d(1);
	TreeNode e(3);
	TreeNode f(5);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	BSTIterator it = BSTIterator(&a);
	while (it.hasNext()) 
		cout << it.next()<<" ";
	cout << endl;

	system("pause");
	return 0;
}
*/