#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int len = nums.size();
		unordered_map<int, int> preindex;
		for (int i = 0; i < len; i++)
		{
			if (preindex.find(nums[i]) == preindex.end())
				preindex.insert(pair<int,int>(nums[i],i));
			else
			{
				if (i - preindex[nums[i]] <= k)
					return true;
				preindex[nums[i]] = i;
			}
		}
		return false;
	}

};