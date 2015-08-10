#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		int previous_index[256];
		for (int i = 0; i < 256; i++)
			previous_index[i] = -1;

		int longestlength = 0;
		int startindex = 0;
		for (int i = 0; i < s.size(); i++)
		{
			startindex = max(startindex, previous_index[s[i]] + 1);
			longestlength = max( i - startindex +1, longestlength);
			previous_index[s[i]] = i;
		}

		return longestlength;
	}
};
/*
int main(int argc, char **args)
{
	Solution so;

	string s("abcabcdd");
	int res = so.lengthOfLongestSubstring(s);
	cout << res << endl;

	system("pause");
	return 0;
}
*/