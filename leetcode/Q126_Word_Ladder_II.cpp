#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		dict.insert(start);
		dict.insert(end);
		unordered_map<string, int> wordmap;
		unordered_map<int, string> inttostring;
		unordered_set<string>::iterator it = dict.begin();
		int count = 0;
		while (it != dict.end())
		{
			wordmap.insert(pair<string, int>(*it, count));
			inttostring.insert(pair<int, string>(count, *it));
			count++;
			it++;
		}
		int totalsize = dict.size();
		vector<vector<int>> vec;
		for (int i = 0; i<totalsize; i++)
		{
			vector<int> v;
			vec.push_back(v);
		}
		it = dict.begin();
		while (it != dict.end())
		{
			string temp = *it;
			int id = wordmap[temp];
			for (int i = 0; i<temp.size(); i++)
			{
				temp = *it;
				for (char c = 'a'; c <= 'z'; c++)
				{
					temp[i] = c;
					if (temp != *it && dict.find(temp) != dict.end())
					{
						int neiid = wordmap[temp];
						vec[id].push_back(neiid);
					}
				}
			}
			it++;
		}
		int source = wordmap[start];
		int target = wordmap[end];
		int *path = new int[totalsize];
		bool *visited = new bool[totalsize];
		for (int i = 0; i<totalsize; i++)
			visited[i] = false;
		vector<vector<int>> parent;
		for (int i = 0; i<totalsize; i++)
		{
			vector<int> v;
			parent.push_back(v);
		}
		queue<int> qu;
		qu.push(source);
		visited[source] = true;
		path[source] = 1;
		while (!qu.empty())
		{
			int cur = qu.front();
			qu.pop();
			if (cur == target)
				break;
			for (int i = 0; i<vec[cur].size(); i++)
			{
				int neiid = vec[cur][i];
				if (!visited[neiid])
				{
					visited[neiid] = true;
					path[neiid] = path[cur] + 1;
					parent[neiid].push_back(cur);
					qu.push(neiid);
				}
				else if (path[cur] + 1 == path[neiid])
				{
					parent[neiid].push_back(cur);
				}
			}
		}
		bool flag = visited[target];
		delete[] visited;
		delete[] path;
		if (!flag)
			return res;
		vector<int> prepath;
		construct_paths(parent, prepath, target, inttostring);
		return res;
	}


	void construct_paths(vector<vector<int>>&parent, vector<int> pre, int current, unordered_map<int, string> &inttostring)
	{
		if (parent[current].size() == 0)
		{
			vector<string> vec;
			vec.push_back(inttostring[current]);
			for (int i = pre.size() - 1; i >= 0; i--)
			{
				vec.push_back(inttostring[pre[i]]);
			}
			res.push_back(vec);
			return;
		}

		pre.push_back(current);
		for (int i = 0; i<parent[current].size(); i++)
		{
			int pid = parent[current][i];
			construct_paths(parent, pre, pid, inttostring);
		}
	}
};

/*
int main()
{
	Solution so;
	unordered_set<string> stringset;
	string arr[]={"hot","dot","dog","lot","log"};
	for(int i=0;i<5;i++)
		stringset.insert(arr[i]);
	vector<vector<string>> res = so.findLadders("hit","cog",stringset);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}
*/