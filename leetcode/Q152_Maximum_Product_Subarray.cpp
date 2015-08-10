#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxpro = INT_MIN;
		int local = 1;
		int len = nums.size();
		// from left to right
		for (int i = 0; i < len; i++)
		{
			local *= nums[i];
			if (local > maxpro)
				maxpro = local;
			if (local == 0)
				local = 1;
		}

		// from right to left
		local = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			local *= nums[i];
			if (local > maxpro)
				maxpro = local;
			if (local == 0)
				local = 1;
		}

		return maxpro;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = {2,3,-2,4};
	int res = so.maxProduct(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/