#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p = head->next;
		head->next = NULL;
		ListNode *r;
		while (p != NULL)
		{
			r = p->next;
			head = insert(head, p);
			p = r;
		}
		return head;
	}

	ListNode* insert(ListNode* head, ListNode *cur)
	{
		ListNode *p = head;
		ListNode *pre = p;
		while (p != NULL && p->val < cur->val)
		{
			pre = p;
			p = p->next;
		}
		if (p == head)
		{
			cur->next = head;
			head = cur;
		}
		else
		{
			pre->next = cur;
			cur->next = p;
		}
		return head;
	}
};