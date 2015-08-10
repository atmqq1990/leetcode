#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {

		string str(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; i--)
		{
			int jinwei = 0;
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				int sum = str[i + j + 1] - '0' + (num1[i] - '0')*(num2[j] - '0') + jinwei;
				str[i + j + 1] = sum % 10 + '0';
				jinwei = sum / 10;
			}
			str[i] += jinwei;
		}

		size_t start = str.find_first_not_of('0');
		if (start == str.npos)
			return "0";
		return str.substr(start);
	}
};

/*
int main()
{
	Solution so;
	string res = so.multiply("0", "1720");
	cout << res << endl;

	system("pause");
	return 0;
}
*/