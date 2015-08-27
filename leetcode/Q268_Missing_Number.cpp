#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int size = nums.size();
		int res = 0;
		for (int i = 0; i <= size; i++)
			res ^= i;
		for (int i = 0; i < size; i++)
			res ^= nums[i];
		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {0,1,3};
	int res = so.missingNumber(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/