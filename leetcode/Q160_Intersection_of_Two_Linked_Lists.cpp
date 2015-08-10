#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		int lena = Listlen(headA);
		int lenb = Listlen(headB);
		ListNode *p = headA;
		ListNode *q = headB;
		if (lena > lenb)
		{
			for (int i = 0; i < lena - lenb; i++)
				p = p->next;
		}
		else if (lenb > lena)
		{
			for (int i = 0; i < lenb - lena; i++)
				q = q->next;
		}
		while (p != q)
		{
			p = p->next;
			q = q->next;
		}
		return p;
	}

	int Listlen(ListNode *head)
	{
		int count = 0;
		while (head != NULL)
		{
			count++;
			head = head->next;
		}
		return count;
	}
};
