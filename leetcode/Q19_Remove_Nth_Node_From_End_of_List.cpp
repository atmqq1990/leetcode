#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode *p = head;
		ListNode *q = head;

		for (int i = 1; i <= n; i++)
			p = p->next;

		if (p == NULL)
			return head->next;

		while (p->next != NULL)
		{
			p = p->next;
			q = q->next;
		}

		q->next = q->next->next;

		return head;
	}

};

void show(ListNode *p)
{
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

}

/*
int main()
{
	ListNode a(1);

	Solution so;
	ListNode *newhead = so.removeNthFromEnd(&a, 1);

	show(newhead);
	system("pause");
	return 0;
}
*/