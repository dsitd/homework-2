#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;


void sinDerrivate(int n, float x) {

	cout << sin(x + M_PI * n / 2) << endl;
}
int addByteN(int n, int x) {
	x |= (1 << n);
	cout << x << endl;
	return x;
}
int killByteN(int n, int x) {
	x &= ~(1 << n);
	cout << x << endl;
	return x;
}
int oddEven(int x) {
	cout << (x & 1) << endl;
	return x & 1;
}
void revers(int a, int b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
int multiplyByEight(int a) {
	return a << 3;
}
vector<double> crazyTrain(double t, double v) {
	vector<double> res(3, 0);
	res[0] = v * t;
	res[1] = res[0] / 2;
	res[2] = res[0] + res[1];
	return res;
}
int add(int a, int b) {
	int c = 0;
	int res = 0;
	res = a ^ b;
	c = (a & b) << 1;
	while (c) {
		int s = res;
		res = res ^ c;
		c = (s & c) << 1;
		
	}
	return res;
}
double multuplicate(double a, double b) {
	double c = 0;
	for (int i = 0; i < b; i = add(i, 1)) {
		c = add(c, a);
	}
	return c;
}
double degrees(double a, double b) {
	bool sign = b >= 0;
	b = abs(b);
	double c = 1;
	cout << sign << endl;
	for (int i = 0; i < b; i = add(i, 1)) {
		c = sign != 0 ? multuplicate(c, a) : b == 0 ? 0 : c / a;
	}
	return c;
}
double calc(int a, int b, char op) {
	switch (op)
	{
	case '+': return add(a, b);
	case '-': return add(a, -b);
	case '*': return multuplicate(a, b);
	case '/': return b == 0?0:a / b;
	case '%': return a % b;
	case '^': return degrees(a, b);
	default:
		break;
	}
}
int main() {
	vector<double> result(3, 0);
	cout << calc(3, 3, '+') << endl;
	cout << calc(3, 3, '-') << endl;
	cout << calc(3, 3, '*') << endl;
	cout << calc(3, 3, '/') << endl;
	cout << calc(3, 3, '%') << endl;
	cout << calc(3, 3, '^') << endl;
	cout << calc(3, -3, '^') << endl;
}