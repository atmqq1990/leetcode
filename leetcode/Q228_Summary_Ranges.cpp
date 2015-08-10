#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int len = nums.size();
		if (len < 1)
			return res;
		int i = 0, j = 0;
		while (i < len)
		{
			j = i + 1;
			while (j < len && nums[j] - nums[j - 1] == 1)
				j++;
			j--;
			if (i == j)
			{
				string temp = inttostring(nums[i]);
				res.push_back(temp);
			}
			else
			{
				string temp1 = inttostring(nums[i]);
				temp1.push_back('-');
				temp1.push_back('>');
				string temp2 = inttostring(nums[j]);
				temp1.append(temp2);
				res.push_back(temp1);
			}
			i = j + 1;
		}
		return res;
	}

	string inttostring(int a)
	{
		if (a == 0)
			return "0";
		stack<char> st;
		long long v = a;
		if (v < 0)
			v = -v;
		while (v != 0)
		{
			int yu = v % 10;
			st.push(yu+'0');
			v = v / 10;
		}
		string res;
		if (a < 0)
			res.push_back('-');
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {0,1,2,4,5,7};
	vector<string> res = so.summaryRanges(v);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/