#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> solveNQueens(int n) {
		if (n == 0)
			return res;

		string str(n,'.');
		vector<string> board;
		for (int i = 0; i < n; i++)
			board.push_back(str);

		solve_Q(board,0);
		return res;
	}

	void solve_Q(vector<string>& board, int row)
	{
		if (row == board.size())
		{
			res.push_back(board);
			return;
		}

		for (int j = 0; j < board[0].size(); j++)
		{
			if (Q_valid(board, row, j))
			{
				board[row][j] = 'Q';
				solve_Q(board,row+1);
				board[row][j] = '.';
			}
		}
	}

	// check if 'Q' can put on pos (i,j)
	bool Q_valid(vector<string>& board, int i, int j)
	{
		for (int k = i - 1; k >= 0; k--)
			if (board[k][j] == 'Q')
				return false;
		//row doest not need to check
		int k = 1;
		while (i - k >= 0 && j - k >= 0)
		{
			if (board[i - k][j - k] == 'Q')
				return false;
			k++;
		}

		k = 1;
		while (i - k >= 0 && j + k < board.size())
		{
			if (board[i - k][j + k] == 'Q')
				return false;
			k++;
		}

		return true;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<string>> res = so.solveNQueens(4);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << endl;
		cout << endl << endl << endl;
	}
	
	system("pause");
	return 0;
}
*/