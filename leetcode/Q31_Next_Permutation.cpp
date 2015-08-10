#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		if (nums.size() <= 1)
			return;
		int len = nums.size();
		int pos = len - 2;

		while (pos >= 0 && nums[pos] >= nums[pos + 1])
			pos--;

		if (pos < 0)
		{
			reverse(nums, 0, nums.size() - 1);
		}
		else
		{
			// find first larger than nums[pos] from right
			int k = nums.size() - 1;
			while (nums[k] <= nums[pos])\
				k--;
			int temp = nums[pos];
			nums[pos] = nums[k];
			nums[k] = temp;
			reverse(nums, pos + 1, nums.size() - 1);
		}
	}

	void reverse(vector<int> &nums, int start, int end)
	{
		int i = start, j = end;
		int temp;
		while (i < j)
		{
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	}
};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(1);

	so.nextPermutation(v);
	for (int i = 0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/