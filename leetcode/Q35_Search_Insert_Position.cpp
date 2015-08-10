#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int len = nums.size();
		if (len == 0)
			return 0;
		if (nums[0] >= target)
			return 0;
		if (nums[nums.size() - 1] == target)
			return nums.size() - 1;
		if (nums[nums.size() - 1] < target)
			return nums.size();

		int low = 0;
		int high = len - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;

			if (low == high)
			{
				if (nums[low] < target)
					return low + 1;
				else
					return low;
			}

			if (nums[mid] > target)
				high = mid - 1;
			else if (nums[mid] < target)
				low = mid + 1;
		}
	}
};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	int res = so.searchInsert(v, 3);
	cout << res << endl;

	system("pause");
	return 0;
}
*/