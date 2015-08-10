#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;

	vector<string> letterCombinations(string digits) {
	
		if (digits.size() == 0)
			return res;
		string pre;
		digui(digits,0,pre);
		return res;
	}

	void digui(string &digits, int currentindex, string &previous)
	{
		if (currentindex == digits.size())
			res.push_back(previous);
		else
		{
			int id = digits[currentindex] - '0';
			for (int i = 0; i < arr[id].size(); i++)
			{
				previous.push_back(arr[id][i]);
				digui(digits,currentindex+1,previous);
				previous.pop_back();
			}
		}
	}


};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<string> res = so.letterCombinations("");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	system("pause");
	return 0;
}
*/