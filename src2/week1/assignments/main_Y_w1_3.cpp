#include <iostream>
using namespace std;

/*
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  uint64_t answer = 0;
  for (int i = 0; i < N; ++i) {
    int W, H, D;
    cin >> W >> H >> D;
    // Если не привести W к типу uint64_t перед умножением,
    // произведение будет иметь тип int и случится переполнение.
    // Альтернативное решение — хранить сами W, H, D в uint64_t
    answer += static_cast<uint64_t>(W) * H * D;
  }
  answer *= R;
  cout << answer << endl;
  return 0;
}

 */

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