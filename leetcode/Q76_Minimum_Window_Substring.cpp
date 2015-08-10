#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int minlen;
	pair<int, int> window;
	string minWindow(string s, string t) {
		int lens = s.size();
		int lent = t.size();
		if (lens < lent)
			return "";

		int scount[256] = {0};
		int tcount[256] = {0};
		for (int i = 0; i < lent; i++)
			tcount[t[i]]++;
		minlen = INT_MAX;
		window.first = -1;
		window.second = -1;

		int foundcount = 0;
		int i=0,j = 0;
		while (j < lens)
		{
			if (foundcount < lent)
			{
				if (tcount[s[j]] > 0 )
				{

					if(scount[s[j]] < tcount[s[j]])
						foundcount++;
					scount[s[j]]++;
				}
				j++;
			}

			while (foundcount == lent)
			{
				if (scount[s[i]] == 0)
					i++;
				else if (scount[s[i]] > tcount[s[i]])
				{
					scount[s[i]]--;
					i++;
				}
				else if (scount[s[i]] == tcount[s[i]])
				{
					if (j - i < minlen)
					{
						minlen = j - i;
						window.first = i;
						window.second = j;
					}
					foundcount--;
					scount[s[i]]--;
					i++;
				}
			}
		}

		if (minlen == INT_MAX)
			return "";
		return s.substr(window.first,minlen);
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.minWindow("bba", "ab");
	cout << res << endl;

	system("pause");
	return 0;
}
*/