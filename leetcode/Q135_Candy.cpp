#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		if (len <= 1)
			return len;
		vector<int> can(len,1);
		vector<int> minmum;
		for (int i = 0; i < len; i++)
		{
			if (i == 0 && ratings[i] < ratings[i + 1])
				minmum.push_back(i);
			else if (i == len - 1 && ratings[i] < ratings[i - 1])
				minmum.push_back(i);
			else if (ratings[i] <= ratings[i - 1] && ratings[i] < ratings[i + 1]
				|| ratings[i] < ratings[i - 1] && ratings[i] <= ratings[i + 1])
				minmum.push_back(i);

		}

		for (int i = 0; i < minmum.size(); i++)
		{
			int index = minmum[i];
			int left = index - 1;
			while (left >= 0 && ratings[left] > ratings[left + 1] && can[left] < can[left + 1] + 1)
			{
				can[left] = can[left + 1] + 1;
				left--;
			}
			int right = index + 1;
			while (right < len && ratings[right] > ratings[right - 1] && can[right] < can[right - 1] + 1)
			{
				can[right] = can[right - 1] + 1;
				right++;
			}
		}

		int res = 0;
		for (int i = 0; i < len; i++)
			res += can[i];

		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> v = {1,2,3,2,1,2,3,2,1,3};
	int res = so.candy(v);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/