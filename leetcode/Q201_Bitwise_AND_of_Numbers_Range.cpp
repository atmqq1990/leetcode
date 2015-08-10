#include<iostream>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == n)
			return m;
		long long power = 1;
		long long bound = m;
		long long up = n;
		while (power < bound)
			power = power * 2;
		if (bound < power)
		{
			if (up < power)
			{			
				int tempres = power/2;
				power = power / 2;
				int temp = rangeBitwiseAnd(m & (power-1), n & (power-1));
				return (tempres|temp);	
			}
			else if (up >= power)
				return 0;
		}
		else if (bound == power)
		{
			if (up >= power * 2)
				return 0;
			else
			{
				return bound;
			}
		}
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.rangeBitwiseAnd(2147483646, 2147483647);
	cout << res << endl;

	system("pause");
	return 0;
}
*/