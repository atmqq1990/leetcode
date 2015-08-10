#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:

	vector<vector<int>> res;

	void swap(vector<int> &nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}


	vector<vector<int>> permuteUnique(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		recursive(nums, 0);
		return res;
	}

	void recursive(vector<int> & nums, int pos)
	{
		if (pos == nums.size() - 1)
		{
			res.push_back(nums);
			return;
		}
		unordered_set<int> sset;   //sset records which elements have been put on index pos
		for (int i = pos; i < nums.size(); i++)
		{
			if (i != pos && nums[i] == nums[pos])
				continue;
			if (i > pos && nums[i] == nums[i - 1])
				continue;
			if (sset.count(nums[i]) > 0)
				continue;
			sset.insert(nums[i]);

			swap(nums, pos, i);
			recursive(nums, pos + 1);
			swap(nums, pos, i);
		}
		sset.clear();
	}
};

/*
int main()
{
	Solution so;
	vector<int> v;

	int arr[] = { -1,2,0,-1,1,0,1 };
	for (int i = 0; i<7; i++)
		v.push_back(arr[i]);

	vector<vector<int>> res = so.permuteUnique(v);
	for (int i = 0; i<res.size(); i++)
	{
		for (int j = 0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	
	system("pause");
	return 0;
}
*/