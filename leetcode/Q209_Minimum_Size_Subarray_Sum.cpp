#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		int len = nums.size();
		int minlen = INT_MAX;
		int tempsum = 0;
		int i = 0, j = 0;

		while (j < len)
		{
			while (j < len && tempsum < s)
			{
				tempsum += nums[j];
				j++;
			}
			j--;
			if (tempsum >= s)
			{
				minlen = min(minlen, j - i + 1);
				if (minlen == 1)
					return 1;
			}
			if (tempsum >= s)
			{
				while (i <= j && tempsum >= s)
				{
					tempsum = tempsum - nums[i];
					i++;
				}
				minlen = min(minlen, j - i + 2);
			}
			j++;
		}
		if (minlen == INT_MAX)
			minlen = 0;
		return minlen;
	}
};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	int res = so.minSubArrayLen(3,v);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/