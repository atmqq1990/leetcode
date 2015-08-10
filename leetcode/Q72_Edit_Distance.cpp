#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		int **dis = new int*[len1+1];
		for (int i = 0; i <= len1; i++)
			dis[i] = new int[len2+1];
		for (int j = 0; j <= len2; j++)
			dis[0][j] = j;
		for (int i = 0; i <= len1; i++)
			dis[i][0] = i;
		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
				if (word1[i - 1] == word2[j - 1])
					dis[i][j] = dis[i-1][j-1];
				else
				{
					int dd = min(dis[i-1][j-1],dis[i-1][j]);
					dd = min(dd,dis[i][j-1]);
					dis[i][j] = dd + 1;
				}
		int res = dis[len1][len2];
		for (int i = 0; i <= len1; i++)
			delete[] dis[i];
		delete[] dis;
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	int res = so.minDistance("abcde","bcdef");
	cout << res << endl;

	system("pause");
	return 0;

}
*/