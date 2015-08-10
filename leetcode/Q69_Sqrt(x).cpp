#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 1)
			return 1;
		if (x == 0)
			return 0;
		long long y = x;
		double pre = x / 2;
		double current = (x*1.0 / pre + pre) / 2.0;
		while (fabs(pre - current) > 0.00001)
		{
			pre = current;
			current = (x*1.0 / pre + pre) / 2.0;
		}
		long long res = (long long)current;
		if (res * res == y)
			return res;
		if (res * res > y)
			return res - 1;
		if ((res + 1)*(res + 1) == y)
			return res + 1;
		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.mySqrt(2147395599);
	cout << res << endl;
	system("pause");
	return 0;
}
*/