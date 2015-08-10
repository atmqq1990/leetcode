#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return false;
		unordered_set<int> set;
		for (int i = 0; i < len; i++)
		{
			if (set.find(nums[i]) != set.end())
				return true;
			set.insert(nums[i]);
		}
		return false;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {1,2,3,4,5,6,7,4};
	bool res = so.containsDuplicate(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/