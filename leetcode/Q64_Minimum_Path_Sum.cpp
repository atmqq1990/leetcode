#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int **minpath = new int*[m];
		for (int i = 0; i < m; i++)
			minpath[i] = new int[n];
		minpath[0][0] = grid[0][0];
		for (int j = 1; j < n; j++)
			minpath[0][j] = minpath[0][j - 1] + grid[0][j];
		for (int i = 1; i < m; i++)
			minpath[i][0] = minpath[i - 1][0] + grid[i][0];
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				minpath[i][j] = min(minpath[i - 1][j], minpath[i][j - 1]) + grid[i][j];
		int res = minpath[m-1][n-1];
		for (int i = 0; i < m; i++)
			delete[] minpath[i];
		delete minpath;
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	vector<int> v3;
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	int res = so.minPathSum(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/