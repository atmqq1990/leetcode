#include<iostream>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1)
			return 1;
		int *arr = new int[n+1];
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			arr[i] = 0;
			for (int j = 0; j < i; j++)
				arr[i] += arr[j] * arr[i - 1 - j];
		}
		int res = arr[n];
		delete[] arr;
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.numTrees(19);
	cout << res << endl;

	system("pause");
	return 0;
}
*/