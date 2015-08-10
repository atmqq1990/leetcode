#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> res;

	vector<string> generateParenthesis(int n) {
		if (n < 1)
			return res;
		string pre;
		generate(pre,n,0,0);

		return res;
	}

	void generate(string &previous,int n,int leftnumber, int rightnumber)
	{
		if (leftnumber == n && rightnumber == n)
			res.push_back(previous);
		else
		{
			if (leftnumber > rightnumber)
			{
				previous.push_back(')');
				generate(previous, n, leftnumber, rightnumber + 1);
				previous.pop_back();

				if (leftnumber < n)
				{
					previous.push_back('(');
					generate(previous,n,leftnumber+1,rightnumber);
					previous.pop_back();					
				}						
			}
			else if (leftnumber == rightnumber)
			{
				previous.push_back('(');
				generate(previous, n, leftnumber + 1, rightnumber);
				previous.pop_back();
			}

		}

	} 

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<string> res = so.generateParenthesis(4);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	
	system("pause");
	return 0;
}
*/