#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;
		if (lists.size() == 1)
			return lists[0];

		vector<ListNode*> lt;
		for (int i = 0; i < lists.size() - 1; i = i+2)
			lt.push_back(mergetwo_sorted_list(lists[i],lists[i+1]));
		if (lists.size() % 2 == 1)
			lt.push_back(lists[lists.size()-1]);

		return mergeKLists(lt);
	}


	ListNode* mergetwo_sorted_list(ListNode *l1, ListNode *l2)
	{
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


void show_lists23(ListNode *head)
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
	ListNode b(4);
	ListNode c(7);
	a.next = &b;
	b.next = &c;

	ListNode d(2);
	ListNode e(5);
	ListNode f(8);
	d.next = &e;
	e.next = &f;

	ListNode g(3);
	ListNode h(6);
	ListNode i(9);
	g.next = &h;
	h.next = &i;

	vector<ListNode *> v;
	v.push_back(&a);
	v.push_back(&d);
	v.push_back(&g);

	ListNode *head = so.mergeKLists(v);
	show_lists23(head);
	
	system("pause");
	return 0;
}
*/