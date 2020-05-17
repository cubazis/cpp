#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include
using namespace std;

bool smallest(std::string const & lhs, std::string const & rhs) {
	if (lhs < rhs)
		return true;
	return false;
}

int main() {
	string a;
	string b;
	string c;
	cin >> a >> b >> c;
	vector<string> vec = {a, b, c};
	cout << *min_element(begin(vec), end(vec), smallest) << "\n";
}