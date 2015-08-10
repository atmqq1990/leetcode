#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int len = s.size();
		stack<int> numst;
		stack<char> opst;
		int i = 0;
		while(i < len)
		{
			if (s[i] == ' ')
			{
				i++;
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				int temp = 0;
				int j = i;
				while (s[j] >= '0' && s[j] <= '9')
				{
					temp = 10 * temp + s[j] - '0';
					j++;
				}
				numst.push(temp);
				i = j;
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			{
				while (!opst.empty() && priority(opst.top()) >= priority(s[i]))
				{
					char c = opst.top();
					opst.pop();
					int a = numst.top();
					numst.pop();
					int b = numst.top();
					numst.pop();
					int res;
					if (c == '+')
						res = b + a;
					else if (c == '-')
						res = b - a;
					else if (c == '*')
						res = b * a;
					else if (c == '/')
						res = b / a;
					numst.push(res);
				}
				opst.push(s[i]);
				i++;
			}
		}

		while (!opst.empty())
		{
			char c = opst.top();
			opst.pop();
			int a = numst.top();
			numst.pop();
			int b = numst.top();
			numst.pop();
			int res;
			if (c == '+')
				res = b + a;
			else if (c == '-')
				res = b - a;
			else if (c == '*')
				res = b * a;
			else if (c == '/')
				res = b / a;
			numst.push(res);
		}
		return numst.top();
	}

	int priority(char c)
	{
		if (c == '+' || c == '-')
			return 1;
		else if (c == '*' || c == '/')
			return 2;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.calculate(" 3+5 / 2 ");
	cout << res << endl;

	system("pause");
	return 0;
}
*/