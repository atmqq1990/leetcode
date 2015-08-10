#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return 0;
		sort(nums.begin(),nums.end());
		int i = 1;
		int maxgap = 0;
		while (i < len)
		{
			while (i < len && nums[i] == nums[i - 1] + 1)
				i++;
			if (i != len)
			{
				maxgap = max(maxgap,nums[i]-nums[i-1]);
				i++;
			}
		}
		return maxgap;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = {1,1000};
	int res = so.maximumGap(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/