#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> original = {"Vector", "of", "strings"};
	vector<string> another = original;
	vector<string> empty;
	original = empty;
	for (int i = 0; i < another.size(); ++i) {
		cout << another[i];
	}
	return 0;
}