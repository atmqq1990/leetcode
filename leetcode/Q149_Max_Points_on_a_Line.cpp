#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int len = points.size();
		if (len <= 2)
			return len;
		map<pair<int, int>, int> linemap;
		int maxcount = 0;
		int overlap = 0;
		for (int i = 0; i < len - 1; i++)
		{
	//		if (len - i < maxcount)
		//		break;
			linemap.clear();
			int localmax = 0;
			overlap = 0;
			for (int j = i + 1; j < len; j++)
			{
				
				int a = points[j].x - points[i].x;
				int b = points[j].y - points[i].y;
				if (a == 0 && b == 0)
				{
					overlap++;
				}
				else if (a == 0 && b != 0)
				{
					pair<int, int> temp(0,1);
					linemap[temp]++;
					localmax = max(localmax, linemap[temp]);
				}
				else if (a != 0 && b == 0)
				{
					pair<int, int> temp(1,0);
					linemap[temp]++;
					localmax = max(localmax, linemap[temp]);
				}
				else if (a != 0 && b != 0)
				{
					int g = GCD(a,b);
					a = a / g;
					b = b / g;
					if (a < 0)
					{
						a = a * (-1);
						b = b * (-1);
					}
					pair<int, int> temp(a,b);
					linemap[temp]++;
					localmax = max(localmax, linemap[temp]);
				}

			}
			maxcount = max(maxcount,localmax+overlap+1);
		}

		return maxcount;
	}

	int GCD(int a, int b)
	{
		while (b != 0)
		{
			int temp = a%b;
			a = b;
			b = temp;
		}
		return a;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	Point p1(0,0);
	Point p2(1,1);
	Point p3(0,0);
	vector<Point> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	int res = so.maxPoints(vec);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/