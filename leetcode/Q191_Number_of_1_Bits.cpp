#include<iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			count++;
			n = n & (n-1);
		}
		return count;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.hammingWeight(11);
	cout << res << endl;

	system("pause");
	return 0;
}
*/