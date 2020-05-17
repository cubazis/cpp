#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Person {
	string name;
	string surname;
	int age;
};

int main() {
//	vector<string> strings = {"one", "two", "three"};
//	cout << strings.size();
//	map<string, int> name_to_val;
//	name_to_val["one"] = 1;
//	name_to_val["two"] = 2;
//	cout << name_to_val["two"];
	vector<Person> staff;
	staff.push_back({"Ivan", "Ivanov", 25});
	cout << staff[0].name;
	return 0;
}