#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int len = nums.size();
		int low = 0;
		int high = len - 1;
		while (low < high)
		{
			int mid1 = (low + high) / 2;
			int mid2 = mid1 + 1;
			if (nums[mid1] < nums[mid2])
				low = mid2;
			else
				high = mid1;
		}
		return low;
	}
};