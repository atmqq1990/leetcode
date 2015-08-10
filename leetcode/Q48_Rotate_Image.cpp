#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i<n / 2; i++)
			rota(matrix, i, n - 2 * i);
	}

	void rota(vector<vector<int>>& matrix, int layerid, int size)
	{
		int *arr = new int[size];
		for (int i = 0; i<size; i++)
			arr[i] = matrix[layerid][layerid + i];

		for (int i = size - 1; i >= 0; i--)
			matrix[layerid][layerid + i] = matrix[layerid + size - 1 - i][layerid];

		for (int i = 0; i <= size - 1; i++)
			matrix[layerid + i][layerid] = matrix[layerid + size - 1][layerid + i];

		for (int i = 0; i <= size - 1; i++)
			matrix[layerid + size - 1][layerid + i] = matrix[layerid + size - 1 - i][layerid + size - 1];

		for (int i = size - 1; i >= 0; i--)
			matrix[layerid + i][layerid + size - 1] = arr[i];

	}
};

/*
int main()
{
	Solution so;
	vector<vector<int>> vec;
	for (int i = 1; i <= 5; i++)
	{
		vector<int> v;
		for (int j = 1; j <= 5; j++)
			v.push_back(i);
		vec.push_back(v);
	}
	so.rotate(vec);
	for (int i = 0; i<vec.size(); i++)
	{
		for (int j = 0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/