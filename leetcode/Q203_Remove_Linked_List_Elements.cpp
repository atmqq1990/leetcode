#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while (head != NULL && head->val == val)
			head = head->next;
		if (head == NULL)
			return head;
		ListNode *p = head->next;
		ListNode *last = head;
		last->next = NULL;
		while (p != NULL)
		{
			ListNode *r = p->next;
			if (p->val == val)
			{
				p = r;
			}
			else
			{
				last->next = p;
				last = last->next;
				last->next = NULL;
				p = r;
			}
		}
		return head;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	ListNode a(1);
	ListNode b(2);
	ListNode c(6);
	ListNode d(3);
	ListNode e(4);
	ListNode f(5);
	ListNode g(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	ListNode *head = so.removeElements(&a,6);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/