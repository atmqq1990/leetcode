#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
		if (nums[nums.size() - 1] > nums[0])
			return binary_search(nums,0,nums.size()-1,target);

		int min_index = find_minvalue_index(nums);
		if (min_index == -1)
		{
			if (nums[0] == target)
				return true;
			else
				return false;
		}

		bool res = binary_search(nums,0,min_index-1,target);
		if (res)
			return true;
		return binary_search(nums,min_index,nums.size()-1,target);
	}

	int find_minvalue_index(vector<int>&nums)
	{
		int low = 0, high = nums.size() - 1;
		int mid;
		while (high - low > 1)
		{
			mid = (low + high) / 2;
			if (nums[mid] > nums[high])
				low = mid;
			else if (nums[mid] < nums[high])
				high = mid;
			else if (nums[mid] == nums[high])
			{
				if (nums[low] > nums[high])
					high = mid;
				else   
				{
					// nums[low] == nums[high] == nums[mid]
					int k = low+1;
					while (k <= high && nums[k] >= nums[k - 1])
						k++;
					if (k > high)
						return -1;
					return k;
				}
			}
		}
		return high;

	}


	bool binary_search(vector<int>&nums, int low, int high, int target)
	{
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] < target)
				low = mid + 1;
			else if (nums[mid] > target)
				high = mid - 1;
		}
		return false;
	}

};

/*
int main(int argc, char **args)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	Solution so;
	bool res = so.search(v, 3);
	cout << res << endl;

	system("pause");
	return 0;
}
*/