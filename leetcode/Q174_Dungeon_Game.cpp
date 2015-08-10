#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m == 0)
			return 0;
		int n = dungeon[0].size();
		int **dp = new int*[m];
		for (int i = 0; i<m; i++)
			dp[i] = new int[n];
		// dp[i][j] means the minmum health before enter pos[i,j]
		if (dungeon[m - 1][n - 1] >= 0)
			dp[m - 1][n - 1] = 1;
		else
			dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
		// initialize the last row
		for (int j = n - 2; j >= 0; j--)
			if (dungeon[m - 1][j] <= 0)
				dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
			else if (dungeon[m - 1][j] >0)
			{
				if (dp[m - 1][j + 1] > dungeon[m - 1][j])
					dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
				else
					dp[m - 1][j] = 1;
			}
		//initialze the last col
		for (int i = m - 2; i >= 0; i--)
			if (dungeon[i][n - 1] <= 0)
				dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
			else if (dungeon[i][n - 1] >0)
			{
				if (dp[i + 1][n - 1] > dungeon[i][n - 1])
					dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
				else
					dp[i][n - 1] = 1;
			}
		//cal other 
		for (int i = m - 2; i >= 0; i--)
			for (int j = n - 2; j >= 0; j--)
			{
				int minneed = min(dp[i + 1][j], dp[i][j + 1]);
				if (dungeon[i][j] <= 0)
					dp[i][j] = minneed - dungeon[i][j];
				else if (dungeon[i][j] > 0)
				{
					if (minneed > dungeon[i][j])
						dp[i][j] = minneed - dungeon[i][j];
					else
						dp[i][j] = 1;
				}
			}

		int res = dp[0][0];
		for (int i = 0; i<m; i++)
			delete[] dp[i];
		delete[] dp;

		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(5);
	vector<int> v2;
	v2.push_back(-2);
	v2.push_back(-3);
	vec.push_back(v1);
	vec.push_back(v2);
	int res = so.calculateMinimumHP(vec);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/