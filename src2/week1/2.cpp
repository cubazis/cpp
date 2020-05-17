#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int> v = {-1, 2, 4, 2, -3, 5};
	int n = 2;
	int m = 0; /* case */
	for (size_t i = n; i + m < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (size_t k = v.size(); k > n + m; --k) {
		size_t i = k - m - 1;
		cout << v[i] << " ";
	}

}