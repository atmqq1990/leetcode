#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		wordDict.insert(beginWord);
		wordDict.insert(endWord);
		unordered_map<string, int> wordmap;
		unordered_set<string>::iterator it = wordDict.begin();
		int count = 0;
		while (it != wordDict.end())
		{
			wordmap.insert(pair<string, int>(*it, count));
			count++;
			it++;
		}
		int totalsize = wordDict.size();
		vector<vector<int>> vec;
		for (int i = 0; i<totalsize; i++)
		{
			vector<int> v;
			vec.push_back(v);
		}
		it = wordDict.begin();
		while (it != wordDict.end())
		{
			string temp = *it;
			int id = wordmap[temp];
			for (int i = 0; i<temp.size(); i++)
			{
				temp = *it;
				for (char c = 'a'; c <= 'z'; c++)
				{
					temp[i] = c;
					if (temp != *it && wordDict.find(temp) != wordDict.end())
					{
						int neiid = wordmap[temp];
						vec[id].push_back(neiid);
					}
				}
			}
			it++;
		}
		int source = wordmap[beginWord];
		int target = wordmap[endWord];
		int *path = new int[totalsize];
		bool *visited = new bool[totalsize];
		for (int i = 0; i<totalsize; i++)
		{
			visited[i] = false;
		}
		queue<int> qu;
		qu.push(source);
		visited[source] = true;
		path[source] = 1;
		while (!qu.empty())
		{
			int cur = qu.front();
			qu.pop();
			for (int i = 0; i<vec[cur].size(); i++)
			{
				int neiid = vec[cur][i];
				if (!visited[neiid])
				{
					visited[neiid] = true;
					path[neiid] = path[cur] + 1;
					qu.push(neiid);
				}
				if (neiid == target)
					break;
			}
		}
		bool flag = visited[target];
		int res = flag ? path[target] : 0;
		delete[] visited;
		delete[] path;
		return res;
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
	int res = so.ladderLength("hit","cog",stringset);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/