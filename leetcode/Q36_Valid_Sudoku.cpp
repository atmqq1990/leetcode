#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		
		bool row[9][10], col[9][10], grid[9][10];

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				row[i][j] = false;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				col[i][j] = false;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				grid[i][j] = false;

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				if (board[i][j] >'9' || board[i][j] < '1')
					return false;

				int id = board[i][j] - '0';
				if (row[i][id])
					return false;
				row[i][id] = true;

				if (col[j][id])
					return false;
				col[j][id] = true;

				int gri = i / 3;
				int grj = j / 3;
				if (grid[3 * gri + grj][id])
					return false;
				grid[3 * gri + grj][id] = true;
			}
		
		return true;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<char> v[9];
	string s[9] = {"53..7....","6..195...",".98....6.",
				   "8...6...3","4..8.3..1","7...2...6",
				   ".6....28.","...419..5","....8..79"};
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			v[i].push_back(s[i][j]);

	vector<vector<char>> vec;
	for (int i = 0; i < 9; i++)
		vec.push_back(v[i]);
	bool res = so.isValidSudoku(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/