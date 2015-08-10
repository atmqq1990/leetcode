#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		if (rowIndex == 0 || rowIndex == 1)
		{
			for (int i = 0; i <= rowIndex; i++)
				res.push_back(1);
			return res;
		}
		int *arr = new int[rowIndex + 1];
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i <= rowIndex; i++)
		{
			int j = i;
			arr[j] = 1;
			j--;
			while (j >= 1)
			{
				arr[j] = arr[j] + arr[j - 1];
				j--;
			}
		}
		for (int i = 0; i <= rowIndex; i++)
			res.push_back(arr[i]);
		delete[] arr;
		return res;
	}
};

/*
int main()
{
	Solution so;
	vector<int> res = so.getRow(3);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
*/