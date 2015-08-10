#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> windowvalue;
		if (k == 0)
			return windowvalue;
	//	if (k == 1)
	//		return nums;
		deque<int> dq;
		int len = nums.size();
		for (int i = 0; i < k; i++)
		{
			if (dq.size() == 0)
				dq.push_front(i);
			else if (nums[i] >= nums[dq.front()])
			{
				while (!dq.empty() && nums[i] >= nums[dq.front()])
					dq.pop_front();
				dq.push_front(i);
			}
			else
			{
				while (!dq.empty() && nums[i] >= nums[dq.back()])
					dq.pop_back();
				dq.push_back(i);

			}
		}
		windowvalue.push_back(nums[dq.front()]);
		for (int i = k; i < len; i++)
		{
			if (dq.front() == i - k)
				dq.pop_front();
			if (dq.size() == 0)
				dq.push_front(i);
			else if (nums[i] >= nums[dq.front()])
			{
				while (!dq.empty() && nums[i] >= nums[dq.front()])
					dq.pop_front();
				dq.push_front(i);
			}
			else
			{
				while (!dq.empty() && nums[i] >= nums[dq.back()])
					dq.pop_back();
				dq.push_back(i);

			}
			windowvalue.push_back(nums[dq.front()]);
		}
		return windowvalue;
    }

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = { 7,2,4 };
	vector<int> res = so.maxSlidingWindow(v,2);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/