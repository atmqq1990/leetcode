#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int number = 0;
		int m = grid.size();
		if (m == 0)
			return number;
		int n = grid[0].size();
		bool **visited = new bool*[m];
		for (int i = 0; i < m; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n;j++)
				if (grid[i][j] == '1' && visited[i][j] == false)
				{
					number++;
					//breadth-first search				
					queue<pair<int, int>> qu;
					qu.push(pair<int,int>(i,j));
					bfs_search(grid,visited,qu);
				}
		for (int i = 0; i < m; i++)
			delete[] visited[i];
		delete[] visited;
		return number;
	}

	void bfs_search(vector<vector<char>>& grid, bool **visited, queue<pair<int, int>>& qu)
	{
		int rowlen = grid.size();
		int collen = grid[0].size();

		while (!qu.empty())
		{
			pair<int, int> cur = qu.front();
			qu.pop();
			int rowid = cur.first;
			int colid = cur.second;
			//up
			if (rowid > 0 && grid[rowid - 1][colid] == '1' && !visited[rowid - 1][colid])
			{
				visited[rowid - 1][colid] = true;
				qu.push(pair<int,int>(rowid-1,colid));
			}
			//right
			if (colid < collen - 1 && grid[rowid][colid + 1] == '1' && !visited[rowid][colid + 1])
			{
				visited[rowid][colid + 1] = true;
				qu.push(pair<int,int>(rowid,colid+1));
			}
			//down
			if (rowid < rowlen - 1 && grid[rowid + 1][colid] == '1' && !visited[rowid + 1][colid])
			{
				visited[rowid + 1][colid] = true;
				qu.push(pair<int,int>(rowid+1,colid));
			}
			//left
			if (colid > 0 && grid[rowid][colid - 1] == '1' && !visited[rowid][colid - 1])
			{
				visited[rowid][colid - 1] = true;
				qu.push(pair<int,int>(rowid,colid-1));
			}
		}
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<vector<char>> vec;
	vector<char> v1 = {'1','1','0','0','0'};
	vector<char> v2 = {'1','1','0','0','0'};
	vector<char> v3 = {'0','0','1','0','0'};
	vector<char> v4 = {'0','0','0','1','1'};
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	int res = so.numIslands(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/