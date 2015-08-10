#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;

		ListNode *newhead = NULL;
		ListNode *p=head;
		ListNode *q=p->next;
		ListNode *r=q->next;
		ListNode *last = NULL;

		while (p && p->next)
		{
			q = p->next;
			r = q->next;

			q->next = p;
			p->next = r;

			if (newhead == NULL)
				newhead = q;
			if (last == NULL)
				last = p;
			else
			{
				last->next = q;
				last = p;
			}
			p = r;
		}
		return newhead;
	}

};


void show_lists24(ListNode *head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

/*
int main(int argc, char **args)
{
	Solution so;

	ListNode a(2);
	ListNode b(5);
	ListNode c(3);
	ListNode d(4);
	ListNode e(6);
	ListNode f(2);
	ListNode g(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

	ListNode *head = so.swapPairs(&a);
	show_lists24(head);
	
	system("pause");
	return 0;
}
*/