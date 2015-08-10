#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> product(len, 1);
		int temp = nums[0];
		for (int i = 1; i<len; i++)
		{
			product[i] *= temp;
			temp *= nums[i];
		}
		temp = nums[len - 1];
		for (int i = len - 2; i >= 0; i--)
		{
			product[i] *= temp;
			temp *= nums[i];
		}
		return product;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {1,2,3,4};
	vector<int> res = so.productExceptSelf(v);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/