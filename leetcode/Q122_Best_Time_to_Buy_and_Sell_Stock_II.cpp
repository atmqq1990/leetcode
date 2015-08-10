#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int len = prices.size();
		for (int i = 1; i < len; ++i)
			profit += max(prices[i]-prices[i-1],0);
		return profit;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	int res = so.maxProfit(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/