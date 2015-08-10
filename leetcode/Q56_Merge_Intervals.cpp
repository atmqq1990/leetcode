#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:

	static bool cmp( Interval a,  Interval b)
	{
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(),intervals.end(),cmp);
		int size = intervals.size();
		vector<Interval> res;
		if (size == 0)
			return res;
		if (size == 1)
			return intervals;
		Interval pre = intervals[0];
		for (int i = 1; i < size; i++)
		{
			if (intervals[i].end <= pre.end)
				continue;
			if (intervals[i].start > pre.end)
			{
				res.push_back(pre);
				pre = intervals[i];
				continue;
			}
			pre.end = intervals[i].end;
		}
		res.push_back(pre);
		return res;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<Interval> v;
	Interval a(1,3);
	Interval b(2,6);
	Interval c(8,10);
	Interval d(15,18);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	vector<Interval> res = so.merge(v);
	for (int i = 0; i < res.size(); i++)
		cout << "[" << res[i].start << "," << res[i].end << "]" << "  ";
	cout << endl;

	system("pause");
	return 0;
}
*/