#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {

		if (height.size() <= 2)
			return false;

		vector<int> peakindex;

		for (int i = 0; i<height.size(); i++)
		{
			if (i == 0)
			{
				if (height[i] > height[i + 1])
					peakindex.push_back(i);
			}
			else if (i == height.size() - 1)
			{
				if (height[i] > height[i - 1])
					peakindex.push_back(i);
			}
			else
			{
				if (height[i] >= height[i - 1] && height[i] > height[i + 1]
					|| height[i] > height[i - 1] && height[i] >= height[i - 1])
				{
					peakindex.push_back(i);

				}
			}
		}

		if (peakindex.size() <= 1)
			return 0;

		return recursive(height, peakindex, 0, peakindex.size() - 1);

	}

	int find_index(vector<int> &height, vector<int>&peakindex, int pstart, int pend)
	{
		int maxh = height[peakindex[pstart]];
		int res = pstart;
		for (int pp = pstart + 1; pp <= pend; pp++)
			if (height[peakindex[pp]] > maxh)
			{
				maxh = height[peakindex[pp]];
				res = pp;
			}
		return res;
	}

	int recursive(vector<int>&height, vector<int>&peakindex, int pstart, int pend)
	{
		if (pend == pstart)
			return 0;

		if (pend - pstart == 1)
			return area(height, peakindex[pstart], peakindex[pend]);

		int max_peak_index = find_index(height, peakindex, pstart, pend);
		int resarea = 0;

		if (max_peak_index != pstart)
		{
			int left_peak_index = find_index(height, peakindex, pstart, max_peak_index - 1);
			resarea += area(height, peakindex[left_peak_index], peakindex[max_peak_index]);
			resarea += recursive(height, peakindex, pstart, left_peak_index);
		}

		if (max_peak_index != pend)
		{
			int right_peak_index = find_index(height, peakindex, max_peak_index + 1, pend);
			resarea += area(height, peakindex[max_peak_index], peakindex[right_peak_index]);
			resarea += recursive(height, peakindex, right_peak_index, pend);

		}

		return resarea;
	}


	int area(vector<int>& height, int start, int end)
	{
		if (end - start < 1)
			return 0;

		int h = min(height[start], height[end]);
		int res = 0;
		for (int j = start + 1; j<end; j++)
		{
			if (height[j] < h)
				res += h - height[j];
		}
		return res;
	}
};

/*
int main()
{
	Solution so;
	int arr[] = { 5,4,1,2 };
	vector<int> v;
	for (int i = 0; i<4; i++)
		v.push_back(arr[i]);
	int res = so.trap(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/