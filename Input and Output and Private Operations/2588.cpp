// https://www.acmicpc.net/problem/2588

#include <iostream>

using namespace std;

int main() {
	int a, b;
	int c, d, e;
	cin >> a >> b;
	c = a * (b % 10);
	b /= 10;
	d = a * (b % 10);
	b /= 10;
	e = a * (b % 10);

	cout << c << "\n" << d << "\n" << e << endl;
	cout << c + (10 * d) + (e * 100);
}