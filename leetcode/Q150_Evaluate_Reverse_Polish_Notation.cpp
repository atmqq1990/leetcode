#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int len = tokens.size();
		if (len == 0)
			return 0;
		stack<int> st;
		for (int i = 0; i<len; i++)
		{
			string s = tokens[i];
			if (s == "+" || s == "-" || s == "*" || s == "/")
			{
				int v2 = st.top();
				st.pop();
				int v1 = st.top();
				st.pop();
				int temp;
				if (s == "+")
					temp = v1 + v2;
				else if (s == "-")
					temp = v1 - v2;
				else if (s == "*")
					temp = v1 * v2;
				else if (s == "/")
					temp = v1 / v2;
				st.push(temp);
			}
			else
			{
				int v = atoi(s.c_str());
				st.push(v);
			}
		}

		return st.top();
	}
};

/*
int main()
{
	Solution so;
	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("+");
	v.push_back("3");
	v.push_back("*");
	int res = so.evalRPN(v);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/