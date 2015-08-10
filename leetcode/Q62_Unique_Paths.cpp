#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {

		int **path = new int*[m];
		for (int i = 0; i < m; i++)
			path[i] = new int[n];
		for (int j = 0; j < n; j++)
			path[0][j] = 1;
		for (int i = 0; i < m; i++)
			path[i][0] = 1;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				path[i][j] = path[i - 1][j] + path[i][j-1];
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
	int res = so.uniquePaths(3,7);
	cout << res << endl;

	system("pause");
	return 0;
}
*/