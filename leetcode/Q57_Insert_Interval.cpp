#include<iostream>
#include<vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int size = intervals.size();
		if (size == 0)
		{
			res.push_back(newInterval);
			return res;
		}
		int i = 0;
		while (i < size && intervals[i].end < newInterval.start)
			i++;
		for (int j = 0; j < i; j++)
			res.push_back(intervals[j]);
		if (i == size)
		{
			res.push_back(newInterval);
			return res;
		}

		Interval pre;
		if (newInterval.start > intervals[i].start)
		{
			
			pre = intervals[i];
			if (newInterval.start < pre.start)
				pre.start = newInterval.start;
			if (newInterval.end > pre.end)
				pre.end = newInterval.end;
			i++;
		}
		else
		{
			pre = newInterval;
		}

		while (i < size)
		{
			if (intervals[i].start > pre.end)
			{
				break;
			}
			if (intervals[i].end <= pre.end)
			{
				i++;
				continue;
			}
			pre.end = intervals[i].end;
			i++;
		}

		res.push_back(pre);
		for (int j = i; j < size; j++)
			res.push_back(intervals[j]);
		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<Interval> v;
	Interval a(1, 5);
	
	v.push_back(a);

	Interval f(0,0);
	vector<Interval> res = so.insert(v,f);
	for (int i = 0; i < res.size(); i++)
		cout << "[" << res[i].start << "," << res[i].end << "]" << "  ";
	cout << endl;

	system("pause");
	return 0;
}
*/