#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0)
			return 0;
		const int K = 2;
		int **dp = new int*[K+1];
		for (int i = 0; i <= K; i++)
			dp[i] = new int[len];
		for (int i = 0; i <= K; i++)
			for (int j = 0; j < len; j++)
				dp[i][j] = 0;
		int maxprofit = 0;
		for (int kk = 1; kk <= K; kk++)
		{
			int tempmax = dp[kk - 1][0] - prices[0];
			for (int i = 1; i < len; i++)
			{
				dp[kk][i] = max(dp[kk][i-1],prices[i]+tempmax);
				tempmax = max(tempmax,dp[kk-1][i]-prices[i]);
				maxprofit = max(maxprofit,dp[kk][i]);
			}
		}
		for (int kk = 0; kk <= K; kk++)
			delete[] dp[kk];
		delete[] dp;
		return maxprofit;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> vec = { 1,2,4,2,5,7,2,4,9,0};
	int res = so.maxProfit(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/