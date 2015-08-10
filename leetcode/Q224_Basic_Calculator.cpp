#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int len = s.size();
		stack<int> opernumber;
		stack<char> operand;
		int i = 0;
		while(i<len)
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
				while (j < len && s[j] >= '0' && s[j] <= '9')
				{
					temp = 10 * temp + s[j] - '0';
					j++;
				}
				opernumber.push(temp);
				i = j;
			//	opernumber.push(s[i] - '0');
			}
			if (s[i] == '+' || s[i] == '-')
			{
				if (operand.empty())
					operand.push(s[i]);
				else if (operand.top() == '+' || operand.top() == '-')
				{
					while (!operand.empty() && operand.top() != '(')
					{
						char cc = operand.top();
						operand.pop();
						int a = opernumber.top();
						opernumber.pop();
						int b = opernumber.top();
						opernumber.pop();
						if (cc == '+')
							opernumber.push(b + a);
						else if (cc == '-')
							opernumber.push(b - a);
					}
					operand.push(s[i]);
				}
				else if (operand.top() == '(')
				{
					operand.push(s[i]);
				}
				i++;
			}
			else if (s[i] == '(')
			{
				operand.push(s[i]);
				i++;
			}
			else if (s[i] == ')')
			{
				while (!operand.empty() && operand.top() != '(')
				{
					char cc = operand.top();
					operand.pop();
					int a = opernumber.top();
					opernumber.pop();
					int b = opernumber.top();
					opernumber.pop();
					if (cc == '+')
						opernumber.push(b + a);
					else if (cc == '-')
						opernumber.push(b - a);
				}
				operand.pop();
				i++;
			}
		}

		while (!operand.empty())
		{
			char cc = operand.top();
			operand.pop();
			int a = opernumber.top();
			opernumber.pop();
			int b = opernumber.top();
			opernumber.pop();
			if (cc == '+')
				opernumber.push(b + a);
			else if (cc == '-')
				opernumber.push(b - a);
		}

		return opernumber.top();
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.calculate("2147483647");
	cout << res << endl;

	system("pause");
	return 0;
}
*/