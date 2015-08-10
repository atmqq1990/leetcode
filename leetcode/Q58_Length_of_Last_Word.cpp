#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		if (len == 0)
			return 0;
		int last = len - 1;
		while (last >= 0 && s[last] == ' ')
			last--;
		if (last < 0)
			return 0;
		if (last == 0)
			return 1;
		int first = last;
		while (first >= 0 && s[first] != ' ')
			first--;
		return last - first;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.lengthOfLastWord("hello world");
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/