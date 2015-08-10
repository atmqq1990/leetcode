#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		if (head->next->next == NULL)
		{
			if (head->next->val == head->val)
				return true;
			return false;
		}
		ListNode *half = half_partion(head);
		ListNode *l2 = reverse(half);
		ListNode *l1 = head;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val != l2->val)
				return false;
			l1 = l1->next;
			l2 = l2->next;
		}
		return true;
	}

	ListNode *half_partion(ListNode *head)
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

};

/*
int main()
{
	Solution so;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(2);
	ListNode f(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	bool res = so.isPalindrome(&a);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/