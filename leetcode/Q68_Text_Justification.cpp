#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int len = words.size();
		int i = 0;
		string temp;
		int currentcount = 0;
		
		while (i < len )
		{
			while (i < len && temp.size() + currentcount +  words[i].size() <= maxWidth)
			{
				temp.append(words[i]);
				i++;
				currentcount++;
			}

			if (i == len)
			{
				string str;
				int startindex = i - currentcount;
				str.append(words[startindex]);
				for (int j = startindex + 1; j < i; j++)
				{
					str.push_back(' ');
					str.append(words[j]);
				}
				while (str.size() < maxWidth)
					str.push_back(' ');
				res.push_back(str);
				currentcount = 0;
			}
			else
			{
				if (temp.size() == maxWidth) // no extra spaces needed
				{
					res.push_back(temp);
					currentcount = 0;
					temp.clear();
				}
				else
				{
					if (currentcount == 1)
					{
						while (temp.size() < maxWidth)
							temp.push_back(' ');
						res.push_back(temp);
						temp.clear();
						currentcount = 0;
					}
					else
					{
						int totalspaces = maxWidth - temp.size();
						int base = totalspaces / (currentcount-1);
						int duo = totalspaces % (currentcount-1);
						int startindex = i - currentcount ;
						if (duo == 0) // spaces between words are the same
						{
							string str;
							str.append(words[startindex]);
							for (int j = startindex + 1; j < i; j++)
							{
								for (int k = 0; k < base; k++)
									str.push_back(' ');
								str.append(words[j]);
							}
							res.push_back(str);
						}
						else
						{
							string str;
							str.append(words[startindex]);
							for (int j = startindex + 1; j < i; j++)
							{
								for (int k = 0; k < base; k++)
									str.push_back(' ');
								if (j <= startindex + duo)
									str.push_back(' ');
								str.append(words[j]);
							}
							res.push_back(str);
						}
						currentcount = 0;
						temp.clear();
					}
				}

			}

		}

		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<string> v;
	string str[] = { "What","must","be","shall","be."};
	for (int i = 0; i < 5; i++)
		v.push_back(str[i]);
	vector<string> res = so.fullJustify(v,12);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	system("pause");
	return 0;
}
*/