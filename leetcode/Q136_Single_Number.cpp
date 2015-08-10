#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int res = 0;
		for (int i = 0; i < len; i++)
			res = res ^ nums[i];
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = {1,2,3,4,5,3,2,1,4};
	int res = so.singleNumber(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/