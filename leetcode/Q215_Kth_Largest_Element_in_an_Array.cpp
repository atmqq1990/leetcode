#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return findKth(nums,0,nums.size()-1,k);
	}

	int findKth(vector<int>&nums, int start, int end, int k)
	{
		int len = end - start + 1;
		if (k == 1) //find max
		{
			int i = start;
			int res = nums[start];
			for (i = start + 1; i <= end; i++)
				if (nums[i] > res)
					res = nums[i];
			return res;
		}
		else if(k == len) //find min
		{
			int i = start;
			int res = nums[start];
			for (i = start + 1; i <= end; i++)
				if (nums[i] < res)
					res = nums[i];
			return res;
		}
		else
		{
			int index = partition(nums,start,end);
			if (index == k - 1)
				return nums[start+index];
			else if (index > k - 1)
				return findKth(nums, start, start+index, k);
			else if (index < k - 1)
				return findKth(nums,start+index+1,end,k-index-1);
		}
	}

	int partition(vector<int>&nums, int start, int end)
	{
		int i = start;
		int j = end;
		int piovt = nums[start];
		while (i < j)
		{
			while (i < j && nums[j] <= piovt)
				j--;
			nums[i] = nums[j];
			while (i<j && nums[i]>piovt)
				i++;
			nums[j] = nums[i];
		}
		nums[i] = piovt;
		return i - start;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = { 3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6 };
	int res = so.findKthLargest(v,20);
	cout << res << endl;

	system("pause");
	return 0;
}
*/