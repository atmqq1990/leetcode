#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1)
			return 0;
		int **path = new int*[m];
		for (int i = 0; i < m; i++)
			path[i] = new int[n];
		path[0][0] = 1;
		for (int j = 1; j < n; j++)
			if (path[0][j - 1] == 1 && obstacleGrid[0][j] != 1)
				path[0][j] = 1;
			else
				path[0][j] = 0;
		for (int i = 1; i < m; i++)
			if (path[i-1][0] == 1 && obstacleGrid[i][0] != 1)
				path[i][0] = 1;
			else
				path[i][0] = 0;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (obstacleGrid[i][j] == 1)
					path[i][j] = 0;
				else
					path[i][j] = path[i - 1][j] + path[i][j - 1];
		int res = path[m-1][n-1];
		for (int i = 0; i < m; i++)
			delete[] path[i];
		delete[] path;
		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);
	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);
	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	int res = so.uniquePathsWithObstacles(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/