#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int len = s.size();
		if (len == 0)
			return 0;
		int *dp = new int[len];
		int res;
		dp[0] = 1;
		if (s[0] == '0')
			dp[0] = 0;
		for (int i = 1; i < len; i++)
		{
			if (s[i] == '0' && s[i - 1] == '0')
				return 0;
			if (s[i] == '0')
			{
				int temp = (s[i - 1] - '0') * 10 + s[i] - '0';
				if (temp < 26)
				{
					if (i - 2 < 0)
						dp[i] = 1;
					else
						dp[i] = dp[i - 2];
				}
				else
					return 0;
			}
			else
			{
				dp[i] = dp[i-1];
				int temp = (s[i - 1] - '0') * 10 + s[i] - '0';
				if (temp >= 10 && temp <= 26)
				{
					if (i - 2 < 0)
						dp[i] = dp[i] + 1;
					else
						dp[i] = dp[i] + dp[i-2];
				}
			}
		}
		res = dp[len-1];
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.numDecodings("230");
	cout << res << endl;

	system("pause");
	return 0;
}
*/