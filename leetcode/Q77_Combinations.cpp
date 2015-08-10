#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combine(int n, int k) {
		vector<int> pre;
		com(pre,n,k,1);
		return res;

	}

	void com(vector<int>& pre,int n, int k, int pos)
	{
		if (pre.size() == k)
		{
			res.push_back(pre);
			return;
		}
		if (pre.size() > k)
			return;

		if (pos <= n)
		{
			pre.push_back(pos);
			com(pre,n,k,pos+1);
			pre.pop_back();
			com(pre,n,k,pos+1);
		}
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> res = so.combine(4,2);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/