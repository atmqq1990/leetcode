#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		sort(nums.begin(),nums.end());

		if (nums.size() < 3)
			return 0;

		int closest = INT_MAX;
		int res = 0;

		int firstindex = 0;
		int start;
		int end;

		while (firstindex < nums.size() - 2)
		{
			start = firstindex + 1;
			end = nums.size() - 1;

			while (start < end)
			{
				if (nums[firstindex] + nums[start] + nums[end] == target)
					return target;
				int currentdis = abs(nums[firstindex]+nums[start]+nums[end]-target);
				if (currentdis < closest)
				{
					res = nums[firstindex] + nums[start] + nums[end];
					closest = currentdis;
				}
				int v1 = abs(nums[firstindex] + nums[start + 1] + nums[end] - target);
				int v2 = abs(nums[firstindex] + nums[start] + nums[end-1] - target);
				if (v1 < v2)
					start++;
				else
					end--;
			}

			int newfirstindex = firstindex + 1;
			while (newfirstindex < nums.size() - 2 && nums[newfirstindex] == nums[firstindex])
				newfirstindex++;

			firstindex = newfirstindex;

		}

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-4);

	int res = so.threeSumClosest(v,1);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/