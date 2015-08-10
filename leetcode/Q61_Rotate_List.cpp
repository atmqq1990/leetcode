#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		int len = 0;
		ListNode *p = head;
		while (p)
		{
			len++;
			p = p->next;
		}
		if (len <= 1)
			return head;
		if (len == k)
			return head;
		k = k % len;
		if (k == 0)
			return head;

		int temp = len - k;
		ListNode *pp = head;
		while (temp > 1)
		{
			pp = pp->next;
			temp--;
		}

		ListNode *r = pp->next;
		pp->next = NULL;
		ListNode *q = r;
		while (q->next != NULL)
			q = q->next;
		q->next = head;
		head = r;
		return head;
	}

};


void show_lists61(ListNode *head)
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
	ListNode *head = so.rotateRight(&a,2);
	show_lists61(head);

	system("pause");
	return 0;
}
*/