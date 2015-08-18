#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		int xorvalue = 0;
		for (int i = 0; i < nums.size(); i++)
			xorvalue ^= nums[i];
		int factor = findlastone(xorvalue);
		int va1 = 0;
		int va2 = 0;
		for (int i = 0; i < nums.size(); i++)
			if ((nums[i] & factor) == 0)
				va1 ^= nums[i];
			else
				va2 ^= nums[i];
		res.push_back(va1);
		res.push_back(va2);
		return res;
	}

	int findlastone(int value)
	{
		int factor = 1;
		while ((value & factor) == 0)
		{
			factor = factor << 1;
		}
		return factor;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = { 1, 2, 1, 3, 2, 5 };
	vector<int> res = so.singleNumber(v);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/