#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		sort(nums.begin(),nums.end());
		
		vector<vector<int>> res;
		if (nums.size() < 4)
			return res;

		int firstindex = 0;
		int secondindex = firstindex + 1;
		int start;
		int end;
		
		while (firstindex < nums.size() -3)
		{
			if (nums[firstindex] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
			{
				firstindex++;
				continue;
			}
			if (nums[firstindex] + nums[firstindex + 1] + nums[firstindex + 2] + nums[firstindex + 3] > target)
				break;

			secondindex = firstindex + 1;	
			while (secondindex < nums.size() - 2)
			{
				if (nums[firstindex] + nums[secondindex] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
				{
					secondindex++;
					continue;
				}
				if (nums[firstindex] + nums[secondindex] + nums[secondindex + 1] + nums[secondindex + 2] > target)
					break;

				start = secondindex + 1;
				end = nums.size() - 1;
				while (start < end)
				{
					if (nums[firstindex] + nums[secondindex] + nums[start] + nums[start + 1] >target)
						break;
					if (nums[firstindex] + nums[secondindex] + nums[end] + nums[end - 1] < target)
						break;
					if (nums[firstindex] + nums[secondindex] + nums[start] + nums[end] == target)
					{
						vector<int> vec;
						vec.push_back(nums[firstindex]);
						vec.push_back(nums[secondindex]);
						vec.push_back(nums[start]);
						vec.push_back(nums[end]);
						res.push_back(vec);

						int newstart = start + 1;
						while (newstart < end && nums[newstart] == nums[start])
							newstart++;
						start = newstart;
						int newend = end - 1;
						while (newend > start && nums[newend] == nums[end])
							newend--;
						end = newend;
					}
					else if (nums[firstindex] + nums[secondindex] + nums[start] + nums[end] > target)
						end--;
					else if (nums[firstindex] + nums[secondindex] + nums[start] + nums[end] < target)
						start++;

				}

				int newsecondindex = secondindex + 1;
				while (newsecondindex < nums.size() - 2 && nums[newsecondindex] == nums[secondindex])
					newsecondindex++;
				secondindex = newsecondindex;

			}

			int newfirstindex = firstindex + 1;
			while (newfirstindex < nums.size() - 3 && nums[newfirstindex] == nums[firstindex])
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
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);

	vector<vector<int>> res = so.fourSum(v,0);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/