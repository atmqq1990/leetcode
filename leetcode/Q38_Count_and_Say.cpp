#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string res = "1";
		string temp = res;
		for (int i = 1; i < n; i++)
		{
			temp = res;
			res.clear();
			
			int j = 0;
			while (j < temp.size())
			{
				int count = 1;
				int k = j+1;
				while (k < temp.size() && temp[k] == temp[j])
				{
					k++;
					count++;
				}
				res.push_back(count+'0');
				res.push_back(temp[j]);
				j = k;
			}

		}

		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	
	cout << so.countAndSay(20) << endl;

	system("pause");
	return 0;
}
*/