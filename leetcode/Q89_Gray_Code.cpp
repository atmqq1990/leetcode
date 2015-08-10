#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		if (n == 0)
			return res;
		res.push_back(1);
		if (n == 1)
			return res;
		int power[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4196};
		int yu = 1;
		for (int mi = 2; mi <= n; mi++)
		{
			yu = yu << 1;
			int base = power[mi-1];
			for (int j = base; j <= 2 * base - 1; j++)
			{
				int temp = res[2 * base - 1 - j] | yu;
				res.push_back(temp);
			}
		}
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> res = so.grayCode(4);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/