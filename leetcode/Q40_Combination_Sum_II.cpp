#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		sort(candidates.begin(), candidates.end());
		vector<int> pre;
		recurive(candidates, pre, 0, target);

		return res;
	}

	void recurive(vector<int> &candidates, vector<int> &pre, int index, int target)
	{
		if (target == 0)
		{
			res.push_back(pre);
			return;
		}

		for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
		{
			if (i > index && candidates[i] == candidates[i - 1])
				continue;

			pre.push_back(candidates[i]);
			recurive(candidates, pre, i+1, target - candidates[i]);
			pre.pop_back();
		}
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);

	vector<vector<int>> res = so.combinationSum2(v, 8);
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