#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {	
		return 	match(s1,s2);		
	}

	bool match(string s1, string s2)
	{
		if (s1 == s2)
		{
			return true;
		}
		string temp1 = s1;
		string temp2 = s2;
		sort(temp1.begin(), temp1.end());
		sort(temp2.begin(), temp2.end());
		if (temp1 != temp2)
			return false;
		
		int len = s1.size();
		int size = 1;
		for (; size < len; size++)
		{
			string temp1 = s1.substr(0,size);
			string temp2 = s2.substr(0,size);
			sort(temp1.begin(), temp1.end());
			sort(temp2.begin(), temp2.end());
			if (temp1 == temp2)
			{
				bool left = match(s1.substr(0,size),s2.substr(0,size));
			    bool right = match(s1.substr(size),s2.substr(size));
				if (left && right)
					return true;
			}

			string temp3 = s2.substr(len-size);
			sort(temp3.begin(), temp3.end());
			if (temp1 == temp3)
			{
				bool right =  match(s1.substr(size),s2.substr(0,len-size));
				bool left = match(s1.substr(0,size),s2.substr(len-size));
				if (left && right)
					return true;
			}
		}

		return false;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	bool res = so.isScramble("abcdd", "dbdac");
	cout << res << endl;

	system("pause");
	return 0;
}
*/