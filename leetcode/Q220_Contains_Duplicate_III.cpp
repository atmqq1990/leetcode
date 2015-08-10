#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> window;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k)
				window.erase(nums[i-k-1]);
			set<int>::iterator it = window.lower_bound(nums[i] - t);
			if (it != window.end() && *it - nums[i] <= t)
				return true;
			window.insert(nums[i]);
		}
		return false;
	}

};