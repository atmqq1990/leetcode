#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		bool neg = false;
		if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0)
			neg = true;
		long long absnumerator = numerator;
		long long absdenominator = denominator;
		if (absnumerator < 0)
			absnumerator = -absnumerator;
		if (absdenominator < 0)
			absdenominator = -absdenominator;

		long long shang = absnumerator / absdenominator;
		long long yushu = absnumerator % absdenominator;

		string str;
		if (neg)
			str.push_back('-');
		str.append(inttostring(shang));

		if (yushu == 0)
		{
			return str;
		}
		else
		{
			str.push_back('.');
			long long number = 10 * yushu;
			string temp;
			long long yu;
			vector<int> yushuvec;
			while (number != 0)
			{			
				int sh = number / absdenominator;
				long long yu = number % absdenominator;
				char ch = sh + '0';
				// judge if the sh occurs
				for (int i = 0; i < temp.size(); i++)
				{
					if ( temp[i] == ch && yushuvec[i] == yu)
					{
						for (int j = 0; j < i; j++)
							str.push_back(temp[j]);
						str.push_back('(');
						for (int j = i; j < temp.size(); j++)
							str.push_back(temp[j]);
						str.push_back(')');
						return str;
					}
				}

				temp.push_back(ch);
				number = yu * 10;
				yushuvec.push_back(yu);
			}
			str.append(temp);
			return str;
		}
	}

	string inttostring(long long a)
	{
		if (a == 0)
			return "0";
		string res;
		stack<char> st;
		while (a != 0)
		{
			int yu = a % 10;
			a = a / 10;
			st.push(yu+'0');
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
int main(int argc, char** args)
{
	Solution so;
	string res = so.fractionToDecimal(-1,INT_MIN);
	cout << res << endl;

	system("pause");
	return 0;
}
*/