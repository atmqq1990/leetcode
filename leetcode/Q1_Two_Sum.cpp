#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
	using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> v;

		unordered_map<int, vector<int>> pos;
		for (int i = 0; i < nums.size(); i++)
		{
			pos[nums[i]].push_back(i);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (pos.count(target - nums[i]) >0 && nums[i] * 2 != target)
			{
				v.push_back(i + 1);
				v.push_back(pos[target - nums[i]][0] + 1);
				return v;
			}
			else if (pos.count(nums[i])>0 && pos[nums[i]].size() >= 2 && nums[i] * 2 == target)
			{
				v.push_back(pos[nums[i]][0] + 1);
				v.push_back(pos[nums[i]][1] + 1);
				return v;
			}
		}

	}
};

/*
int main(int argc, char **args)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);

	Solution so;

	vector<int> res = so.twoSum(v, 0);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/