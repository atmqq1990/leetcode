#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p = head;
		ListNode *q = p->next;
		p->next = NULL;
		while (q != NULL)
		{
			ListNode *r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		return p;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = so.reverseList(&a);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/