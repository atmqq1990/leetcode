#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return triangle[0][0];
		int *minsum = new int[len];
		minsum[0] = triangle[0][0];
		int res = INT_MAX;
		for (int i = 1; i<len; i++)
		{
			minsum[i] = minsum[i - 1] + triangle[i][i];
			if (i == len - 1 && minsum[i] < res)
				res = minsum[i];
			int j = i - 1;
			while (j >= 1)
			{
				minsum[j] = min(minsum[j - 1], minsum[j]) + triangle[i][j];
				if (i == len - 1 && minsum[j] < res)
					res = minsum[j];
				j--;
			}
			minsum[0] = minsum[0] + triangle[i][0];
			if (i == len - 1 && minsum[0] < res)
				res = minsum[0];
		}
		delete[] minsum;
		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(2);
	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	vector<int> v3;
	v3.push_back(6);
	v3.push_back(5);
	v3.push_back(7);
	vector<int> v4;
	v4.push_back(4);
	v4.push_back(1);
	v4.push_back(8);
	v4.push_back(3);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	int res = so.minimumTotal(vec);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/