#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char> ops;
		int i = 0;
		int len = input.size();
		while (i < len)
		{
			int temp = 0;
			int j = i;
			while (j < len && input[j] >= '0' && input[j] <= '9')
			{
				temp = temp * 10 + input[j] - '0';
				j++;
			}
			nums.push_back(temp);
			if (j < len)
			{
				ops.push_back(input[j]);
				j++;
			}
			i = j;
		}
		
		return compute(nums,0,nums.size()-1,ops);
	}

	vector<int> compute(vector<int>&nums, int numstart, int numend, vector<char>&ops)
	{
		int number = numend - numstart + 1;
		if (number == 1)
		{
			vector<int> res;
			res.push_back(nums[numstart]);
			return res;
		}
		if (number == 2)
		{
			char c = ops[numstart];
			vector<int> res;
			int v = calculation(nums[numstart],nums[numend],c);
			res.push_back(v);
			return res;
		}
		else if (number > 2)
		{
			vector<int> res;
			for (int end = numstart; end < numend; end++)
			{
				vector<int> left = compute(nums,numstart,end,ops);
				vector<int> right = compute(nums,end+1,numend,ops);
				for (int i = 0; i < left.size(); i++)
					for (int j = 0; j < right.size(); j++)
					{
						int v = calculation(left[i],right[j],ops[end]);
						res.push_back(v);
					}
				
			}
			return res;
		}

	}


	int calculation(int a, int b, char c)
	{
		if (c == '+')
			return a + b;
		else if (c == '-')
			return a - b;
		else if (c == '*')
			return a * b;
		else if (c == '/')
			return a / b;
	}


};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> res = so.diffWaysToCompute("2*3-4*5");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/