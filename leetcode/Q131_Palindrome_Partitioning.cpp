#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		vector<string> pre;
		part(s,pre,0);
		return res;
	}

	void part(string &s, vector<string>&pre, int pos)
	{
		if (pos == s.size())
		{
			res.push_back(pre);
			return;
		}

		string temp;
		for (int i = pos; i < s.size(); i++)
		{
			temp.push_back(s[i]);
			if (temp[temp.size() - 1] == temp[0] && ispalindrom(temp, 0, temp.size() - 1))
			{
				pre.push_back(temp);
				part(s,pre,i+1);
				pre.pop_back();
			}
		}
	}
	
	bool ispalindrom(string &s, int start, int end)
	{
		int i = start;
		int j = end;
		while (i <= j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<string>> res = so.partition("aab");
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/