#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		int i = len - 1;
		int newlen = len;
		while (i >= 0 && digits[i] == 9)
			i--;
		if (i < 0)
			newlen++;
		vector<int> res(newlen, 0);
		if (newlen != len)
		{
			res[0] = 1;
			return res;
		}
		else
		{
			
			i == newlen - 1;
			int carry = 1;
			while (i >= 0)
			{
				int total = digits[i] + carry;
				res[i] = total % 10;
				carry = total / 10;
				i--;
			}

		}

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v(9,8);
	vector<int> res = so.plusOne(v);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/