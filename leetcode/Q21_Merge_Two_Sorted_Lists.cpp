#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = NULL;
		ListNode *p = NULL;

		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				if (head == NULL)
				{
					head = l1;
					p = l1;
				}
				else
				{
					p->next = l1;
					p = p->next;
				}
				l1 = l1->next;
			}
			else
			{
				if (head == NULL)
				{
					head = l2;
					p = l2;
				}
				else
				{
					p->next = l2;
					p = p->next;
				}
				l2 = l2->next;
			}
		}

		if (l1)
			p->next = l1;
		if (l2)
			p->next = l2;
		return head;
	}

};


void show_list21(ListNode *head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

/*
int main()
{
	Solution so;
	ListNode a(1);
	ListNode b(3);
	ListNode c(5);
	a.next = &b;
	b.next = &c;

	ListNode d(2);
	ListNode e(4);
	ListNode f(6);
	d.next = &e;
	e.next = &f;

	ListNode *head = so.mergeTwoLists(&a, &d);
	show_list21(head);

	system("pause");
	return 0;
}
*/