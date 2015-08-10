#include<iostream>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = n & 1;
		for (int i = 0; i < 31; i++)
		{
			res = res << 1;
			n = n >> 1;
			int temp = n & 1;
			res = res | temp;
		}
		return res;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	uint32_t res = so.reverseBits(43261596);
	cout << res << endl;

	system("pause");
	return 0;
}
*/