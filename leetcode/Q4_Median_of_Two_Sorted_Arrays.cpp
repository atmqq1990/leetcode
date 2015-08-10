#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();

		if (m ==1 && n==1)
			return (nums1[0]+nums2[0])/2.0;

		if ((m + n + 1) % 2 == 0)
			return findkth_value(nums1,nums2, (m + n + 1)/2);
		else
		{
			int v1 = findkth_value(nums1,nums2,(m + n +1)/2);
			int v2 = findkth_value(nums1,nums2,(m + n +1)/2+1);
			return (v1 + v2) / 2.0;
		}

	}


	// find the kth value in tow sorted arrays
	int findkth_value(vector<int>&nums1, vector<int>&nums2, int k)
	{
		return find_kthvalue(nums1,nums2,0,nums1.size()-1,0,nums2.size()-1,k);
	}


	int find_kthvalue(vector<int>&nums1, vector<int>&nums2, int left1, int right1, int left2, int right2, int k)
	{
		if (left1 > right1)
			return nums2[left2+k-1];

		if (left2 > right2)
			return nums1[left1+k-1];

		while (k > 1)
		{
			if (left1 > right1)
				return nums2[left2 + k - 1];

			if (left2 > right2)
				return nums1[left1 + k - 1];

			int halfk = k / 2;
			
			if (halfk > right1 - left1 + 1)
				halfk = right1 - left1 + 1;
			if (halfk > right2 - left2 + 1)
				halfk = right2 - left2 + 1;

			if (nums1[left1 + halfk - 1] == nums2[left2 + halfk - 1])
			{
				left1 = left1 + halfk;
				left2 = left2 + halfk;
				k = k - 2 * halfk;
				if (k == 0)
					return nums1[left1 - 1];
			}
			else if(nums1[left1 + halfk - 1] > nums2[left2 + halfk - 1])
			{
				left2 = left2 + halfk;
				k = k - halfk;
			}
			else if (nums1[left1 + halfk - 1] < nums2[left2 + halfk - 1])
			{
				left1 = left1 + halfk;
				k = k - halfk;
			}

		}

		if (left1 > right1)
			return nums2[left2 + k - 1];

		if (left2 > right2)
			return nums1[left1 + k - 1];

		return min(nums1[left1],nums2[left2]);
	}

};

/*
int main(int argc, char **args[])
{

	Solution so;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);

	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	nums2.push_back(5);
	nums2.push_back(6);

	double res = so.findMedianSortedArrays(nums1,nums2);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/