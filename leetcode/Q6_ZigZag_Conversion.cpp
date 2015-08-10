#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {

		string *rows = new string[numRows];
		int flag = 1;   //1 down , 0 right upside

		int len = s.size();
		int i = 0;
		while (i < len)
		{
			if (flag == 1)
			{
				int j = 0;
				while (j < numRows && i < len)
				{
					rows[j].push_back(s[i]);
					j++;
					i++;
				}
				if (i == len)
					break;
			}
			else
			{
				int j = numRows - 2;
				while (j > 0 && i<len)
				{
					rows[j].push_back(s[i]);
					i++;
					j--;
				}
				if (i == len)
					break;
			}

			flag = 1 - flag;
		}

		string res;
		for (int i = 0; i < numRows; i++)
			res.append(rows[i]);

		delete[] rows;
		return res;
	}


};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.convert("PAYPALISHIRING",3);
	cout << res << endl;

	system("pause");
	return 0;
}
*/