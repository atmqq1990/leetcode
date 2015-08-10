#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		
		if (haystack.size() != 0 && needle.size() == 0)
			return 0;
		if (haystack.size() == 0 && needle.size() == 0)
			return 0;

		int lenp = needle.size();
		int *next = new int[lenp+1];

		generate_next(needle,next);

		int lens = haystack.size();

		for (int i = 0, j = 0; i<lens; i++)
		{
			if (j < lenp && haystack[i] == needle[j])
				j++;
			else
			{
				while (j > 0)
				{
					j = next[j];
					if (haystack[i] == needle[j])
					{
						j++;
						break;
					}
				}
			}
			if (j == lenp)
			{
				return i - j+1;
			}
		}

		return -1;
	}

	void generate_next(string &needle, int next[])
	{
		int len = needle.size();
		next[0] = -1;

		int j = -1, i = 0;
		while (i<len)
		{
			if (j == -1 || needle[i] == needle[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
			{
				j = next[j];
			}
		}
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.strStr("mississippi", "issipi");
	cout << res << endl;

	system("pause");
	return 0;
}
*/