#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {
public:
	stack<int> st;
	stack<int> minst;
	void push(int x) {
		if (st.empty())
		{
			st.push(x);
			minst.push(x);
		}
		else
		{
			st.push(x);
			minst.push(min(x, minst.top()));
		}
	}

	void pop() {
		if (!st.empty())
		{
			st.pop();
			minst.pop();
		}
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return minst.top();
	}
};