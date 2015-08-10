#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode *head=NULL;

		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode *p = l1;
		ListNode *q = l2;

		ListNode *current = head;

		int jinwei = 0;
		while (p != NULL && q != NULL)
		{
			ListNode *temp = new ListNode((p->val + q->val+jinwei)%10);
			jinwei = (p->val + q->val + jinwei)/10;

			if (head == NULL)
			{
				head = temp;
				current = temp;
			}
			else
			{
				current->next = temp;
				current = current->next;
			}
			p = p->next;
			q = q->next;
		}

		
		while (p != NULL)
		{
			ListNode *temp = new ListNode((p->val+jinwei) % 10);
			jinwei = (p->val + jinwei) / 10;

			current->next = temp;
			current = current->next;	
			p = p->next;
		}

		while (q != NULL)
		{
			ListNode *temp = new ListNode((q->val + jinwei) % 10);
			jinwei = (q->val + jinwei) / 10;

			current->next = temp;
			current = current->next;
			q = q->next;
		}

		if (jinwei != 0)
		{
			ListNode *temp = new ListNode(jinwei);
			current->next = temp;
			current = current->next;
		}

		return head;
	}

};

void show_list(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void destroy(ListNode *head)
{
	ListNode *q = head;
	while (head != NULL)
	{
		q = head;
		head = head->next;
		delete q;
	}
}

/*
int main(int argc, char **args)
{

	ListNode a(2);
	ListNode b(4);
	ListNode c(3);
	a.next = &b;
	b.next = &c;

	ListNode d(5);
	ListNode e(6);
	ListNode f(9);
	d.next = &e;
	e.next = &f;

	Solution so;
	ListNode *newhead = so.addTwoNumbers(&a,&d);

	show_list(newhead);
	destroy(newhead);

	system("pause");
	return 0;
}
*/