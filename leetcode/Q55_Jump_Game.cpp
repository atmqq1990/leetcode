#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return true;
		int last = nums[0];
		int current = 0;
		int newlast = last;
		while (last < len - 1)
		{
			while (current < last)
			{
				if (current + nums[current] > newlast)
					newlast = current + nums[current];
				if (newlast >= len - 1)
					return true;
				current++;
			}
			if (current + nums[current] > newlast)
				newlast = current + nums[current];
			if (newlast >= len - 1)
				return true;
			last = newlast;
			if (current == last && nums[last] == 0)
				return false;
		}

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	int arr[] = { 1,1,2,2,0,1,1};
	for (int i = 0; i < 7; i++)
		v.push_back(arr[i]);
	bool res = so.canJump(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/