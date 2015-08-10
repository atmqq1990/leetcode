#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		
		int len = gas.size();
		int firststart = 0;
		while (firststart < len && gas[firststart] < cost[firststart])
			firststart++;
		if (firststart == len)
			return -1;
		bool *visited = new bool[len];
		for (int i = 0; i < len; i++)
			visited[i] = false;
		int i = firststart;
		int j = i;
	//	visited[i] = true;
		int tank = 0;
		while (true)
		{
			while (tank >= 0)
			{
				tank += gas[j] - cost[j];
				visited[j] = true;
				j = (j+1)%len;
				if (tank>=0 && j == i)
					return i;
			}
			tank = 0;
			i = j;
			if (visited[i])
				break;
		}

		return -1;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	vector<int> gas = { 1,2,3,3 };
	vector<int> cost = {2,1,5,1};
	int res = so.canCompleteCircuit(gas,cost);
	cout << res << endl;

	system("pause");
	return 0;
}
*/