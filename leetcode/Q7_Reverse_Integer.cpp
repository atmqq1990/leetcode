#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {

		if (x == 0)
			return 0;

		int digit[10];
		bool neg = false;
		if (x < 0)
			neg = true;

		long long y = x;
		if (y < 0)
			y = -y;

		int totaldigitnum = 0;
		int zuihou;
		while (y)
		{
			zuihou = y % 10;
			y = y / 10;
			digit[totaldigitnum] = zuihou;
			totaldigitnum++;
		}

		long long res = 0;
		for (int i = 0; i < totaldigitnum; i++)
			res = res * 10 + digit[i];

		if (res > INT_MAX)
			return 0;

		if (neg)
			res = -res;

		return res;

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.reverse(-3001);
	cout << res << endl;

	system("pause");
	return 0;

}
*/