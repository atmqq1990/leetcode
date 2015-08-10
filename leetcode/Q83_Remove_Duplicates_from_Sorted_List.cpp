#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p = head;
		ListNode *q = p->next;
		while (q != NULL)
		{
			while (q != NULL && q->val == p->val)
				q = q->next;
			p->next = q;
			p = q;
			if (p != NULL)
				q = p->next;
		}
		return head;
	}
};

void show_lists83(ListNode *head)
{
	while (head)
	{
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}

/*
int main(int argc, char** args)
{
	Solution so;
	ListNode a(1);
	ListNode b(1);
	ListNode c(2);
	ListNode d(3);
	ListNode e(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = so.deleteDuplicates(&a);
	show_lists83(head);

	system("pause");
	return 0;
}
*/