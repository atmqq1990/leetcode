#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;
		int y = x;
		long long temp = 0;
		int last = 0;
		while (x > 0)
		{
			last = x % 10;
			temp = temp * 10 + last;
			x = x / 10;
		}
	
		return temp == y;
	}
};
/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isPalindrome(123321);
	cout << res << endl;

	system("pause");
	return 0;
}
*/