#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows == 0)
			return res;
		vector<int> v;
		v.push_back(1);
		res.push_back(v);
		if (numRows == 1)
			return res;
		for (int i = 1; i<numRows; i++)
		{
			int uplen = res[i - 1].size();
			if (uplen == 1)
			{
				vector<int> vec;
				vec.push_back(1);
				vec.push_back(1);
				res.push_back(vec);
			}
			else
			{
				vector<int> vec;
				vec.push_back(1);
				for (int j = 1; j<res[i - 1].size(); j++)
					vec.push_back(res[i - 1][j] + res[i - 1][j - 1]);
				vec.push_back(1);
				res.push_back(vec);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<vector<int>> res = so.generate(5);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}
*/