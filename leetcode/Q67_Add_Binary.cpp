#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		stack<char> st;
		int lena = a.size();
		int lenb = b.size();
		int i = lena-1, j = lenb-1;
		int carry = 0;
		int sum = 0;
		char putintost;
		while (i >= 0 && j >= 0)
		{
			sum = a[i] - '0' + b[j] - '0' + carry;
			putintost = sum % 2 + '0';
			st.push(putintost);
			carry = sum / 2;
			i--;
			j--;
		}

		while (i >= 0)
		{
			sum = a[i] - '0' + carry;
			putintost = sum % 2 + '0';
			st.push(putintost);
			carry = sum / 2;
			i--;
		}

		while (j >= 0)
		{
			sum = b[j] - '0' + carry;
			putintost = sum % 2 + '0';
			st.push(putintost);
			carry = sum / 2;
			j--;
		}

		if (carry == 1)
			st.push('1');

		string res;
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.addBinary("11","1");
	cout << res << endl;

	system("pause");
	return 0;
}
*/