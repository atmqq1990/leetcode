#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> res;
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();
		if (n == 0)
			return res;
		bool **visited = new bool *[m];
		for (int i = 0; i < m; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		int minv = min(m,n);
		for (int i = 0; i < (minv+1) / 2; i++)
		{
			spa(matrix, visited, i, m-2*i,n-2*i);
		}
		for (int i = 0; i < m; i++)
			delete[] visited[i];
		delete[] visited;
		return res;

	}

	void spa(vector<vector<int>>& matrix, bool **visited, int layerid, int rowlen, int collen)
	{
		for (int i = 0; i < collen;i++)
			if (!visited[layerid][layerid + i])
			{
				res.push_back(matrix[layerid][layerid+i]);
				visited[layerid][layerid + i] = true;
			}
		for (int i = 0; i < rowlen;i++)
			if (!visited[layerid + i][layerid + collen - 1])
			{
				res.push_back(matrix[layerid+i][layerid+collen-1]);
				visited[layerid+i][layerid+collen-1] = true;
			}
		for (int i = collen - 1; i >= 0;i--)
			if (!visited[layerid + rowlen - 1][layerid + i])
			{
				res.push_back(matrix[layerid+rowlen-1][layerid+i]);
				visited[layerid + rowlen - 1][layerid + i] = true;
			}
		for (int i = rowlen - 1; i >= 0;i--)
			if (!visited[layerid + i][layerid])
			{
				res.push_back(matrix[layerid+i][layerid]);
				visited[layerid + i][layerid] = true;
			}
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(6);
	v1.push_back(9);
	v1.push_back(7);
	vec.push_back(v1);
	vector<int> res = so.spiralOrder(vec);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/