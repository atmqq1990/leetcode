#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int ones = 0, twos = 0, threes = 0;
		for (int i = 0; i < len; i++)
		{
			twos |= ones &nums[i];
			ones ^= nums[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		
		return ones;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = {1,2,3,4,5,5,4,3,2,2,3,4,5};
	int res = so.singleNumber(v);

	cout << res << endl;
	system("pause");
	return 0;
}
*/