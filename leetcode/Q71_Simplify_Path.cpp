#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vec;
		int len = path.size();
		int i = 0;
		string current;
		while (i < len)
		{
			while (i < len && path[i] == '/')
				i++;
			if (i == len)
				break;
			while (i < len && path[i] != '/')
			{
				current.push_back(path[i]);
				i++;
			}
			if (current == "..")
			{
				current.clear();
				if(vec.size() > 0)
					vec.pop_back();
			}
			else if (current == ".")
			{
				current.clear();
			}
			else if(current.size() > 0)
			{
				vec.push_back(current);
				current.clear();
			}

		}

		string res;
		for (int i = 0; i < vec.size(); i++)
		{
			res.push_back('/');
			res.append(vec[i]);
		}
		if (res.size() == 0)
			res.push_back('/');
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.simplifyPath("/home//foo/");
	cout << res << endl;

	system("pause");
	return 0;
}
*/