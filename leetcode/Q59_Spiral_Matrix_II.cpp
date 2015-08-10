#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> matrix;
	int number = 1;
	vector<vector<int>> generateMatrix(int n) {
		if (n < 1)
			return matrix;
		for (int i = 0; i < n; i++)
		{
			vector<int> ve(n,0);
			matrix.push_back(ve);
		}

		bool **visited = new bool *[n];
		for (int i = 0; i < n; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		for (int i = 0; i < (n + 1) / 2; i++)
			spa(matrix,visited,i,n-2*i);
		for (int i = 0; i < n; i++)
			delete[] visited[i];
		delete[] visited;
		return matrix;
	}

	void spa(vector<vector<int>>& matrix, bool **visited, int layerid, int len)
	{
		for (int i = 0; i < len; i++)
			if (!visited[layerid][layerid + i])
			{
				matrix[layerid][layerid + i] = number;
				number++;
				visited[layerid][layerid + i] = true;
			}
		for (int i = 0; i < len; i++)
			if (!visited[layerid + i][layerid + len - 1])
			{
				matrix[layerid + i][layerid + len - 1] = number;
				number++;
				visited[layerid + i][layerid + len - 1] = true;
			}
		for (int i = len - 1; i >= 0; i--)
			if (!visited[layerid + len - 1][layerid + i])
			{
				matrix[layerid + len - 1][layerid + i] = number;
				number++;
				visited[layerid + len - 1][layerid + i] = true;
			}
		for (int i = len - 1; i >= 0; i--)
			if (!visited[layerid + i][layerid])
			{
				matrix[layerid + i][layerid] = number;
				number++;
				visited[layerid + i][layerid] = true;
			}
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> res = so.generateMatrix(3);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/