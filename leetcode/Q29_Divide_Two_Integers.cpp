#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {

		if (divisor == 1)
			return dividend;
		if (divisor == 0)
			return INT_MAX;
		if (dividend == 0)
			return 0;
		
		bool neg = (dividend<0) && (divisor>0) || (dividend>0) && (divisor<0);

		if (!neg)
		{
			return pos_div(fabs(dividend), fabs(divisor));
		}
		else
		{
			int res = pos_div(fabs(dividend), fabs(divisor));
			res = -res;
			return res;
		}
		
	}

	int pos_div(long long dividend, long long divisor)
	{
		if (divisor == 1 && dividend > INT_MAX)
			return INT_MAX;

		if (dividend < divisor)
			return 0;

		long long count = 1;
		long long temp = divisor;
		while (dividend >= temp)
		{
			temp = temp << 1;
			count = count << 1;
		}

		if (temp == divisor)
			return 1;

		temp = temp >> 1;
		count = count >> 1;
		return count + pos_div(dividend-temp,divisor);
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.divide(1,-1);
	
	cout << res << endl;
	system("pause");
	return 0;
}
*/