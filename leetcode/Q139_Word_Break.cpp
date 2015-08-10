#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int maxwordlen = 0;
		unordered_set<string>::iterator it = wordDict.begin();
		while (it != wordDict.end())
		{
			if (maxwordlen < it->length())
				maxwordlen = it->length();
			it++;
		}
		int lens = s.size();
		bool *reachable = new bool[lens+1];
		for (int i = 0; i <= lens; i++)
			reachable[i] = false;
		reachable[0] = true;
		
		for (int i = 1; i <= lens; i++)
		{
			string temp;
			for (int j = i - 1; j >= 0 && i-j <=maxwordlen ; j--)
			{
				temp.push_back(s[j]);
				string reversed = temp;
				reverse(reversed.begin(),reversed.end());
				if (wordDict.find(reversed)!=wordDict.end() && reachable[j] == true)
				{
					reachable[i] = true;
					break;
				}
			}

		}

		bool res = reachable[lens];
		delete[] reachable;
		return res;
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
	bool res = so.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",dict);
	cout << res << endl;

	system("pause");
	return 0;
}
*/