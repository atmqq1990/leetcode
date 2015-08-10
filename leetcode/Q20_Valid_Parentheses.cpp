#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {

		stack<char> st;
		int len = s.size();
		for (int i = 0; i<len; i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				st.push(s[i]);
			else if (st.empty())
				return false;
			else if (s[i] == ')' &&st.top() != '(' || s[i] == ']'&&st.top() != '[' || s[i] == '}'&&st.top() != '{')
				return false;
			else
				st.pop();
		}
		if (st.empty())
			return true;
		return false;
	}

};

/*
int main()
{
	Solution so;
	bool res = so.isValid("[");
	cout << res << endl;

	system("pause");
	return 0;
}
*/