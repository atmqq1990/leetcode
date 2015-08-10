#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *half = halfpartion(head);
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(half);
		return merge(l1, l2);
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

	ListNode* merge(ListNode*l1, ListNode *l2)
	{
		ListNode *newhead = NULL;
		ListNode *last = NULL;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				if (newhead == NULL)
				{
					newhead = l1;
					last = l1;
				}
				else
				{
					last->next = l1;
					last = last->next;
				}
				l1 = l1->next;
			}
			else
			{
				if (newhead == NULL)
				{
					newhead = l2;
					last = l2;
				}
				else
				{
					last->next = l2;
					last = last->next;
				}
				l2 = l2->next;
			}
		}

		if (l1 != NULL)
		{
			if (newhead == NULL)
			{
				newhead = l1;
				last = l1;
			}
			else
			{
				last->next = l1;
				last = last->next;
			}
		}

		if (l2 != NULL)
		{
			if (newhead == NULL)
			{
				newhead = l2;
				last = l2;
			}
			else
			{
				last->next = l2;
				last = last->next;
			}
		}

		return newhead;
	}
}; 