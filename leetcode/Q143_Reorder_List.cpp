#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return;

		ListNode *half = halfpartion(head);
		ListNode *l1 = head;
		ListNode *l2 = reverse(half);
		merge(l1,l2);

	}

	ListNode* halfpartion(ListNode *head)
	{
		ListNode *p = head;
		ListNode *q = head;
		while (q->next != NULL && q->next->next != NULL)
		{
			p = p->next;
			q = q->next->next;
		}
		ListNode *r = p->next;
		p->next = NULL;
		return r;
	}

	ListNode *reverse(ListNode *head)
	{
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

	void merge(ListNode *l1, ListNode *l2)
	{
		ListNode *head = l1;
		ListNode *last = head;
		l1 = l1->next;
		last->next = l2;
		last = last->next;
		l2 = l2->next;
		while (l1 && l2)
		{
			last->next = l1;
			last = last->next;
			l1 = l1->next;
			last->next = l2;
			l2 = l2->next;
			last = last->next;
		}

		if (l1)
			last->next = l1;
	}
};

void show_list143(ListNode *head)
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
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	cout << "before doing: ";
	show_list143(&a);
	so.reorderList(&a);
	cout << "after doing: ";
	show_list143(&a);

	system("pause");
	return 0;
}
*/