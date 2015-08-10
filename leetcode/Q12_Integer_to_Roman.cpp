#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

	string intToRoman(int num) {

		string thousand[10] = {"","M","MM","MMM",""};
		string hundred[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
		string ten[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
		string digit[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

		string res;
		res.append(thousand[num/1000]);
		num = num % 1000;
		res.append(hundred[num/100]);
		num = num % 100;
		res.append(ten[num/10]);
		num = num % 10;
		res.append(digit[num]);

		return res;
	}

};

/*
int main(int argc, char **args)
{
	Solution so;
	string res = so.intToRoman(3999);
	cout << res << endl;
	
	system("pause");
	return 0;
	
}
*/