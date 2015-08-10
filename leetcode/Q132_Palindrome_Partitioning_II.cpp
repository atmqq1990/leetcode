#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		if (len <= 1)
			return 0;
		int *dp = new int[len+1];
		for (int i = 0; i <= len; i++)
			dp[i] = i - 1;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; j++)
				dp[i + j + 1] = min(dp[i+j+1],1+dp[i-j]);

			for (int j = 1; i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j]; j++)
				dp[i + j + 1] = min(dp[i+j+1],1+dp[i-j+1]);

		}
		int res = dp[len];
		delete[] dp;
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.minCut("bb");
	cout << res << endl;

	system("pause");
	return 0;
}
*/