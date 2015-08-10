#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<int> pre;
		subsets(pre,nums,0);
		return res;
	}

	void subsets(vector<int> pre, vector<int>&nums, int pos)
	{
		if (pos == nums.size())
		{
			res.push_back(pre);
			return;
		}

		int lastpos = pos+1;
		while (lastpos < nums.size() && nums[lastpos] == nums[pos])
			lastpos++;
		int count = lastpos - pos;
		for (int i = 0; i <= count; i++)
		{
			if(i!=0)
				pre.push_back(nums[pos]);
			subsets(pre,nums,lastpos);
		}

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> res;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	res = so.subsetsWithDup(v);
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