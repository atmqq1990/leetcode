#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> res;
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int maxwordlen = 0;
		unordered_set<string>::iterator it = wordDict.begin();
		while (it != wordDict.end())
		{
			if (maxwordlen < it->length())
				maxwordlen = it->length();
			it++;
		}

		int lens = s.size();
		bool *reachable = new bool[lens + 1];
		for (int i = 0; i <= lens; i++)
			reachable[i] = false;
		reachable[0] = true;
		vector<vector<int>> par;
		for (int i = 0; i < lens; i++)
		{
			vector<int> v;
			par.push_back(v);
		}

		for (int i = 1; i <= lens; i++)
		{
			string temp;
			for (int j = i - 1; j >= 0 && i - j <= maxwordlen; j--)
			{
				temp.push_back(s[j]);
				string reversed = temp;
				reverse(reversed.begin(), reversed.end());
				if (wordDict.find(reversed) != wordDict.end() && reachable[j] == true)
				{
					reachable[i] = true;
					par[i - 1].push_back(j);
				}
			}
		}

		string pre;
		construct(s,par,lens-1,pre);
		return res;
	}


	void construct(string &s, vector<vector<int>>& par, int pos, string pre)
	{
		if (pos < 0)
		{
			reverse(pre.begin(),pre.end());
			pre.pop_back();
			res.push_back(pre);
			return;
		}

		for (int i = 0; i < par[pos].size(); i++)
		{
			int j = par[pos][i];
			string newpre = pre;
			newpre.push_back(' ');
			for (int k = pos; k >= j; k--)
			{
				newpre.push_back(s[k]);
			}
			construct(s,par,j-1,newpre);
		}
	}
};   

/*
int main(int argc, char** args)
{
	Solution so;
	unordered_set<string> dict;
	string dictword;
	for (int i = 1; i <= 10; i++)
	{
		dictword.push_back('a');
		dict.insert(dictword);
	}
	vector<string> res = so.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
		
	system("pause");
	return 0;
}
*/