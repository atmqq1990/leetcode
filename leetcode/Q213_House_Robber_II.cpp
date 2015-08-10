#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob_noncycle(vector<int>& nums, int start, int end) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int *money = new int[len];
		for (int i = 0; i <= start; i++)
			money[i] = nums[i];
		for (int i = start + 1; i <= end; i++)
		{
			money[i] = max(money[i - 1], nums[i]);
			if (i - 2 >= start)
				money[i] = max(money[i], money[i - 2] + nums[i]);
		}

		int res = money[end];
		delete[] money;
		return res;
	}

	int rob(vector<int>& nums) {
		int len = nums.size();

		int va1 = rob_noncycle(nums, 0, len - 2);
		int va2 = rob_noncycle(nums, 1, len - 1);
		return max(va1, va2);
	}
};