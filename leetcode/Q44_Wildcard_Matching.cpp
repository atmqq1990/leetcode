#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

	bool isMatch(string s, string p) {

		int lens = s.size();
		int lenp = p.size();

		bool **match = new bool *[lens+1];
		for (int i = 0; i <= lens; i++)
			match[i] = new bool[lenp+1];

		for (int i = 0; i <= lens; i++)
			for (int j = 0; j <= lenp; j++)
				match[i][j] = false;

		match[0][0] = true;
		for (int i = 1; i <= lens; i++)
			match[i][0] = false;

		for (int j = 1; j <= lenp; j++)
		{
			match[0][j] = match[0][j - 1] && (p[j - 1] == '*');
		}

		for (int i = 1; i <= lens; i++)
			for (int j = 1; j <= lenp; j++)
			{
				if (p[j - 1] != '*')
				{
					match[i][j] = match[i - 1][j - 1] && ((s[i-1]==p[j-1]) || (p[j-1]=='?'));
				}
				else
				{
					match[i][j] = match[i-1][j] || match[i][j-1];
				}
			}

		bool res = match[lens][lenp];
		for (int i = 0; i <= lens; i++)
			delete[] match[i];
		delete[] match;

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isMatch("aa","aa");
	cout << res << endl;

	system("pause");
	return 0;
}
*/ 