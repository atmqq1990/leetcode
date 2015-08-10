#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 1)
			return nums[0];
		if (nums[len - 1] > nums[0])
			return nums[0];
		int low = 0;
		int high = len - 1;
		int mid;
		while (high - low > 1)
		{
			mid = (low + high)/2;
			if (nums[low] < nums[high])
				return nums[low];
			if (nums[mid] > nums[high])
				low = mid;
			else if (nums[mid] < nums[high])
				high = mid;
			else if (nums[mid] == nums[high])
			{
				if (nums[low] > nums[high])
					high = mid;
				else if (nums[low] == nums[high])
					low++;
			}
		}

		return min(nums[low],nums[high]);
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {4,5,6,7,3,4,4,4,4,4,4,4,4,4};
	int res = so.findMin(v);
	cout << res << endl;

	system("pause");
	return 0;

}
*/