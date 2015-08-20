#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {

		if (n == 1)
			return 1;

		int *arr = new int[n+1];
		arr[1] = 1;
		int count = 1;
		int index2 = 1, index3 = 1, index5 = 1;
		while (count < n)
		{
			int minvalue = min(arr[index2]*2,min(arr[index3]*3,arr[index5]*5));
			count++;
			arr[count] = minvalue;
			while (arr[index2] * 2 <= minvalue)
				index2++;
			while (arr[index3] * 3 <= minvalue)
				index3++;
			while (arr[index5] * 5 <= minvalue)
				index5++;
		}

		int res = arr[n];
		delete[] arr;
		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.nthUglyNumber(10);
	cout << res << endl;

	system("pause");
	return 0;
}
*/