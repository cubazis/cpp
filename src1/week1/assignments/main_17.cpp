#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
25 27 1
12 16 4
13 13 13
 */

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main() {
	int A, B;
	cin >> A >> B;
	cout << gcd(A, B) << endl;
	return 0;
}