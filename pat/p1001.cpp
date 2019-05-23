#include<iostream>
#inlcude<string>
using namespace std;
/**
	1001 A+B Format (20)
	Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

	Input Specification:
	Each input file contains one test case. Each case contains a pair of integers a and b where −10
	​6
	​​ ≤a,b≤10
	​6
	​​ . The numbers are separated by a space.

	Output Specification:
	For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

	Sample Input:
	-1000000 9
	Sample Output:
	-999,991
*/

void p1001(int a, int b) {
	bool isN = false;
	string str;
	int c = a + b;
	if (c >= 0) {
		str = to_string(c);
	}
	else {
		str = to_string(-c);
		isN = true;
	}
	int size = str.length();
	if (size >= 4) {
		for (int i = size - 3; i > 0; i=i-3) {
			str.insert(i, ",");
		}
	}
	if (isN) {
		str = '-' + str;
	}
	cout << str << endl;
}

