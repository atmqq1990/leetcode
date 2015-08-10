#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> nums;
		for (int i = 1; i <= 9; i++)
			nums.push_back(i);
		vector<int> pre;
		combination(nums,pre,n,0,k);
		return res;
	}

	void combination(vector<int>&nums, vector<int>pre, int target, int pos, int k)
	{
		if (pre.size() == k)
		{
			if (target == 0)
				res.push_back(pre);
			return;
		}
		if (pos == nums.size())
			return;
		for (int i = pos; i < nums.size() && target >= nums[i]; i++)
		{
			pre.push_back(nums[i]);
			combination(nums,pre,target-nums[i],i+1,k);
			pre.pop_back();
		}
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<vector<int>> res = so.combinationSum3(3,9);
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