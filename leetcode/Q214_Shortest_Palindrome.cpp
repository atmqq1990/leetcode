#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		int len = s.size();
		string res;
		if (len == 0)
			return res;
		string temp = s;
		reverse(temp.begin(),temp.end());
		if (s == temp)
			return temp;
		int pafromstart = longestPalindrome(s);
		for (int i = len - 1; i >= pafromstart; i--)
			res.push_back(s[i]);
		res.append(s);
		return res;
	}

	int longestPalindrome(string s) {
		int len = s.size();
		string temp;
		temp.push_back('@');
		temp.push_back('#');
		for (int i = 0; i < len; i++)
		{
			temp.push_back(s[i]);
			temp.push_back('#');
		}
		temp.push_back('$');

		int *p = new int[temp.size()];
		for (int i = 0; i < temp.size(); i++)
			p[i] = 1;
		string tempres;
		int ind = 0;
		int maxin = 0;
		int maxlength = 0;
		int startfromorginal = 1;

		for (int i = 0; i < temp.size(); i++)
		{
			if (i <= maxin)
				p[i] = min(p[2 * ind - i], maxin - i);
			else
				p[i] = 1;

			while (i - p[i] >= 0 && i + p[i] < temp.size() && temp[i + p[i]] == temp[i - p[i]])
				p[i]++;
			if (i - p[i] < 2)
				startfromorginal = max(startfromorginal, p[i] - 1);

			if (p[i] - 1 > maxlength)
			{
				maxlength = p[i] - 1;
				tempres = temp.substr(i - p[i] + 1, 2 * p[i] - 1);
			}

			if (i + p[i] > maxin)
			{

				ind = i;
				maxin = i + p[i];
			}

		}

		return startfromorginal;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	string res = so.shortestPalindrome("abcd");
	cout << res << endl;

	system("pause");
	return 0;
}
*/