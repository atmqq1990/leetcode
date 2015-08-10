#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int *money = new int[len];
		money[0] = nums[0];
		for (int i = 1; i < len; i++)
		{
			money[i] = max(money[i-1],nums[i]);
			if (i - 2 >= 0)
				money[i] = max(money[i],money[i-2] + nums[i]);
		}
		
		int res = money[len-1];
		delete[] money;
		return res;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {1,2,3,4,1,2,6};
	int res = so.rob(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/