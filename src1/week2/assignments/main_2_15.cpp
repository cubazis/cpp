#include <iostream>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void PrintSet(const set<string>& s) {
	cout << "Size = " << s.size() << endl;
	for (auto x : s) {
		cout << x << endl;
	}
}

void PrintSet(const set<int>& s) {
	cout << "Size = " << s.size() << endl;
	for (auto x : s) {
		cout << x << endl;
	}
}

int main () {
	int N;
	cin >> N;
	set<string> s;
	string ss;
	for (int i = 0; i < N; ++i) {
		cin >> ss;
		s.insert(ss);
	}
	cout << s.size();
	return 0;
}
