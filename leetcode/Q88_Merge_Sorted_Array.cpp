#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0)
			return;
		if (m == 0)
		{
			for (int i = 0; i < n; i++)
				nums1[i] = nums2[i];
			return;
		}
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] >= nums2[j])
			{
				nums1[k] = nums1[i];
				i--;
				k--;
			}
			else
			{
				nums1[k] = nums2[j];
				j--;
				k--;
			}
		}

		// if i>=0 , no need to move
		while (j >= 0)
		{
			nums1[k] = nums2[j];
			j--;
			k--;
		}

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v1(10);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	so.merge(v1,3,v2,3);
	for (int i = 0; i < 3 + 3; i++)
		cout << v1[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/