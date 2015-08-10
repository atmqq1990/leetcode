#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 1)
			return nums[0];
		if (nums[len - 1] > nums[0])
			return nums[0];
		int low = 0;
		int high = len - 1;
		int mid;
		while (high - low > 1)
		{
			mid = (low + high) / 2;
			if (nums[mid] > nums[high])
				low = mid;
			else if (nums[mid] < nums[high])
				high = mid;
		}

		return nums[high];
	}
};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	int res = so.findMin(v);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/