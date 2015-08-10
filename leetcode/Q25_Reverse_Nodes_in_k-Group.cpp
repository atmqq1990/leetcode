#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1)
			return head;

		int len = 0;
		ListNode *ptr = head;
		while (ptr)
		{
			len++;
			ptr = ptr->next;
		}

		if (len < k)
			return head;
		else 
		{
			ListNode *newhead = NULL;
			ListNode *current = head;
			ListNode *pre = NULL;
			while (len >= k)
			{
				ListNode *newcurrent = current;
				for (int i = 1; i <= k; i++)
					newcurrent = newcurrent->next;

				pair<ListNode*, ListNode*> temp = reverse(current,k);
				if (newhead == NULL)
				{
					newhead = temp.first;
					pre = temp.second;
				}
				else 
				{
					pre->next = temp.first;
					pre = temp.second;
				}
				current = newcurrent;
				len = len - k;
			}
			pre->next = current;
			
			return newhead;
		}

	}

	pair<ListNode*,ListNode*> reverse(ListNode *start, int k)
	{
		ListNode *p = start;
		ListNode *q = p->next;
		ListNode *r = q->next;
		int count = 0;
		ListNode *last=NULL;
		ListNode *first = NULL;
		p->next = NULL;
		last = p;
		count++;
		while (count < k)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
			count++;
		}
		
		first = p;
		return make_pair(first,last);		
	}

};


void show_lists25(ListNode *head)
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
	
	ListNode *head = so.reverseKGroup(&a,3);
	show_lists25(head);
	
	system("pause");
	return 0;
}
*/