#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print(const vector<int> & v){
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	int N;
	cin >> N;
	vector<int> v;
	int x;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(begin(v), end(v), [](int i, int j){return (abs(i) < abs(j));});
	print(v);
}