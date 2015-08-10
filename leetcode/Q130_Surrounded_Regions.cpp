#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		bool **valid = new bool*[m];
		bool **visited = new bool*[m];
		for (int i = 0; i<m; i++)
		{
			valid[i] = new bool[n];
			visited[i] = new bool[n];
		}
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
			{
				visited[i][j] = false;
				valid[i][j] = true;
			}
		queue<pair<int, int>> qu;
		for (int j = 0; j<n; j++)
			if (board[0][j] == 'O')
			{
				valid[0][j] = false;
				qu.push(pair<int, int>(0, j));
				visited[0][j] = true;
			}
		for (int i = 0; i<m; i++)
			if (board[i][n - 1] == 'O')
			{
				valid[i][n - 1] = false;
				qu.push(pair<int, int>(i, n - 1));
				visited[i][n - 1] = true;
			}
		for (int j = 0; j<n; j++)
			if (board[m - 1][j] == 'O')
			{
				valid[m - 1][j] = false;
				qu.push(pair<int, int>(m - 1, j));
				visited[m - 1][j] = true;
			}
		for (int i = 0; i<m; i++)
			if (board[i][0] == 'O')
			{
				valid[i][0] = false;
				qu.push(pair<int, int>(i, 0));
				visited[i][0] = true;
			}

		while (!qu.empty())
		{
			pair<int, int> cur = qu.front();
			qu.pop();

			//left
			if (cur.second > 0)
			{
				int row = cur.first;
				int col = cur.second - 1;
				if (board[row][col] == 'O' && !visited[row][col])
				{
					valid[row][col] = false;
					visited[row][col] = true;
					qu.push(pair<int, int>(row, col));
				}
			}

			//up
			if (cur.first > 0)
			{
				int row = cur.first - 1;
				int col = cur.second;
				if (board[row][col] == 'O' && !visited[row][col])
				{
					valid[row][col] = false;
					visited[row][col] = true;
					qu.push(pair<int, int>(row, col));
				}
			}

			//right
			if (cur.second < n - 1)
			{
				int row = cur.first;
				int col = cur.second + 1;
				if (board[row][col] == 'O' && !visited[row][col])
				{
					valid[row][col] = false;
					visited[row][col] = true;
					qu.push(pair<int, int>(row, col));
				}
			}

			//down
			if (cur.first < m - 1)
			{
				int row = cur.first + 1;
				int col = cur.second;
				if (board[row][col] == 'O' && !visited[row][col])
				{
					valid[row][col] = false;
					visited[row][col] = true;
					qu.push(pair<int, int>(row, col));
				}
			}
		}

		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				if (valid[i][j])
					board[i][j] = 'X';

	}
};

/*
int main()
{
	Solution so;
	vector<vector<char>> vec;
	vector<char> v1;
	v1.push_back('X');
	v1.push_back('X');
	v1.push_back('X');
	v1.push_back('X');
	vector<char> v2;
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('O');
	v2.push_back('X');
	vector<char> v3;
	v3.push_back('X');
	v3.push_back('X');
	v3.push_back('O');
	v3.push_back('X');
	vector<char> v4;
	v4.push_back('X');
	v4.push_back('O');
	v4.push_back('X');
	v4.push_back('X');
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	so.solve(vec);
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}
*/