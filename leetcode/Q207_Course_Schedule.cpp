#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int len = numCourses;
		vector<vector<int>> children(len, vector<int>());
		vector<int> indegree(len, 0);
		for (int i = 0; i<prerequisites.size(); i++)
		{
			pair<int, int> cur = prerequisites[i];
			int a = cur.first;
			int b = cur.second;
			indegree[a]++;
			children[b].push_back(a);
		}
		bool *visited = new bool[len];
		for (int i = 0; i<len; i++)
			visited[i] = false;
		queue<int> qu;
		int visitednumber = 0;
		for (int i = 0; i<len; i++)
			if (indegree[i] == 0)
			{
				qu.push(i);
				visited[i] = true;
			}

		while (!qu.empty())
		{
			visitednumber++;
			int cur = qu.front();
			qu.pop();

			for (int i = 0; i<children[cur].size(); i++)
			{
				int neiid = children[cur][i];
				if (!visited[neiid])
				{
					indegree[neiid]--;
					if (indegree[neiid] == 0)
					{
						visited[neiid] = true;
						qu.push(neiid);
					}
				}
			}
		}

		if (visitednumber == len)
			return true;
		return false;
	}

};