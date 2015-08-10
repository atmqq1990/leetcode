#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

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

		int p[2100];
		for (int i = 0; i < 2100; i++)
			p[i] = 1;

		string tempres;
		int ind = 0;
		int maxin = 0;
		int maxlength = 0;
		
		for (int i = 0; i < temp.size(); i++)
		{
			if (i <= maxin)
				p[i] = min(p[2 * ind - i], maxin - i);
			else
				p[i] = 1;

			while (i - p[i] >= 0 && i + p[i] < temp.size() && temp[i + p[i]] == temp[i - p[i]])
				p[i]++;

			if (p[i] - 1 > maxlength)
			{
				maxlength = p[i] - 1;
				tempres = temp.substr(i-p[i]+1,2*p[i]-1);
			}
			
			if (i + p[i] > maxin)
			{

				ind = i;
				maxin = i + p[i];
			}

		}

		string res;
		for (int i = 1; i < tempres.size(); i=i+2)
		{
			res.push_back(tempres[i]);

		}

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;

	string res = so.longestPalindrome("abcbabc");

	cout << res << endl;

	system("pause");

	return 0;

}
*/