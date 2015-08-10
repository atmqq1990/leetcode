#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int va1 = 0;
		int count1 = 0;
		int va2 = 1;
		int count2 = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (nums[i] == va1)
				count1++;
			else if (nums[i] == va2)
				count2++;
			else if (count1 == 0)
			{
				va1 = nums[i];
				count1 = 1;
			}
			else if (count2 == 0)
			{
				va2 = nums[i];
				count2 = 1;
			}
			else
			{
				count1--;
				count2--;
			}
		}

		count1 = 0, count2 = 0;
		for (int i = 0; i < len; i++)
			if (nums[i] == va1)
				count1++;
			else if (nums[i] == va2)
				count2++;
		vector<int> res;
		if (count1 > len / 3)
			res.push_back(va1);
		if (count2 > len / 3)
			res.push_back(va2);
		
		return res;
	}

};