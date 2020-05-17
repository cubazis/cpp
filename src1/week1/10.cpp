#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int c = 1;
	++c;
	c *= 5;
	c -= 3;
	cout << c++;
	return 0;
}