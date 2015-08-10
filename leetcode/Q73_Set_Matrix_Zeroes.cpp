#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool firstrow = false;
		bool firstcol = false;
		int m = matrix.size();
		if (m == 0)
			return;
		int n = matrix[0].size();
		for (int j = 0; j < n;j++)
			if (matrix[0][j] == 0)
			{
				firstrow = true;
				break;
			}
		for (int i = 0; i < m;i++)
			if (matrix[i][0] == 0)
			{
				firstcol = true;
				break;
			}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n;j++)
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
		for (int i = 1; i < m;i++)
			if (matrix[i][0] == 0)
			{
				for (int j = 1; j < n; j++)
					matrix[i][j] = 0;
			}
		for (int j = 1; j < n;j++)
			if (matrix[0][j] == 0)
			{
				for (int i = 1; i < m; i++)
					matrix[i][j] = 0;
			}
		if (firstrow)
		{
			for (int j = 0; j < n; j++)
				matrix[0][j] = 0;
		}
		if (firstcol)
		{
			for (int i = 0; i < m; i++)
				matrix[i][0] = 0;
		}

	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(0);
	v2.push_back(6);
	vector<int> v3;
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	so.setZeroes(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/