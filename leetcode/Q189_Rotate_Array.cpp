#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;
		if (k == 0)
			return;
		reverse(nums,0,len-k-1);
		reverse(nums,len-k,len-1);
		reverse(nums,0,len-1);
	}

	void reverse(vector<int>&nums, int start, int end)
	{
		int i = start;
		int j = end;
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
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {1,2,3,4,5,6,7};
	so.rotate(v,3);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/