#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		int len = str.size();
		bool neg = false;

		long long res = 0;
		int i = 0;
		while (i<len && str[i] == ' ')
			i++;

		if (str[i] == '-')
		{
			neg = true;
			i++;
		}
		else if (str[i] == '+')
			i++;

		while (i < len)
		{
			if (!neg && res > INT_MAX)
				return INT_MAX;
			if (neg && -res < INT_MIN)
				return INT_MIN;

			if (str[i] > '9' || str[i] < '0')
				break;
			res = res * 10 + (str[i]-'0');
			i++;
		}

		if (neg)
			res = -res;

		if (res > INT_MAX)
			return INT_MAX;
		else if (res < INT_MIN)
			return INT_MIN;

		return res;
	}
};
/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.myAtoi("9223372036854775809");
	cout << res << endl;

	system("pause");
	return 0;
	
}
*/