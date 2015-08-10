#include<iostream>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n < 3)
			return 0;
		bool *isPrime = new bool[n];
		for (int i = 2; i < n; i++)
			isPrime[i] = true;
		for (int i = 2; i*i < n; i++)
		{
			if (isPrime[i] == false)
				continue;
			for (int j = i*i; j < n; j += i)
				isPrime[j] = false;
		}

		int count = 0;
		for (int i = 2; i < n; i++)
			if (isPrime[i])
				count++;
		delete[] isPrime;
		return count;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.countPrimes(8);
	cout << res << endl;

	system("pause");
	return 0;
}
*/