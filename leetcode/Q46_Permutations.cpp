#include<iostream>
#include<vector>
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

	vector<vector<int>> permute(vector<int>& nums) {
		recursive(nums,0);
		return res;
	}

	void recursive(vector<int> & nums, int pos)
	{
		if (pos == nums.size() - 1)
		{
			res.push_back(nums);
			return;
		}

		for (int i = pos; i < nums.size(); i++)
		{
			swap(nums,pos,i);
			recursive(nums,pos+1);
			swap(nums,pos,i);
		}
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<vector<int>> res = so.permute(v);
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