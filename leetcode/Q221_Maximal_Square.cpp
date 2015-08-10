#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		int maxsize = 0;
		int **dp = new int*[m];
		for (int i = 0; i < m; i++)
			dp[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			dp[0][j] = matrix[0][j] - '0';
			maxsize = max(maxsize,dp[0][j]);
		}
		for (int i = 0; i < m; i++)
		{
			dp[i][0] = matrix[i][0] - '0';
			maxsize = max(maxsize,dp[i][0]);
		}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					maxsize = max(maxsize,dp[i][j]);
				}
		for (int i = 0; i < m; i++)
			delete[] dp[i];
		delete[] dp;
		return maxsize*maxsize;
	}

};

/*
int main(int argc, char**args)
{
	Solution so;
	vector<vector<char>> vec;
	vector<char> v1 = { '1','0','1','0' };
	vector<char> v2 = { '1','0','1','1' };
	vector<char> v3 = { '1','0','1','1' };
	vector<char> v4 = { '1','1','1','1' };
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	int res = so.maximalSquare(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/