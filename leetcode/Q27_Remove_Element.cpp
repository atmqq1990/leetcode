#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {

		int len = nums.size();
		int i = 0;
		int ducount = 0;

		while (i < len)
		{
			if (nums[i] != val)
				nums[i - ducount] = nums[i];
			else
				ducount++;
			i++;
		}

		while (ducount > 0)
		{
			nums.pop_back();
			ducount--;
		}

		return nums.size();
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);
	v.push_back(6);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);

	int res = so.removeElement(v,3);
	cout << res << " :";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	system("pause");
	return 0;

}
*/