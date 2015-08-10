#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1)
			return 0;
		int profit = 0;
		int lowestprice = prices[0];
		for (int i = 1; i<len; i++)
		{
			if (prices[i] > lowestprice + profit)
			{
				profit = prices[i] - lowestprice;
			}
			else if (prices[i] < lowestprice)
			{
				lowestprice = prices[i];
			}
		}
		return profit;
	}
};

/*
int main()
{
	Solution so;
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	int res = so.maxProfit(vec);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/