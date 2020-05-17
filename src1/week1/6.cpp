#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> vec= {"aaa", "bbb", "ccc"};
	for (auto w: vec) {
		cout << w << endl;
	}
	for (string w: vec) {
		cout << w << endl;
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << endl;
	}
	return 0;
}