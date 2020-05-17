#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool compare(const string & a, const string & b){
	if(a < b){
		return true;
	}
	return false;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {

	}
	void ChangeLastName(int year, const string& last_name) {

	}
	string GetFullName(int year) {
		if(history.empty()){
			return "Incognito";
		}
		if(history.count(year) == 1){
			return history[year].first + " " + history[year].second;
		} else{
			map<int, pair<string, string>>::iterator close_low;
			close_low = history.lower_bound(year);
			return history[close_low].first + " " + close_low.second;
		}
	}
private:
	map<int, pair<string, string>> history;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}