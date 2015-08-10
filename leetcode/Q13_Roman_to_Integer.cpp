#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:

	int romanToInt(string s) {

		string thousand[10] = { "","M","MM","MMM"};
		string hundred[10] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string ten[10] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		string digit[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
		unordered_map<string, int> romap;
		for (int i = 1; i < 4; i++)
			romap.insert(make_pair(thousand[i], i * 1000));
		for (int i = 1; i < 10; i++)
			romap.insert(make_pair(hundred[i], i * 100));
		for (int i = 1; i < 10; i++)
			romap.insert(make_pair(ten[i], i * 10));
		for (int i = 1; i < 10; i++)
			romap.insert(make_pair(digit[i], i));

		int len = s.size();
		if (len == 0)
			return 0;
		int i = 0;
		int res = 0;
		string current;
		current.push_back(s[i]);
		i++;
		while (i < len)
		{
			string temp = current;
			temp.push_back(s[i]);
			while (i < len && romap.count(temp) > 0)
			{
				current = temp;
				i++;
				if(i < len)
					temp.push_back(s[i]);
			}
			res = res + romap[current];
			current.clear();
			if (i < len)
			{
				current.push_back(s[i]);
				i++;
			}
		}
		if (current.size()>0)
			res += romap[current];
		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.romanToInt("DCXXI");
	cout << res << endl;

	system("pause");
	return 0;
}
*/