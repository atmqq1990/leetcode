#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		if (head->next == head)
			return true;
		if (head->next == NULL)
			return false;
		ListNode *p = head;
		ListNode *q = p->next->next;
		while (q != NULL && q != p)
		{
			p = p->next;
			q = q->next;
			if (q != NULL)
				q = q->next;
		}

		if (q == NULL)
			return false;
		return true;
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
	d.next = &a;
	bool res = so.hasCycle(&a);
	cout << res << endl;

	system("pause");
	return 0;
}
*/