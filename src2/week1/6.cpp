#include <iostream>
using namespace std;

int main() {
	uint32_t N;
	uint16_t x, y, z;
	uint16_t R;
	cin >> N >> R;
	unsigned long M = 0;
	for (uint32_t i = 0; i < N; ++i) {
		cin >> x >> y >> z;
		unsigned long e = 1;
		e *= x;
		e *= y;
		e *= z;
		e *= R;
		M += e;
	}
	cout << M << endl;
}