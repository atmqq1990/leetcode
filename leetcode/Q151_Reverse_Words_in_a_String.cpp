#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int len = s.size();
		int i = 0;
		while (i< len && s[i] == ' ')
			i++;
		if (i == len)
		{
			s.clear();
			return;
		}

		// no space start from i
		while (i < len)
		{
			int j = i + 1;
			while (j < len && s[j] != ' ')
				j++;
			j--;
			reverse(s, i, j);
			int newi = j + 1;
			while (newi < len && s[newi] == ' ')
				newi++;
			i = newi;
		}

		while (s.size() > 0 && s[s.size() - 1] == ' ')
			s.pop_back();
		reverse(s, 0, s.size() - 1);
		while (s.size() > 0 && s[s.size() - 1] == ' ')
			s.pop_back();

		int spacecount = 0;
		for (int i = 0; i<s.size(); i++)
		{
			s[i - spacecount] = s[i];
			if (i>0 && s[i] == ' ' && s[i - 1] == ' ')
				spacecount++;
		}

		while (spacecount > 0)
		{
			s.pop_back();
			spacecount--;
		}

	}

	void reverse(string &s, int start, int end)
	{
		int i = start, j = end;
		char temp;
		while (i < j)
		{
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
	}
};

/*
int main()
{
	Solution so;
	string s = "the sky is blue";
	so.reverseWords(s);
	cout<<s<<endl;

	system("pause");
	return 0;
}
*/