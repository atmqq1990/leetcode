#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	static bool cmp(string a, string b)
	{
		string s1 = a;
		string s2 = b;
		s1.append(b);
		s2.append(a);

		return s1 < s2;
	}

	string largestNumber(vector<int>& nums) {
		vector<string> stvec;
		for (int i = 0; i<nums.size(); i++)
			stvec.push_back(inttostring(nums[i]));
		sort(stvec.begin(), stvec.end(), cmp);
		string res;
		for (int i = stvec.size() - 1; i >= 0; i--)
			res.append(stvec[i]);
		if (stvec[stvec.size() - 1] == "0")
			res = "0";
		return res;
	}

	string inttostring(int a)
	{
		if (a == 0)
			return "0";
		string res;
		stack<char> st;
		while (a != 0)
		{
			int yu = a % 10;
			a = a / 10;
			st.push(yu + '0');
		}
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}

};

/*
int main()
{
	Solution so;
	vector<int> v;
	v.push_back(3);
	v.push_back(30);
	v.push_back(34);
	v.push_back(5);
	v.push_back(9);
	string res = so.largestNumber(v);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/