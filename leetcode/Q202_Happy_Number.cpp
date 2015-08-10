#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n == 1)
			return true;
		unordered_set<int> set;
		set.insert(n);
		while (n != 1)
		{
			int nextvalue = 0;
			int temp = n;
			while (temp)
			{
				int yu = temp % 10;
				nextvalue += yu * yu;
				temp = temp / 10;
			}

			if (nextvalue == 1)
				return true;
			if (set.find(nextvalue) != set.end())
				return false;
			set.insert(nextvalue);
			n = nextvalue;
		}
		return true;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isHappy(18);
	cout << res << endl;

	system("pause");
	return 0;
}
*/