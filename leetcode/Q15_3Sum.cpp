#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		sort(nums.begin(),nums.end());
		vector<vector<int>> res;

		if (nums.size() < 3)
			return res;

		int firstindex = 0;
		int start;
		int end;

		while (firstindex < nums.size()-2 )
		{
			if (nums[firstindex] * 3 > 0)
				return res;

			start = firstindex + 1;
			end = nums.size() - 1;

			while (start < end)
			{
				if (nums[start] + nums[end] < -nums[firstindex])
				{
					if (nums[end] * 2 < -nums[firstindex])
						break;

					start++;
				}
				else if (nums[start] + nums[end] > -nums[firstindex])
				{
					if (nums[start] * 2 > -nums[firstindex])
						break;

					end--;
				}
				else if (nums[start] + nums[end] == -nums[firstindex])
				{
					vector<int> vec;
					vec.push_back(nums[firstindex]);
					vec.push_back(nums[start]);
					vec.push_back(nums[end]);
					res.push_back(vec);

					int newstart = start+1;
					while (newstart < end && nums[newstart] == nums[start])
						newstart++;
					start = newstart;
					int newend = end-1;
					while (newend > start && nums[newend] == nums[end])
						newend--;
					end = newend;
					
				}

			}

			
			int newfirstindex = firstindex+1;
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
	int arr[] = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	for (int i = 0; i < 16; i++)
		v.push_back(arr[i]);

	vector<vector<int>> res = so.threeSum(v);
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