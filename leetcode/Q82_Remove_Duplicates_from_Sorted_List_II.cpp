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
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;
		ListNode *newhead = NULL;
		ListNode *p = head;
		ListNode *q = p->next;
		ListNode *last=NULL;
		
		while (q != NULL || p !=NULL)
		{
			while (q != NULL && q->val == p->val)
				q = q->next;

			if (p->next == q) //p->value , no duplication
			{
				if (newhead == NULL)
				{
					newhead = p;
					last = p;
					last->next = NULL;
				}
				else
				{
					last->next = p;
					last = last->next;
					last->next = NULL;
				}
				p = q;
				if (p != NULL)
					q = p->next;
			}
			else // p->value , has duplication
			{
				p = q;
				if (p != NULL)
					q = p->next;
			}

		}
		return newhead;
	}
};

void show_lists82(ListNode *head)
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
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(4);
	ListNode f(4);
	ListNode g(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	ListNode *head = so.deleteDuplicates(&a);
	show_lists82(head);

	system("pause");
	return 0;
}
*/