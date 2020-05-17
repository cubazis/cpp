#include <iostream>
#include <map>
#include <set>
using namespace std;

int main () {
	int N;
	cin >> N;
	map<string, set<string>> m;
	string one, two;
	for (int i = 0; i < N; ++i) {
		cin >> one;
		if (one == "ADD") {
			cin >> one >> two;
			m[one].insert(two);
			m[two].insert(one);
		}
		if (one == "COUNT") {
			cin >> one;
			cout << m[one].size() << endl;
		}
		if (one == "CHECK") {
			cin >> one >> two;
			if(m[one].count(two) == 1 || m[two].count(one) == 1){
				cout << "YES" << endl;
			}else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}

