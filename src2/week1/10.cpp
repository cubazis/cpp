#include <iostream>
#include <tuple>
#include <utility>
#include <map>
using namespace std;

int main() {
	tuple t(7, "text", true);
	cout << get<1>(t) << endl;
	pair<int, string> p = {1, "test"};
	cout << p.first << " " << p.second << endl;
	map<int,string> m = {{1, "one"}, {2, "two"}};
	for (const pair<int, string>  & item: m) {
		cout << item.first << " " << item.second << endl;
	}
}