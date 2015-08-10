#include<iostream>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n < 1)
			return 0;
		if (n < 9)
			return 1;
		int count = 0;
		long long factor = 1;
		while (factor <= n)
		{
			int right = n % factor;
			int temp = n / factor;
			int digit = temp % 10;
			int left = temp / 10;
			if (digit == 0)
				count += left*factor;
			else if (digit == 1)
				count += left*factor + right + 1;
			else if (digit > 1)
				count += (left + 1)*factor;

			factor = factor * 10;
		}
		return count;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.countDigitOne(13);
	cout << res << endl;

	system("pause");
	return 0;
}
*/