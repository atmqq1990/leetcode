#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;
		RandomListNode *p = head;
		RandomListNode *newhead = new RandomListNode(head->label);
		RandomListNode *q = newhead;
		unordered_map<RandomListNode*, RandomListNode*> nodemap;
		p = p->next;
		nodemap.insert(pair<RandomListNode*, RandomListNode*>(head,newhead));
		while (p != NULL)
		{
			RandomListNode *temp = new RandomListNode(p->label);
			nodemap.insert(pair<RandomListNode*, RandomListNode*>(p,temp));
			q->next = temp;
			q = q->next;
			p = p->next;
		}
		p = head;
		q = newhead;
		while (p != NULL)
		{
			q->random = nodemap[p->random];
			p = p->next;
			q = q->next;
		}
		return newhead;
	}
};