#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *newhead = NULL;
		ListNode *last = NULL;
		ListNode *p = head;
		ListNode *q = head;
		ListNode *r = head;
		while (r != NULL && r->val < x)
			r = r->next;
		if (r == NULL)
			return head;
		if (r != head)
		{
			newhead = head;
			last = head;
			while (last->next != r)
				last = last->next;
			last->next = NULL;
			p = r;
			q = r;
		}

		while (q != NULL)
		{
			while (q != NULL && q->val >= x)
			{
				p = q;
				q = q->next;
			}
			if (q == NULL)
			{
				if (newhead == NULL) // all the value are >= x
					return head;
				else
				{
					last->next = r;
				}
			}
			else
			{
				ListNode *temp = q->next;
				if (p != q)
					p->next = temp;
				if (newhead == NULL)
				{
					newhead = q;
					last = q;
					last->next = NULL;
				}
				else
				{
					last->next = q;
					last = last->next;
					last->next = NULL;
				}
				q = temp;
			}

		}
		last->next = r;
		return newhead;
	}
};

/*
void show_lists86(ListNode *head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main()
{
	Solution so;
	ListNode a(2);
	ListNode b(2);
	ListNode c(2);
	ListNode d(0);
	ListNode e(4);
	ListNode f(2);
	ListNode g(0);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	ListNode *head = so.partition(&a,4);
	show_lists86(head);

	system("pause");
	return 0;
}
*/