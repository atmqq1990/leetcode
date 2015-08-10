#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		vector<int> height(n, 0);
		vector<int> maxarea(m, 0);
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
				if (matrix[i][j] == '0')
					height[j] = 0;
				else
					height[j]++;
			maxarea[i] = largestRectangleArea(height);
		}

		int res = 0;
		for (int i = 0; i<m; i++)
			if (maxarea[i] > res)
				res = maxarea[i];
		return res;
	}

	int largestRectangleArea(vector<int>& height) {
		stack<int> st;
		int i = 0;
		int len = height.size();
		int maxarea = 0;
		while (i < len)
		{
			if (st.empty() || height[i] >= height[st.top()])
			{
				st.push(i);
				i++;
			}
			else
			{
				int index = st.top();
				st.pop();
				int temp_area;
				int width;
				if (st.empty())
					width = i;
				else
					width = i - st.top() - 1;
				temp_area = height[index] * width;
				if (temp_area > maxarea)
					maxarea = temp_area;
			}
		}

		while (!st.empty())
		{
			int index = st.top();
			st.pop();
			int temp_area;
			int width;
			if (st.empty())
				width = i;
			else
				width = i - st.top() - 1;
			temp_area = height[index] * width;
			if (temp_area > maxarea)
				maxarea = temp_area;
		}
		return maxarea;
	}

};

/*
int main()
{
	Solution so;
	vector<vector<char>> vec;
	vector<char> v1;
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('0');
	vector<char> v2;
	v2.push_back('0');
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('0');
	vector<char> v3;
	v3.push_back('0');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('0');
	vector<char> v4;
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('0');
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	int res = so.maximalRectangle(vec);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/