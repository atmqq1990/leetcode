#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;

		if (fabs(x - 1.0)<0.0000001)
			return x;

		long long abn = n;
		if (abn < 0)
			abn = -abn;
		double res = postive_power(x, abn);
		if (n > 0)
			return res;
		else
			return 1.0 / res;
	}


	double postive_power(double x, long long n)
	{
		double res = 1.0;
		if (n == 1)
			return x;

		res *= postive_power(x, n >> 1);
		res *= res;
		if (n % 2)
			res *= x;
		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	double res = so.myPow(1.00000, INT_MIN);
	cout << res << endl;

	system("pause");
	return 0;
}
*/