#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return len;
		unordered_set<int> visited;
		unordered_set<int> numset(nums.begin(), nums.end());
		int maxlength = 0;
		for (int i = 0; i<len; i++)
		{
			int va = nums[i];
			if (visited.find(va) != visited.end())
				continue;
			visited.insert(va);
			int left = va - 1;
			int right = va + 1;
			while (numset.find(left) != numset.end())
			{
				visited.insert(left);
				left--;
			}
			while (numset.find(right) != numset.end())
			{
				visited.insert(right);
				right++;
			}
			maxlength = max(maxlength, right - left - 1);
		}
		return maxlength;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = { 100, 4, 200, 1, 3, 2 };
	int res = so.longestConsecutive(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/