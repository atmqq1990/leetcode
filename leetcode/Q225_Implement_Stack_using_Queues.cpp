#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		topvalue = x;
		if (major == 0)
			qu1.push(x);
		else
			qu2.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (major == 0)
		{
			while (qu1.size() > 2)
			{
				qu2.push(qu1.front());
				qu1.pop();
			}
			if (qu1.size()  == 2)
			{
				topvalue = qu1.front();
				qu2.push(qu1.front());
				qu1.pop();
			}
			qu1.pop();
		}
		else if (major == 1)
		{
			while (qu2.size() > 2)
			{
				qu1.push(qu2.front());
				qu2.pop();
			}
			if (qu2.size() == 2)
			{
				topvalue = qu2.front();
				qu1.push(qu2.front());
				qu2.pop();
			}
			qu2.pop();
		}
		major = 1 - major;
	}

	// Get the top element.
	int top() {
		return topvalue;
	}

	// Return whether the stack is empty.
	bool empty() {
		return qu1.empty() && qu2.empty();
	}
private:
	queue<int> qu1;
	queue<int> qu2;
	int topvalue;
	int major = 0;
};

/*
int main(int argc, char**args)
{
	Stack st;
	st.push(1);
	st.pop();
	bool res = st.empty();
	cout << res << endl;

	system("pause");
	return 0;
}
*/