#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int len1 = version1.size();
		int len2 = version2.size();

		int start1 = 0, start2 = 0;
		int end1, end2;

		while (start1 < len1 && start2 < len2)
		{
			while (start1 < len1 && version1[start1] == '0')
				start1++;
			while (start2 < len2 && version2[start2] == '0')
				start2++;
			end1 = start1;
			end2 = start2;
			while (end1 < len1 && version1[end1] != '.')
				end1++;
			while (end2 < len2 && version2[end2] != '.')
				end2++;
			if (end1 == len1 || version1[end1]=='.')
				end1--;
			if (end2 == len2 || version2[end2]=='.')
				end2--;
			int comp = comparedigits(version1,start1,end1,version2,start2,end2);
			if (comp != 0)
				return comp;
			if (end1 < len1 - 1 && version1[end1 + 1] == '.')
				end1++;
			if (end2 < len2 - 1 && version2[end2 + 1] == '.')
				end2++;
			start1 = end1 + 1;
			start2 = end2 + 1;

		}
		if (start1 == len1 && start2 == len2)
			return 0;
		else if (start1 == len1 && start2 != len2)
		{
			for (int i = start2; i < len2; i++)
				if (version2[i]>'0' && version2[i] <= '9')
					return -1;
			return 0;
		}
		else if (start1 != len1 && start2 == len2)
		{
			for (int i = start1; i < len1; i++)
				if (version1[i]>'0' && version1[i] <= '9')
					return 1;
			return 0;
		}
	}

	int comparedigits(string&s1, int start1, int end1, string&s2, int start2, int end2)
	{
		int len1 = end1 - start1 + 1;
		int len2 = end2 - start2 + 1;
		if (len1 < len2)
			return -1;
		else if (len1 > len2)
			return 1;
		int i = start1, j = start2;
		while (i <= end1)
		{
			if (s1[i] < s2[j])
				return -1;
			else if (s1[i] > s2[j])
				return 1;
			i++;
			j++;
		}
		return 0;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.compareVersion("1.0","1");
	cout << res << endl;

	system("pause");
	return 0;
}
*/