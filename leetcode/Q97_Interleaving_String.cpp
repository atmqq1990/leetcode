#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool matched;
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if (len1 + len2 != len3)
			return false;
		if (len3 == 0)
			return true;
		matched = false;
		match(s1, 0, s2, 0, s3, 0);

		return matched;
	}

	void match(string &s1, int pos1, string &s2, int pos2, string &s3, int pos3)
	{
		if (matched)
			return;
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if (pos1 == len1 && pos2 == len2)
		{
			matched = true;
			return;
		}
		if (pos1 == len1)
		{
			int j = pos2;
			int k = pos3;
			while (j<len2 && s2[j] == s3[k])
			{
				j++;
				k++;
			}
			if (j == len2)
			{
				matched = true;
				return;
			}
			return;
		}
		if (pos2 == len2)
		{
			int i = pos1;
			int k = pos3;
			while (i<len1 && s1[i] == s3[k])
			{
				i++;
				k++;
			}
			if (i == len1)
			{
				matched = true;
				return;
			}
			return;
		}
		if (s1[pos1] != s3[pos3] && s2[pos2] != s3[pos3])
		{
			return;
		}
		else if (s1[pos1] == s3[pos3] && s2[pos2] != s3[pos3])
		{
			match(s1, pos1 + 1, s2, pos2, s3, pos3 + 1);
		}
		else if (s1[pos1] != s3[pos3] && s2[pos2] == s3[pos3])
		{
			match(s1, pos1, s2, pos2 + 1, s3, pos3 + 1);
		}
		else if (s1[pos1] == s3[pos3] && s2[pos2] == s3[pos3])
		{
			int count1 = 1;
			int ind1 = pos1 + 1;
			while (ind1 <len1 && s1[ind1] == s1[pos1])
			{
				ind1++;
				count1++;
			}

			int count2 = 1;
			int ind2 = pos2 + 1;
			while (ind2 < len2 && s2[ind2] == s2[pos2])
			{
				ind2++;
				count2++;
			}

			int count3 = 1;
			int ind3 = pos3 + 1;
			while (ind3 < len3 && s3[ind3] == s3[pos3])
			{
				ind3++;
				count3++;
			}

			if (count3 < min(count1, count2))
				return;

			if (count3 > count1 + count2)
				return;
			if (count3 == count1 + count2)
			{
				match(s1, pos1 + count1, s2, pos2 + count2, s3, pos3 + count3);
				return;
			}
			else
			{
				int maxcount = min(count3, count1);
				for (int i = 0; i <= maxcount; i++)
				{
					match(s1, pos1 + i, s2, pos2 + count3 - i, s3, pos3 + count3);
					if (matched)
						return;
				}
			}
		}
	}
};

/*
int main()
{
	Solution so;
	bool res = so.isInterleave("aabcc","dbbca","aadbbbaccc");
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/