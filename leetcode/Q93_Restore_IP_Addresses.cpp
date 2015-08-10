#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		if (s.size() < 4 || s.size() > 12)
			return res;
		vector<string> pre;
		restoreIP(pre,s,0);
		return res;

	}

	void restoreIP(vector<string> pre, string &s, int pos)
	{
		if (pos == s.size())
		{
			if (pre.size() != 4)
				return;
			string temp;
			for (int i = 0; i < 4; i++)
			{
				temp.append(pre[i]);
				temp.push_back('.');
			}
			temp.pop_back();
			res.push_back(temp);
			return;
		}

		if (pre.size() >= 4)
			return;

		int presize = pre.size();
		string temp;
		int value = 0;
		int fa = 10;
		int end = 3;
		if (s.size() - pos < end)
			end = s.size() - pos;

		if (s[pos] == '0')
		{
			int leftsize = s.size() - 1 - pos;
			if (leftsize >= (4 - presize - 1) && leftsize <= (4 - presize - 1) * 4)
			{
				vector<string> newpre(pre.begin(),pre.end());
				newpre.push_back("0");
				restoreIP(newpre,s,pos+1);
			}

			return;
		}

		for (int i = 0; i < end; i++)
		{
			value = value * fa + s[pos + i] - '0';
			temp.push_back(s[pos+i]);
			
			int leftsize = s.size()-1 - (pos + i);
			if (leftsize >= (4-presize-1) && leftsize <= (4-presize-1)*4 && value <= 255)
			{
				vector<string> newpre(pre.begin(),pre.end());
				newpre.push_back(temp);
				restoreIP(newpre,s,pos+i+1);
			}

		}
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<string> res = so.restoreIpAddresses("010010");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	system("pause");
	return 0;
}
*/