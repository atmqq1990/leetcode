#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		//firstly need to find the rowid
		if (target < matrix[0][0])
			return false;
		if (target == matrix[0][0])
			return true;
		if (target > matrix[m - 1][n - 1])
			return false;
		if (target == matrix[m - 1][n - 1])
			return true;
		int lowrow = 0;
		int highrow = m - 1;
		int rowid = -1;
		int midrow;
		while (lowrow < highrow)
		{
			midrow = (lowrow + highrow) / 2;
			if (matrix[midrow][0] < target )
			{
				if (matrix[midrow + 1][0] > target)
				{
					rowid = midrow;
					break;
				}
				else if (matrix[midrow + 1][0] == target)
				{
					return true;
				}
				else if (matrix[midrow + 1][0] < target)
				{
					lowrow = midrow + 1;
				}
			}
			else if (matrix[midrow][0] == target)
				return true;
			else if (matrix[midrow][0] > target)
			{
				highrow = midrow;
			}
		}
		if (rowid == -1)
			rowid = lowrow;

		if (matrix[rowid][n - 1] < target)
			return false;

		int lowcol = 0;
		int highcol = n - 1;
		int midcol;
		while (lowcol <= highcol)
		{
			midcol = (lowcol + highcol) / 2;
			if (matrix[rowid][midcol] == target)
				return true;
			else if (matrix[rowid][midcol] > target)
				highcol = midcol - 1;
			else if (matrix[rowid][midcol] < target)
				lowcol = midcol + 1;

		}

		return false;
	}
};


/*
int main(int argc, char **args)
{
	Solution so;
	vector<vector<int>> vec;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(16);
	v2.push_back(20);
	vector<int> v3;
	v3.push_back(23);
	v3.push_back(30);
	v3.push_back(34);
	v3.push_back(50);
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	bool res = so.searchMatrix(vec,12);
	cout << res << endl;

	system("pause");
	return 0;
}
*/