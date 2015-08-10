#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int len = s.size();
		int res = 0;
		for (int i = 0; i < len; i++)
			res = res * 26 + s[i] - 'A' + 1;
		return res;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.titleToNumber("AA");
	cout << res << endl;

	system("pause");
	return 0;
}
*/