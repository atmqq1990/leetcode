#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string res;
		stack<char> st;
		while (n != 0)
		{
			int yu = n % 26;
			if (yu == 0)
			{
				yu = 26;
				n = n - 26;
			}
			char c = yu - 1 + 'A';
			n = n / 26;
			st.push(c);
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
int main(int argc, char **args)
{
	Solution so;
	string res = so.convertToTitle(26*26+26+1);
	cout << res << endl;

	system("pause");
	return 0;
}
*/