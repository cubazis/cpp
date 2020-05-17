#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int thr = 3;
	vector<int> v {1, 3, 5, 1, 6, 2};
	cout << count_if(begin(v), end(v), [thr](int x){return x > thr;});
}