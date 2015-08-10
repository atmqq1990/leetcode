#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		int counts[26] = { 0 };
		int len = s.size();
		for (int i = 0; i<len; i++)
			counts[s[i] - 'a']++;
		for (int i = 0; i<len; i++)
		{
			if (counts[t[i] - 'a'] == 0)
				return false;
			counts[t[i] - 'a']--;
		}
		return true;
	}
}; 