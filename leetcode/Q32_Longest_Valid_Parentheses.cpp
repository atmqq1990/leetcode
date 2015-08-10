#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {

		stack<int> st;

		int len = s.size();
		if (len == 0)
			return 0;
		int maxlength = 0;
		int leftnumber = 0;
		int rightnumber = 0;

		for (int i = 0; i<len; i++)
		{
			if (s[i] == '(')
			{
				leftnumber++;
				st.push(i);
			}
			else
			{
				if (rightnumber < leftnumber)
				{
					rightnumber++;
					s[st.top()] = '#';
					s[i] = '#';
					st.pop();
				}
				else
				{
					while (!st.empty())
						st.pop();
					leftnumber = 0;
					rightnumber = 0;
				}
			}
		}

		int i = 0;
		int currentcount = 0;
		while (i < len)
		{
			while (i< len && s[i] == '#')
			{
				i++;
				currentcount++;
			}
			if (maxlength < currentcount)
				maxlength = currentcount;
			currentcount = 0;
			i++;
		}

		return maxlength;
	}
};

/*
int main()
{
	Solution so;
	int res = so.longestValidParentheses("()(()");
	cout << res << endl;

	system("pause");
	return 0;
}
*/