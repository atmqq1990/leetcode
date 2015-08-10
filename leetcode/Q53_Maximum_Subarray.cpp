#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		int maxsum = nums[0];
		int current = 0;
		for (int i = 0; i < len; i++)
		{
			current += nums[i];
			if (current > maxsum)
				maxsum = current;
			if (current < 0)
				current = 0;
		}

		return maxsum;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	int arr[] = { -2,1,-3,4,-1,2,1,-5,4};
	for (int i = 0; i < 9; i++)
		v.push_back(arr[i]);
	int res = so.maxSubArray(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/