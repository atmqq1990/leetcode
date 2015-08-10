#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<int> pre;
		sub(nums,pre,0);
		return res;
	}

	void sub(vector<int> &nums, vector<int>& pre, int pos)
	{
		if (pos == nums.size())
		{
			res.push_back(pre);
			return;
		}

		pre.push_back(nums[pos]);
		sub(nums,pre,pos+1);
		pre.pop_back();
		sub(nums,pre,pos+1);
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	vector<vector<int>> res = so.subsets(v);
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