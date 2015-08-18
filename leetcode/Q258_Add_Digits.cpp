#include<iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;
		int temp = num;
		while (temp >= 10)
		{
			int a = temp;
			temp = 0;
			while (a > 0)
			{
				temp += a % 10;
				a = a / 10;
			}

		}
		return temp;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.addDigits(38);
	cout << res << endl;

	system("pause");
	return 0;
}
*/