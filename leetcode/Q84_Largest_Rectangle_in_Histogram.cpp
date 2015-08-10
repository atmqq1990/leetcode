#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
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
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);
	v.push_back(3);
	int res = so.largestRectangleArea(v);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/