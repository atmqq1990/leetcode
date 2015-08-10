#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.size();
		if (len == 0)
			return true;
		int i = 0;
		int j = len - 1;
		while (i <= j)
		{
			while (i <= j && !isalphanumeric(s[i]))
				i++;
			while (i <= j && !isalphanumeric(s[j]))
				j--;
			if (i <= j)
			{
				char c1 = s[i];
				if (c1 >= 'a')
					c1 = c1 - 32;
				char c2 = s[j];
				if (c2 >= 'a')
					c2 = c2 - 32;
				if (c1 != c2)
					return false;
				i++;
				j--;
			}
		}
		return true;
	}

	bool isalphanumeric(char c)
	{
		if (c >= 'a' && c <= 'z')
			return true;
		if (c >= '0' && c <= '9')
			return true;
		if (c >= 'A' && c <= 'Z')
			return true;
		return false;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isPalindrome("race a car");
	cout << res << endl;

	system("pause");
	return 0;
}
*/