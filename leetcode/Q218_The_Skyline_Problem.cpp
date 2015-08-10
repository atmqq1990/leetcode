#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> res;
		priority_queue<pair<int, int>> livebuildings;
		int cur = 0, cur_x, cur_h, len = buildings.size();
		while (cur < len || !livebuildings.empty())
		{
			if (livebuildings.empty() || cur < len && buildings[cur][0] <= livebuildings.top().second)
			{
				cur_x = buildings[cur][0];
				while (cur < len && buildings[cur][0] == cur_x)
				{
					livebuildings.push(pair<int, int>(buildings[cur][2], buildings[cur][1]));
					cur++;
				}
			}
			else
			{
				cur_x = livebuildings.top().second;
				while (!livebuildings.empty() && livebuildings.top().second <= cur_x)
					livebuildings.pop();
			}

			cur_h = livebuildings.empty() ? 0 : livebuildings.top().first;

			if (res.empty() || res.back().second != cur_h)
				res.push_back(pair<int, int>(cur_x, cur_h));

		}

		return res;
	}
};