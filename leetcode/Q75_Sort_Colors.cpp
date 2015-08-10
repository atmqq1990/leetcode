#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int count[3] = { 0,0,0 };
		for (int i = 0; i<len; i++)
			count[nums[i]]++;
		int i = 0;
		for (int k = 0; k<3; k++)
			for (int j = 0; j<count[k]; j++)
			{
				nums[i] = k;
				i++;
			}
	}
};

/*
int main()
{
Solution so;
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(0);
v.push_back(1);
v.push_back(2);
v.push_back(0);
v.push_back(1);
v.push_back(2);
v.push_back(0);
so.sortColors(v);
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<endl;

system("pause");
return 0;
}
*/