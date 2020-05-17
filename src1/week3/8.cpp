#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool compare(const string & a, const string & b){
	if(a < b){
		return true;
	}
	return false;
}

class SortedStrings {
public:
	void AddString(const string& s) {
		strings.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(strings), end(strings), compare);
		return strings;
	}
private:
	vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}