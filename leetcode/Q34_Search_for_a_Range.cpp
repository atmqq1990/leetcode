#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> res;
		int middle = binary_search(nums, target, 0, nums.size() - 1);
		if (middle == -1)
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}

		int first = middle, last = middle;
		int left = binary_search(nums, target, 0, first - 1);
		while (left != -1)
		{
			first = left;
			left = binary_search(nums, target, 0, first - 1);
		}

		int right = binary_search(nums, target, last + 1, nums.size() - 1);
		while (right != -1)
		{
			last = right;
			right = binary_search(nums, target, last + 1, nums.size() - 1);
		}

		res.push_back(first);
		res.push_back(last);

		return res;
	}

	int binary_search(vector<int> &nums, int target, int start, int end)
	{
		int low = start, high = end;
		int mid;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				high = mid - 1;
			else if (nums[mid] < target)
				low = mid + 1;
		}
		return -1;
	}

};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(10);
	vector<int>  res = so.searchRange(v, 8);
	for (int i = 0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/