#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool found = false;
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		bool **visited = new bool*[m];
		for (int i = 0; i < m; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		int row = 0, col = 0;
		while (row < m)
		{
			while (col < n)
			{
				if (board[row][col] != word[0])
					col++;
				else
					break;
			}
			if (col == n)
			{
				row++;
				col = 0;
			}
			else
				break;
		}

		if (row == m)
			return false;
		search(board,visited,word,row,col,1);
		
		return found;
	}

	void search(vector<vector<char>>& board,bool **visited ,string& word, int rowid, int colid, int matchedlen)
	{
		if (found)
			return;
		int m = board.size();
		int n = board[0].size();
		if (rowid < 0 || rowid > m || colid < 0 || colid > n)
			return;

		visited[rowid][colid] = true;



		if (matchedlen == word.size())
		{
			found = true;
			return;
		}
		
		if (rowid == m)
			return;

		if (rowid > 0 && !visited[rowid - 1][colid] && board[rowid - 1][colid] == word[matchedlen])
		{
			visited[rowid - 1][colid] = true;
			search(board,visited,word,rowid-1,colid,matchedlen+1);
			if (found)
				return;
			visited[rowid - 1][colid] = false;
		}

		if (rowid < m-1 && !visited[rowid + 1][colid] && board[rowid + 1][colid] == word[matchedlen])
		{
			visited[rowid + 1][colid] = true;
			search(board, visited, word, rowid + 1, colid, matchedlen + 1);
			if (found)
				return;
			visited[rowid + 1][colid] = false;
		}

		if (colid > 0 && !visited[rowid][colid - 1] && board[rowid][colid - 1] == word[matchedlen])
		{
			visited[rowid][colid - 1] = true;
			search(board,visited,word,rowid,colid-1,matchedlen+1);
			if (found)
				return;
			visited[rowid][colid - 1] = false;
		}

		if (colid < n-1 && !visited[rowid][colid + 1] && board[rowid][colid + 1] == word[matchedlen])
		{
			visited[rowid][colid + 1] = true;
			search(board, visited, word, rowid, colid + 1, matchedlen + 1);
			if (found)
				return;
			visited[rowid][colid + 1] = false;
		}

		visited[rowid][colid] = false;
		
		if (matchedlen > 1)
			return;

		colid++;
		
		while (rowid < m)
		{
			while (colid < n)
			{
				if (board[rowid][colid] != word[0])
					colid++;
				else
					break;
			}
			if (colid == n)
			{
				rowid++;
				colid = 0;
			}
			else
				break;
		}

		if (rowid == m)
			return ;

		search(board,visited,word,rowid,colid,1);
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<char>> vec;
	vector<char> v1;
	v1.push_back('A');
	v1.push_back('B');
	v1.push_back('C');
	v1.push_back('E');
	vector<char> v2;
	v2.push_back('S');
	v2.push_back('F');
	v2.push_back('C');
	v2.push_back('S');
	vector<char> v3;
	v3.push_back('A');
	v3.push_back('D');
	v3.push_back('E');
	v3.push_back('E');
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	bool res = so.exist(vec,"ABCB");
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/