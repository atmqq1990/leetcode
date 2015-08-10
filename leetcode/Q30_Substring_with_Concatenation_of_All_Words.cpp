#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:

	vector<int> findSubstring(string s, vector<string>& words) {

		vector<int> res;
		if (words.size() == 0)
			return res;

		unordered_map<string, int> wordsmap;
		for (int i = 0; i<words.size(); i++)
		{
			if (wordsmap.count(words[i]) >0)
				wordsmap[words[i]]++;
			else
				wordsmap.insert(make_pair(words[i], 1));
		}

		unordered_map<string, int> smap;
		int len = s.size();
		int ws = words[0].size();
		int p = 0, q = p + ws*words.size() - 1;

		bool hs[256] = { false };

		for (int i = 0; i<words.size(); i++)
			hs[words[i][0]] = true;

		while (q < len)
		{
			if (!hs[s[p]])
			{
				p++;
				q++;
				continue;
			}
			smap.clear();
			int k = p;
			while (k <= q)
			{
				string temp = s.substr(k, ws);
				if (wordsmap.count(temp) == 0)
					break;
				if (smap.count(temp) == 0)
					smap.insert(make_pair(temp, 1));
				else
					smap[temp]++;
				if (smap[temp] > wordsmap[temp])
					break;
				k = k + ws;
			}

			if (k > q)
				res.push_back(p);

			p++;
			q++;
		}

		return res;
	}

};

/*
int main()
{
	Solution so;
	vector<string> v;
	v.push_back("foo");
	v.push_back("bar");

	vector<int> res = so.findSubstring("barfoothefoobarman", v);
	for (int i = 0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/