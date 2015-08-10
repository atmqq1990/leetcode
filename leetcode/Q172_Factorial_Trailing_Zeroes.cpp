#include<iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		long long factor = 5;
		int res = 0;
		while (n >= factor)
		{
			res += n / factor;
			factor *= 5;
		}
		return res;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.trailingZeroes(INT_MAX);
	cout << res << endl;

	system("pause");
	return 0;
}
*/