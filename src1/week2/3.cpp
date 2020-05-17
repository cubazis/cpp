#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(const vector<string>& v) {
	for (string s : v) {
		cout << s << endl;
	}
}

int main() {
	int n;
	cin >> n;
// Прокрутите код, чтобы увидеть полностью на мобильных устройствах
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
		cout << "Current size = " << v.size() << endl;
	}
	PrintVector(v);

	return 0;
}