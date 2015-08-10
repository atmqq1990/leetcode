#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {

		int len = strs.size();
		vector<string> res;
		unordered_map<string, int> amap;

		for (int i = 0; i<len; i++)
		{
			string ss = strs[i];
			string temp(26, '0');
			for (int i = 0; i<ss.size(); i++)
				temp[ss[i] - 'a']++;
			if (amap.find(temp) == amap.end())
			{
				amap.insert(make_pair(temp, i));
			}
			else
			{
				res.push_back(strs[i]);
				if (amap[temp] >= 0)
				{
					res.push_back(strs[amap[temp]]);
					amap[temp] = -1;
				}
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<string> v;
	string str[] = { "eat","ate","eta","dog","god","ohg","tea" };
	for (int i = 0; i<7; i++)
		v.push_back(str[i]);
	vector<string> res = so.anagrams(v);
	for (int i = 0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/