#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {

		int minindex = find_min_index(nums);

		int res1 = binary_search(nums, 0, minindex - 1, target);

		if (res1 != -1)
			return res1;

		return binary_search(nums, minindex, nums.size() - 1, target);

	}

	int find_min_index(vector<int>& nums)
	{
		int low = 0;
		int high = nums.size() - 1;
		int mid = (low + high) / 2;
		while (high - low > 1)
		{
			if (nums[mid] > nums[high])
			{
				low = mid;
				mid = (low + high) / 2;
			}
			else if (nums[mid] < nums[high])
			{
				high = mid;
				mid = (low + high) / 2;
			}

		}

		return high;
	}


	int binary_search(vector<int> &nums, int low, int high, int target)
	{
		int start = low;
		int end = high;
		int mid = (start + end) / 2;

		while (start <= end)
		{

			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
			{
				end = mid - 1;
				mid = (start + end) / 2;
			}
			else if (nums[mid] < target)
			{
				start = mid + 1;
				mid = (start + end) / 2;
			}
		}

		return -1;
	}


};

/*
int main(int argc, char **args)
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	Solution so;

	int res = so.search(v, 1);
	cout << res << endl;

	system("pause");
	return 0;
}
*/