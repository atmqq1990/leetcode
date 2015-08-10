#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool solved;

	void solveSudoku(vector<vector<char>>& board) {
		solved = false;

		int nextcol = 0;
		int nextrow = 0;
		while (nextrow < 9)
		{
			while (nextcol < 9 && board[nextrow][nextcol] != '.')
				nextcol++;

			if (nextcol != 9)
				break;
			nextcol = 0;
			nextrow++;
		}
		

		solve(board,nextrow,nextcol);
	}

	void solve(vector<vector<char>>&board, int row, int col)
	{
		if (solved)
			return;
		if (row == board.size())
		{
			solved = true;
			return;
		}

		int nextcol = col+1;
		int nextrow = row;
		while (nextrow < 9)
		{
			while (nextcol < 9 && board[nextrow][nextcol] != '.')
				nextcol++;

			if (nextcol != 9)
				break;
			nextcol = 0;
			nextrow++;
		}
		
		for (char c = '1'; c <= '9'; c++)
		{
			board[row][col] = c;
			if (isvalid(board, row, col, c))
				solve(board,nextrow,nextcol);
			if (solved)
				return;
			board[row][col] = '.';
		}
					
	}


	bool isvalid(vector<vector<char>> &board, int i, int j, char c)
	{
		for (int k = 0; k < 9; k++)
		{
			if (board[i][k] == c && k!=j) 
				return false;
		}

		for (int k = 0; k < 9; k++)
		{
			if (board[k][j] == c && k!=i)
				return false;
		}

		int m = i - i % 3;
		int n = j - j % 3;
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
			{
				if (board[m + x][n + y] == c)
					if ((x + m) == i && (y + n) == j)
						continue;
					else	
						return false;
			}
		
		return true;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<char> v[9];
	string s[9] = { "53..7....","6..195...",".98....6.",
		"8...6...3","4..8.3..1","7...2...6",
		".6....28.","...419..5","....8..79" };
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			v[i].push_back(s[i][j]);

	vector<vector<char>> vec;
	for (int i = 0; i < 9; i++)
		vec.push_back(v[i]);

	so.solveSudoku(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;

}
*/