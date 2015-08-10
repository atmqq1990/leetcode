#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<int, bool> map;
		int len = s.size();
		if (len < 10)
			return res;
		int keyvalue = 0;
		int i = 0;
		for (; i<10; i++)
		{
			int key1 = generatekey(s[i]);
			keyvalue = keyvalue << 3;
			keyvalue = keyvalue | key1;
		}
		map.insert(pair<int, bool>(keyvalue, false));
		while (i < len)
		{
			int key1 = generatekey(s[i]);
			keyvalue = keyvalue & 0x07ffffff;
			keyvalue = keyvalue << 3;
			keyvalue = keyvalue | key1;
			if (map.find(keyvalue) == map.end())
			{
				map.insert(pair<int, bool>(keyvalue, false));
			}
			else
			{
				if (map[keyvalue] == false)
				{
					map[keyvalue] = true;
					res.push_back(s.substr(i - 9, 10));
				}
			}
			i++;
		}

		return res;
	}


	int generatekey(char c)
	{
		switch (c)
		{
		case 'A':
			return 1;
		case 'C':
			return 2;
		case 'G':
			return 3;
		case 'T':
			return 4;
		}

	}
};

/*
int main()
{
	Solution so;
	vector<string> res = so.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
*/