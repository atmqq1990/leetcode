#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return NULL;
		UndirectedGraphNode *source = new UndirectedGraphNode(node->label);
		unordered_map<int, UndirectedGraphNode*> hasconstructed;
		hasconstructed.insert(pair<int,UndirectedGraphNode*>(source->label,source));
		queue<UndirectedGraphNode*> qu;
		qu.push(node);
		unordered_set<int> visitedlabelset;
		visitedlabelset.insert(node->label);
		while (!qu.empty())
		{
			UndirectedGraphNode * precur = qu.front();
			qu.pop();
			UndirectedGraphNode * clocur = hasconstructed[precur->label];
			for (int i = 0; i < precur->neighbors.size(); i++)
			{
				UndirectedGraphNode * nei = precur->neighbors[i];
				if (visitedlabelset.find(nei->label) == visitedlabelset.end())
				{
					visitedlabelset.insert(nei->label);
					qu.push(nei);
				}
				if (hasconstructed.find(nei->label) == hasconstructed.end())
				{
					UndirectedGraphNode * temp = new UndirectedGraphNode(nei->label);
					hasconstructed.insert(pair<int,UndirectedGraphNode*>(temp->label,temp));
				}
				clocur->neighbors.push_back(hasconstructed[nei->label]);
			}
		}

		return source;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;

	system("pause");
	return 0;
}
*/