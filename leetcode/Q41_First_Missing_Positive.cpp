#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {

		int len = nums.size();
		int minv = INT_MAX;
		int maxv = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] > 0 && nums[i] > maxv)
				maxv = nums[i];
			if (nums[i] > 0 && nums[i] < minv)
				minv = nums[i];
		}

		if (minv > 1)
			return 1;
		if (minv == maxv)
			return maxv + 1;

		for (int i = 1; i <= len; i++)
		{
			while (nums[i - 1] != i)
			{
				if (nums[i - 1] <= 0)
					break;
				if (nums[nums[i - 1] - 1] == nums[i - 1])
					break;
				swap(nums, i - 1, nums[i - 1] - 1);
			}
		}

		for (int i = 1; i <= len; i++)
			if (nums[i - 1] != i)
				return i;
	}

	void swap(vector<int> &nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

};

/*
int main()
{
	Solution so;
	vector<int> v;
	int arr[] = { 11,1,6,11,5,5,-6,9,-3,9,5,4,2,-8,16,-6,-4,2,3 };
	for (int i = 0; i<19; i++)
		v.push_back(arr[i]);

	int res = so.firstMissingPositive(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/