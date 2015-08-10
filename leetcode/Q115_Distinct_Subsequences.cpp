#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int lens = s.size();
		int lent = t.size();

		int **dp = new int*[lens + 1];
		for (int i = 0; i <= lens; i++)
			dp[i] = new int[lent + 1];
		for (int i = 0; i <= lens; i++)
			dp[i][0] = 1;
		for (int j = 1; j <= lent; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= lens; i++)
		{
			for (int j = 1; j <= lent; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}

		int res = dp[lens][lent];
		for (int i = 0; i <= lens; i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}
};

/*
int main()
{
	Solution so;
	int res = so.numDistinct("rabbbit","rabbit");
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/