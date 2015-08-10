#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string res;
	string getPermutation(int n, int k) {
		vector<int> num;
		for (int i = 1; i <= n; i++)
			num.push_back(i);
		int power[10];
		power[0] = 1;
		for (int i = 1; i < 10; i++)
			power[i] = power[i-1] * i;
		getPer(num,power,k);

		return res;
	}

	void getPer(vector<int>& num, int power[],int k)
	{
		if (k == 0)
			return;
		int n = num.size();
		if (n == 1)
		{
			res.push_back('0' + num[0]);
			return;
		}
		if (power[n] == k)
		{
			for (int i = num.size()-1; i >= 0; i--)
				res.push_back(num[i]+'0');
			return;
		}

		if (power[n - 1] > k)
		{
			res.push_back(num[0]+'0');
			vector<int> newnum;
			for (int j = 1; j < n; j++)
				newnum.push_back(num[j]);
			getPer(newnum,power,k);
		}
		else
		{
			int dd = k / power[n-1];
			int yu = k % power[n-1];
			if (yu == 0)
			{
				int temp = num[0];
				num[0] = num[dd-1];
				num[dd - 1] = temp;
				res.push_back(num[0]+'0');
				vector<int>::iterator it = num.begin();
				it++;
				sort(it,num.end());
				for (int i = num.size() - 1; i >= 1; i--)
					res.push_back(num[i]+'0');
			}
			else
			{
				int temp = num[0];
				num[0] = num[dd];
				num[dd] = temp;
				res.push_back(num[0] + '0');
				vector<int> newnum;
				for (int j = 1; j < num.size(); j++)
					newnum.push_back(num[j]);
				sort(newnum.begin(),newnum.end());
				getPer(newnum,power, k - dd*power[n-1]);

			}

		}

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.getPermutation(3,3);
	cout << res << endl;

	system("pause");
	return 0;
}
*/