#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL)
			return head;
		if (m == n)
			return head;
		ListNode *newhead = NULL;
		ListNode *last = NULL;
		ListNode *p_m = NULL;
		ListNode *p_n = NULL;
		ListNode *p_nn = NULL;

		ListNode *pre = head;
		ListNode *cur = head;
		int count = 1;
		while (count < m)
		{
			pre = cur;
			cur = cur->next;
			count++;
		}

		if (count != 1)
		{
			newhead = head;
			last = pre;
		}
		p_m = cur;
		
		ListNode *p = cur;
		ListNode *q = cur->next;
		p->next = NULL;
		ListNode *r=NULL;
		count++;
		while (count <= n)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
			count++;
		}
		p_n = p;

		if (newhead == NULL)
		{
			newhead = p;
			last = p_m;
			last->next = q;
		}
		else
		{
			last->next = p_n;
			p_m->next = q;
		}
		
		return newhead;
	}
};

void show_lists92(ListNode *head)
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
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = so.reverseBetween(&a,2,4);
	show_lists92(head);

	system("pause");
	return 0;
}
*/