#include<iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		int *c = new int[n+1];
		c[1] = 1;
		c[2] = 2;
		for (int i = 3; i <= n; i++)
			c[i] = c[i-1] + c[i-2];
		int res = c[n];
		delete[] c;
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.climbStairs(15);
	cout << res << endl;

	system("pause");
	return 0;
}
*/