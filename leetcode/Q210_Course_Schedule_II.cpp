#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> res;
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
			res.push_back(cur);

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

		if (visitednumber != len)
			res.clear();
		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<pair<int,int>> vp;
	vp.push_back(pair<int,int>(1,0));
	vp.push_back(pair<int,int>(2,0));
	vp.push_back(pair<int,int>(3,1));
	vp.push_back(pair<int,int>(3,2));
	vector<int> res = so.findOrder(4,vp);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
*/