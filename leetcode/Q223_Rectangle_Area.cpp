#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A)*(D-B);
		int area2 = (G - E)*(H-F);
		int com = commonarea(A,B,C,D,E,F,G,H);
		return area1 + area2 - com;
	}

	int commonarea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		//check if exists overlap
		if (F >= D || H <= B || E >= C || G <= A)
			return 0;
		if (A < E)
		{
			int width = min(C, G) - E;
			if (B < F)
			{
				int height = min(D, H) - F;
				return width * height;
			}
			else if (B >= F)
			{
				int height = min(D, H) - B;
				return width * height;
			}
		}
		else if (A >= E)
		{
			int width = min(C, G) - A;
			if (B < F)
			{
				int height = min(D, H) - F;
				return width * height;
			}
			else if (B >= F)
			{
				int height = min(D, H) - B;
				return width * height;
			}
		}

	}

};

