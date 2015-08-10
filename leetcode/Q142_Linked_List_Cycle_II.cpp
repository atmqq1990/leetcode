#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		if (head->next == head)
			return head;
		if (head->next == NULL)
			return NULL;
		ListNode *p = head;
		ListNode *q = p;
		while (q != NULL)
		{
			p = p->next;
			q = q->next;
			if (q != NULL)
				q = q->next;
			if (p == q)
				break;
		}

		if (q == NULL)
			return NULL;
		
		ListNode *newp = p;
		ListNode *newq = head;
		while (newp != newq)
		{
			newp = newp->next;
			newq = newq->next;
		}
		return newp;
	}
};

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
	d.next = &b;
	ListNode* cl = so.detectCycle(&a);
	if(cl != NULL)
		cout << cl->val << endl;

	system("pause");
	return 0;
}
*/