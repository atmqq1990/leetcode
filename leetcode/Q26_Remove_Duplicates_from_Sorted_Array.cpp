#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int len = nums.size();
		int ducount = 0;

		int i = 0;
		while (i < len)
		{
			nums[i - ducount] = nums[i];
			int j = i + 1;
			while (j < len && nums[j] == nums[i])
			{
				ducount++;
				j++;
			}
			i = j;
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
int main(int argc, char ** args)
{
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	int res = so.removeDuplicates(v);
	cout << res << " :";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	
	system("pause");
	return 0;
}
*/