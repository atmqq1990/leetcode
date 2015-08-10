#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int count = 0;
		int value = INT_MIN;
		for (int i = 0; i < len; i++)
		{
			if (count == 0)
			{
				value = nums[i];
				count++;
			}
			else if (nums[i] == value)
				count++;
			else
				count--;
		}
		return value;
	}
};

/*
int main(int argc)
{
	Solution so;
	vector<int> v = {1,2,3,4,5,2,2,3,2,3,2,4,2,4,2,2,2,2,2};
	int res = so.majorityElement(v);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/