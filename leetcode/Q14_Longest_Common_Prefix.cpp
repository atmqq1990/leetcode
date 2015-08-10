#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		string res;
		if (strs.size() == 1)
			return strs[0];
		if (strs.size() == 0)
			return res;

		return common(strs);
		
	}

	string common(vector<string>& strs)
	{
		if (strs.size() == 1)
			return strs[0];

		vector<string> aa;
		for (int i = 0; i < strs.size()-1; i += 2)
			aa.push_back(commonprefix(strs[i],strs[i+1]));
		if (strs.size() % 2 == 1)
			aa.push_back(strs[strs.size()-1]);

		return common(aa);

	}

	string commonprefix(string &a, string &b)
	{
		string res;
		int lena = a.size();
		int lenb = b.size();
		int len = min(lena,lenb);
		for (int i = 0; i < len; i++)
			if (a[i] == b[i])
				res.push_back(a[i]);
			else
				break;
		return res;
	}


};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<string> vec;
	vec.push_back("");
	vec.push_back("");
	vec.push_back("");
	string res = so.longestCommonPrefix(vec);
	cout << res << endl;

	system("pause");
	return 0;
}
*/