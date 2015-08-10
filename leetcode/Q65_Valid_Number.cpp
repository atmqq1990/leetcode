#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		bool neg = false;
		bool pos = false;
		bool fudianshu = false;
		bool hase = false;
		bool floatmi = false;
		bool hasdigit = false;

		int len = s.size();
		int i = 0;
		while (i < len && s[i] == ' ')
			i++;
		if (i == len)
			return false;
		if (s[i] == '-')
			neg = true;
		else if (s[i] == '+')
			pos = true;
		else if (s[i] >'9' || s[i] < '0')
		{
			if (s[i] == '.')
			{
		//		hasdigit = true;
				pos = true;
				fudianshu = true;
			}
			else 
				return false;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			pos = true;
			hasdigit = true;
		}
		i++;
		
		if (i == len && (s[i] == '+' || s[i] == '-'))
			return false;

		while (i < len)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				hasdigit = true;
				i++;
			}
			else if (s[i] == ' ')
			{
				int j = i + 1;
				while (j < len && s[j] == ' ')
					j++;
				if (j == len && hasdigit)
					return true;
				else
					return false;
			}
			else if (s[i] == '.')
			{
				if (hase)
				{
					return false;
				}
				else
				{
			//		hasdigit = true;
					if (fudianshu)
						return false;
					fudianshu = true;
					i++;
				}
			}
			else if (s[i] == 'e')
			{
				if (hase)
					return false;
				if (!hasdigit)
					return false;
				hase = true;
				i++;
				if (i == len)
					return false;
				if ((s[i] > '9' || s[i] < '0') && (s[i] != '.') && s[i] != '+' &&s[i] != '-')
					return false;
				bool hasd = false;
				for (int j = i; j < len; j++)
					if (s[j] >= '0' && s[j] <= '9')
						hasd = true;
				if (!hasd)
					return false;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (hase)
				{
					if (s[i - 1] != 'e')
						return false;
					if (i == len - 1)
						return false;
					i++;
					if ((s[i] > '9' || s[i] < '0') && s[i] != '.')
						return false;
				}
				else
					return false;
			}
			else
				return false;

		}
		if(hasdigit)
			return true;
		return false;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isNumber("6e6.5");
	cout << res << endl;	

	system("pause");
	return 0;
}
*/