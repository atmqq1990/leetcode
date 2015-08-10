#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {

		int maxare = 0;
		int len = height.size();
		int i = 0, j = len - 1;
		int temp;
		while (i < j)
		{
			temp = min(height[i],height[j])*(j-i);
			if (temp > maxare)
				maxare = temp;
			if (height[i] >= height[j])
				j--;
			else
				i++;
			
		}
		return maxare;
	}
};

/*
int main(int argc, char **args)
{
	Solution  so;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	int res = so.maxArea(v);
	cout << res << endl;
	system("pause");
	return 0;
}
*/